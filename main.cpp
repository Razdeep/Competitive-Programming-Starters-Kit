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
#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include "MainHelper.h"
#include "ArgumentParser.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)
        cpsk::MainHelper::showHelp();
    else if (argc == 2)
    {
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        {
            cpsk::MainHelper::showHelp();
        }
        else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)
        {
            cpsk::MainHelper::showVersion();
        }
        else
        {
            string file_name = string(argv[1]);
            int file_name_length = file_name.size();
            string match(".cpp");
            if (file_name.size() > 4)
            {
                if (file_name.substr(file_name_length - 4, file_name_length) != match)
                    file_name += ".cpp";
            }
            else
            {
                file_name += ".cpp";
            }
            cpsk::MainHelper::produceSource(file_name);
            cout << file_name << " successfully generated" << endl;
        }
    }
    else if (argc & 1)
    {
        // @TODO
        unordered_map<string, string> param_map = cpsk::ArgumentParser::parse(argc, argv);
    }
    else
    {
        cerr << "Check whether you have selected the right flags." << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}