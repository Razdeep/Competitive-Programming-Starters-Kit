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
#include "Misc.h"
#include "Constant.h"

#ifdef _WIN32

#else
#include <unistd.h>
#endif

void cpsk::Misc::delay() {
    delay(50);
}

void cpsk::Misc::delay(const long int ms) {
    usleep(ms * 1000);
}

void cpsk::Misc::drawLine(const char ch, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

void cpsk::Misc::drawLineTransition(unsigned int length, 
                                    char ch,
                                    unsigned int delayms) {
    for (uint8_t i = 0; i < length; i++) {
        std::cout << ch;
        std::cout.flush();
        delay(delayms);
    }
    std::cout << std::endl;
}

void cpsk::Misc::transitionText(const std::string &str, int ms) {
    for (uint8_t i = 0; i < str.size(); i++) {
        std::cout << str[i];
        std::cout.flush();
        delay(ms);
    }
    std::cout << std::endl;
}
