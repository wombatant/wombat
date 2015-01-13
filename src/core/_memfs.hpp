/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE__MEMFS_HPP
#define WOMBAT_CORE__MEMFS_HPP

#include "_memfs.hpp"
#include "core.hpp"

namespace wombat {
namespace core {

typedef uint32_t MemFsPtr;

class MemFs {
	public:
		static uint32_t version;
	private:
		struct Record {
			// the next Record in memory
			MemFsPtr prev, next;
			MemFsPtr left, right;
			MemFsPtr dataLen;
			// offsets from Record this
			MemFsPtr m_path;
			MemFsPtr m_data;

			MemFsPtr pathLen();
			MemFsPtr size();
			void setPath(std::string);
			void setData(uint8_t *data, int size);
		};

		uint8_t *m_begin, *m_end;
		uint32_t &m_version;
		// the last Record in the MemFs's memory chunk
		MemFsPtr &m_lastRec;
		Record *m_root;

	public:
		/**
		 * Constructor
		 * @param begin pointer to the beginning of this MemFs's memory chunk
		 * @param end pointer to the end of this MemFs's memory chunk
		 */
		MemFs(uint8_t *begin, uint8_t *end);

		/**
		 * Initializes the memory chunk of this MemFs was given.
		 * This clears the previous contents.
		 */
		void init();

		/**
		 * Writes the given data to a "file" with the given path.
		 * @param path the path of the file
		 * @param data the contents of the file
		 * @param dataLen the number of bytes data points to
		 */
		void write(std::string path, uint8_t *data, MemFsPtr dataLen);

		/**
		 * Reads the "file" at the given path. You are responsible for freeing
		 * the data when done with it.
		 * @param path path of the "file"
		 * @param data pointer to the pointer where the data is stored
		 * @param size pointer to a value that will be assigned the size of data
		 * @return 0 if read is a success
		 */
		int read(std::string path, uint8_t **data, MemFsPtr *size);

	private:
		/**
		 * Gets the record at the given path.
		 * @param root the root node to start comparing on
		 * @param path path of the "file"
		 * @param pathLen number of characters in pathLen
		 * @return the requested Record, if available
		 */
		Record *getRecord(Record *root, const char *path, MemFsPtr pathLen);

		/**
		 * Gets an address for a new Record.
		 * @param size the size of the Record
		 */
		void *alloc(MemFsPtr size);

		/**
		 * Compresses all of the records into a contiguous space, starting at m_root.
		 */
		void compress();

		/**
		 * Inserts the given insertValue into the tree of the given root.
		 * If the record already exists, it replaces the old on deletes it.
		 * @return true if the record was inserted
		 */
		bool insert(Record *root, Record *insertValue, MemFsPtr *rootParentPtr = 0);

		/**
		 * Gets the MemFsPtr associated with the next Record to be allocated.
		 * @retrun the MemFsPtr associated with the next Record to be allocated
		 */
		MemFsPtr iterator();

		/**
		 * Converts an actual pointer to a MemFsPtr.
		 */
		MemFsPtr ptr(void *ptr);

		/**
		 * Converts a MemFsPtr to an actual pointer.
		 */
		template<typename T>
		T ptr(MemFsPtr ptr);
};

template<typename T>
T MemFs::ptr(MemFsPtr ptr) {
	return (T) m_begin + ptr;
}

}
}

#endif
