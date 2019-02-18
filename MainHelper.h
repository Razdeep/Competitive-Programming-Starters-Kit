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
#ifndef __MAIN_HELPER_H
#define __MAIN_HELPER_H
#include <iostream>
#include <unordered_map>
namespace cpsk{
  class MainHelper
  {
    public:
      static void showHelp(); // Shows help if specified in command line flag
      static void showVersion(); // Shows help if specified in command line flag
      static bool produceSource(std::string& file_name); // Produces output code
      static bool produceSource(const char *filename); // Produces output code
  };
}
#endif