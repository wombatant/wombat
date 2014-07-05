/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE_MISC_HPP
#define WOMBAT_CORE_MISC_HPP

#include <string>
#include <functional>

#include <models/models.hpp>
#include "types.hpp"

namespace wombat {
namespace core {

/**
 * Sets the language used by this application.
 * Defaults to "english".
 * @param lang the language used by this application
 */
void setLanguage(std::string lang);

/**
 * Gets the language used by this application.
 * @return the language used by this application
 */
std::string getLanguage();

/**
 * Initializes graphics, user input, and audio
 * @return 0 if successful
 */
int init(models::Settings settings);

void draw();

/**
 * Used for getting the time stamp for when processing for the current event was started.
 * @return the time stamp for when processing for the current event was started
 */
uint64 eventTime();

uint64 time();

bool running();

void quit();

void main();

void debug(std::string);

}
}

#endif

