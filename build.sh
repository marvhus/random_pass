#!/bin/bash

set -xe

g++ -o pass_gen main.cpp -Wall -Werror -std=c++11 -pedantic -ggdb
