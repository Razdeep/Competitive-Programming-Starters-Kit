#include <gtest/gtest.h>
#include "SourceFile.h"

using cpsk::SourceFile;

class SourceFileTest : public ::testing::Test {
protected:
    std::string mCorrectSourceFileName   = "sample.cpp";
    std::string mIncorrectSourceFileName = "sample.abc";
};

TEST_F(SourceFileTest, correct_file_name_test) {
    SourceFile sourceFile(mCorrectSourceFileName);
    EXPECT_EQ(sourceFile.hasCorrectExtension(), true);
}

TEST_F(SourceFileTest, incorrect_file_name_test) {
    SourceFile sourceFile(mIncorrectSourceFileName);
    EXPECT_EQ(sourceFile.hasCorrectExtension(), true);
}