/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <string.h>
#include <stddef.h>
#include "_memfs.hpp"

namespace wombat {
namespace core {

uint32_t MemFs::version = 0;

MemFsPtr MemFs::Record::pathLen() {
	return offsetof(MemFs::Record, m_path) + m_data;
}

MemFsPtr MemFs::Record::size() {
	return offsetof(MemFs::Record, m_path) + pathLen() + dataLen;
}

void MemFs::Record::setPath(std::string path) {
	char *ptr = (char*) (this + m_path);
	for (uint i = 0; i < path.size(); i++) {
		*(ptr + i) = path[i];
	}
}

void MemFs::Record::setData(uint8_t *data, int size) {
	memcpy(this + m_data, data, size);
	m_data = size;
}

MemFs::MemFs(uint8_t *begin, uint8_t *end): m_version(*((uint32_t*) begin)), m_lastRec(*(MemFsPtr*) (begin + sizeof(m_version))) {
	if (version != m_version) {
		throw "MemFs version mismatch";
	}
	m_begin = begin;
	m_end = end;
	m_root = (Record*) (begin + sizeof(MemFsPtr));
}

void MemFs::init() {
	memset(m_begin, 0, m_end - m_begin);
	m_version = version;
}

void MemFs::write(std::string path, uint8_t *data, MemFsPtr dataLen) {
	const MemFsPtr size = offsetof(MemFs::Record, m_path) + path.size() + dataLen;
	auto rec = (Record*) alloc(size);
	rec->dataLen = dataLen;
	insert(m_root, rec);
}

int MemFs::read(std::string path, uint8_t **data, MemFsPtr *size) {
	auto rec = getRecord(m_root, path.c_str(), path.size());
	int retval = 1;
	if (rec) {
		*size = rec->dataLen;
		*data = (uint8_t*) malloc(*size);
		memcpy(*data, ptr<uint8_t*>(rec->m_data), *size);
		retval = 0;
	}
	return retval;
}

MemFs::Record *MemFs::getRecord(MemFs::Record *root, const char *path, MemFsPtr pathLen) {
	MemFsPtr len;
	if (root->pathLen() < pathLen) {
		len = root->pathLen();
	} else {
		len = pathLen;
	}
	auto cmp = strncmp(ptr<char*>(root->m_path), path, len);
	MemFsPtr recPt;
	if (cmp < 0) {
		recPt = root->left;
	} else if (cmp > 0) {
		recPt = root->right;
	} else {
		recPt = ptr(root);
	}
	if (recPt) {
		return getRecord(ptr<Record*>(recPt), path, pathLen);
	} else {
		return ptr<Record*>(recPt);
	}
}

void *MemFs::alloc(MemFsPtr size) {
	const auto iterator = this->iterator();
	if ((iterator + size) > (uint64_t) m_end) {
		compress();
		if ((iterator + size) > (uint64_t) m_end) {
			return nullptr;
		}
	}
	ptr<Record*>(m_lastRec)->next = iterator;

	auto rec = ptr<uint8_t*>(iterator);
	memset(rec, 0, size);
	ptr<Record*>(iterator)->prev = m_lastRec;
	m_lastRec = iterator;
	return rec;
}

void MemFs::compress() {
	auto current = m_root;
	while (current->next) {
		auto prevEnd = current + current->size();
		current = ptr<Record*>(current->next);
		if (prevEnd != current) {
			memcpy(prevEnd, current, current->size());
			current = prevEnd;
		}
	}
}

bool MemFs::insert(Record *root, Record *insertValue, MemFsPtr *rootParentPtr) {
	MemFsPtr len;
	if (root->pathLen() < insertValue->pathLen()) {
		len = root->pathLen();
	} else {
		len = insertValue->pathLen();
	}
	auto cmp = strncmp(ptr<char*>(root->m_path), ptr<char*>(insertValue->m_path), len);
	if (cmp < 0) {
		if (root->left) {
			return insert(ptr<Record*>(root->left), insertValue, &root->left);
		} else {
			root->left = ((uint8_t*) insertValue) - m_begin;
			return true;
		}
	} else if (cmp > 0) {
		if (root->right) {
			return insert(ptr<Record*>(root->right), insertValue, &root->right);
		} else {
			root->right = ((uint8_t*) insertValue) - m_begin;
			return true;
		}
	} else {
		auto ivAddr = ((uint8_t*) insertValue) - m_begin;
		if (root->prev) {
			ptr<Record*>(root->prev)->next = ivAddr;
		}
		if (root->next) {
			ptr<Record*>(root->next)->prev = ivAddr;
		}
		if (rootParentPtr) {
			*rootParentPtr = ivAddr;
		}
		return true;
	}
	return false;
}

MemFsPtr MemFs::iterator() {
	return m_lastRec + ((Record*) m_begin + m_lastRec)->size();
}

MemFsPtr MemFs::ptr(void *ptr) {
	return ((uint8_t*) ptr) - m_begin;
}

}
}
