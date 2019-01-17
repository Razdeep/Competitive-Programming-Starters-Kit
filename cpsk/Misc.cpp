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
void Misc::delay()
{
    for (int i = 0; i < 100000; i++)
        for (int j = 0; j < 1000; j++)
            ;
}
void Misc::delay(const long int ms)
{
    // @TODO
    for (int i = 0; i < 10000; i++)
        for (int j = 0; j < 1000; j++)
            ;
}
void Misc::drawLine(int n = 50)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
}
void Misc::drawLine(const char ch, int n = 50)
{
    int i;
    for (i = 0; i < n; i++)
    {
        std::cout << ch;
    }
    std::cout << std::endl;
}
void Misc::drawLineTransition(unsigned int length, unsigned int delayms)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << "-";
        std::cout.flush();
        delay(100);
    }
    std::cout << std::endl;
}
void Misc::drawLineTransition(const char ch, int n = 50, int ms = 50)
{
    int i;
    for (i = 0; i < n; i++)
    {
        std::cout << ch;
        delay(100);
    }
    std::cout << std::endl;
}
void Misc::transitionText(const std::string& str, int ms)
{
    for (int i = 0; i < str.size(); i++)
    {
        std::cout << str[i];
        std::cout.flush();
        delay(ms);
    }
    std::cout << std::endl;
}