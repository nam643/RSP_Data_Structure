#!/bin/bash

g++ $1.cpp -std=c++20 -Wall -Wextra -o $1.exe && ./$1.exe