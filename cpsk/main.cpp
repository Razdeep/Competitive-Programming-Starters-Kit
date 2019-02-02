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
#include <cstring>
#include <unordered_map>
#include "MainHelper.h"
#include "ArgumentParser.h"

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
        else if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)
        {
            cpsk::MainHelper::showVersion();
        }
        else
        {
            
        }
    }
    else if (argc%2 == 0)
    {
        std::cerr << "Check whether you have selected the right flags." << std::endl;
        return EXIT_FAILURE;
    }
    else{
        std::unordered_map<std::string, std::string> param_map = cpsk::ArgumentParser::parse(argc,argv);
        FILE *template_file_pointer = fopen("TEMPLATE","r");                                // @TODO: get source directory and add it to path
        FILE *output_file_pointer = fopen(param_map[std::string("filename")].c_str(),"w");  // @TODO: get current working directory
        
        fclose(template_file_pointer);
        fclose(output_file_pointer);
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}