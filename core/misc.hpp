/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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

