#!/bin/bash

g++ main.cpp \
    MainHelper.cpp \
    ArgumentParser.cpp \
    Misc.cpp \
    SourceFile.cpp \
-Wall -o cpsk

echo "-----------------------------"
echo -e "Compilation completed."
echo "-----------------------------"