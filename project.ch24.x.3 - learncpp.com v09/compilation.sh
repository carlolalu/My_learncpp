#!/bin/bash

cd src
g++ -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Werror -Wsign-conversion -std=c++20 -o ../build/executable.out ./*