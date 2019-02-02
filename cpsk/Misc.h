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
#ifndef __MISC_H
#define __MISC_H
#include <iostream>
namespace cpsk{
  class Misc
  {
    public:
      static void delay();
      static void delay(const long int);
      static void drawLine(int);
      static void drawLine(const char, int);
      static void drawLineTransition(unsigned int length,unsigned int delayms);
      static void drawLineTransition(const char, int, int);
      static void transitionText(const std::string& str, int ms=100);
  };
}
#endif