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
#include <iostream>

void cpsk::SourceFile::commonUtils(){
    // @TODO
}
cpsk::SourceFile::SourceFile(const string& file_name)
{
    this->file_name = file_name;
    comments_enabled = true;
}
cpsk::SourceFile::SourceFile(const char *file_name)
{
    this->file_name = string(file_name);
    comments_enabled = true;
}
void cpsk::SourceFile::toggleComments(){
    this->comments_enabled ^= true;
}
void cpsk::SourceFile::enableComments(){
    this->comments_enabled = true;
}
void cpsk::SourceFile::disableComments(){
    this->comments_enabled = false;
}
string cpsk::SourceFile::getFileName() const{
    return file_name;
}
bool cpsk::SourceFile::getCommentStatus() const{
    return comments_enabled;
}
bool cpsk::SourceFile::produceSource() const{
    // @TODO
}