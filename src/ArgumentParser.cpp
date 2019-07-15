/**
 *   Copyright 2019 Rajdeep Roy Chowdhury <rrajdeeproychowdhury@gmail.com>
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */
#include <unordered_map>
#include "ArgumentParser.h"

std::unordered_map<std::string, std::string> cpsk::ArgumentParser::parse(int argc, char *argv[]) {
    // @TODO Put the value having blank key to the key 'filename'
    std::unordered_map<std::string, std::string> param_map;
    for (int i = 0; i < argc; i += 2) {
        param_map[argv[i]] = argv[i + 1];
    }
    return param_map;
}
