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
#include "SourceFile.h"
#include "BaseException.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

#ifdef WINDOWS
#include <direct.h>
std::string getCurrentDirectory() {
    return std::string(_getcwd());
}
#else
#include <unistd.h>
std::string getCurrentDirectory() {
    constexpr int MAX = int(1e5);
    char res[MAX];
    return (getcwd(res, MAX) ? std::string(res): std::string(""));
}
#endif

constexpr int MAX = int(1e5);

cpsk::SourceFile::SourceFile(const std::string &file_name) {
    mFileName = file_name;
    mIsCommentsEnabled = true;
    ensureExtension();
}

cpsk::SourceFile::SourceFile(const char *file_name) {
    mFileName = std::string(file_name);
    mIsCommentsEnabled = true;
    ensureExtension();
}

void cpsk::SourceFile::toggleComments() {
    mIsCommentsEnabled ^= true;
}

void cpsk::SourceFile::enableComments() {
    mIsCommentsEnabled = true;
}

void cpsk::SourceFile::disableComments() {
    mIsCommentsEnabled = false;
}

std::string cpsk::SourceFile::getFileName() const {
    return mFileName;
}

bool cpsk::SourceFile::getCommentStatus() const {
    return mIsCommentsEnabled;
}

bool cpsk::SourceFile::produceSource() const {
    std::fstream template_file;
    std::fstream output_file;
    try {
        std::string file_name = "TEMPLATE";
        std::string file_name_path = getenv("HOME");
        file_name_path += "/.cpsk/";
        file_name_path += file_name;
        template_file.open(file_name_path, std::ios::in);
        if (!template_file) {
            throw new cpsk::exceptions::FileNotFoundException();
        }
        std::string output_file_name_path = getCurrentDirectory() + "/" + mFileName;
        output_file.open(output_file_name_path, std::ios::trunc | std::ios::out);
        if (!output_file) {
            throw new cpsk::exceptions::FileCreationException();
        }
        char buffer[MAX];
        while (!template_file.eof()) {
            template_file.getline(buffer, MAX);
            output_file << buffer;
            output_file << std::endl;
        }
        template_file.close();
        output_file.close();
        std::cout << file_name << " successfully created." << std::endl;
    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
        template_file.close();
        output_file.close();
        return false;
    } catch (...) {
        std::cerr << "Error occurred" << std::endl;
        template_file.close();
        output_file.close();
        return false;
    }
    template_file.close();
    output_file.close();
    return true;
}

bool cpsk::SourceFile::hasCorrectExtension() const {
    const std::string expected_extension = ".cpp";
    int file_name_length = int(mFileName.size());
    return mFileName.substr(file_name_length - 4, file_name_length) == expected_extension;
}

void cpsk::SourceFile::ensureExtension() {
    int file_name_length = int(mFileName.size());

    if (file_name_length > 4) {
        if (!hasCorrectExtension()) {
            mFileName += ".cpp";
        }
    } else {
        mFileName += ".cpp";
    }
}
