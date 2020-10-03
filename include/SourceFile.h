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

#ifndef __SOURCE_FILE_H
#define __SOURCE_FILE_H

namespace cpsk {
    class SourceFile {
    private:
        std::string mFileName;
        bool mIsCommentsEnabled;
        std::string mHeaderText;

    public:
        SourceFile() : mFileName(std::string("01")), mIsCommentsEnabled(true) {}

        SourceFile(const std::string &file_name);

        SourceFile(const char *file_name);

        void toggleComments();
        void enableComments();
        void disableComments();

        std::string getFileName() const;

        bool getCommentStatus() const;

        bool hasCorrectExtension() const;
        void ensureExtension();
        bool produceSource() const;
    };
}
#endif