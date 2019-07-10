#########################################################
#                                                       #
# Competitive Programming Starters Kit (CPSK)           #
#                                                       #
# Copyright (C) 2019, Rajdeep Roy Chowdhury             #
#                     <rrajdeeproychowdhury@gmail.com>  #
#                                                       #
#########################################################

CC = g++
CFLAGS = -Wall
OPT_LEVEL = -O3

default: cpsk

all: cpsk

cpsk: clean
	$(CC) $(CFLAGS) $(OPT_LEVEL) src/* main.cpp -o cpsk
	@echo "[~] Compiled"

clean:
	-rm -f cpsk
	@echo "[~] Cleaned"

install: cpsk
	sudo mv cpsk /usr/local/bin/

