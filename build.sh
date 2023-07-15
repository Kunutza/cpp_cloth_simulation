#!/bin/sh

files="main.cpp src/read/values.cpp"
libs="-lsfml-graphics -lsfml-window -lsfml-system"

g++ -o test $files $libs && ./test
