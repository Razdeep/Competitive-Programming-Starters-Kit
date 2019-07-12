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
#include <fstream>
#include "MainHelper.h"
#include "Misc.h"

#define MAX 1000000

void cpsk::MainHelper::showHelp()
{
    std::cout << "To create a source file quickly, type `cpsk <FILENAME>`" << std::endl;
}
void cpsk::MainHelper::showVersion()
{
    Misc::drawLineTransition(60, 50);
    std::string space = "                ";
    Misc::transitionText(space + " #####  ######   #####  #    #");
    Misc::transitionText(space + "#     # #     # #     # #   #");
    Misc::transitionText(space + "#       #     # #       #  # ");
    Misc::transitionText(space + "#       ######   #####  ###");
    Misc::transitionText(space + "#       #             # #  #");
    Misc::transitionText(space + "#     # #       #     # #   #");
    Misc::transitionText(space + " #####  #        #####  #    # ");
    Misc::drawLineTransition(60, 50);
    Misc::transitionText(std::string("\tCompetitive Programming Starters Kit (CPSK)"), 100);
    Misc::transitionText(std::string("\t\tby Rajdeep Roy Chowdhury"), 100);
    Misc::drawLineTransition(60, 50);
    Misc::transitionText(std::string("Version 0.1"));
}
