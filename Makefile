# Compiler
CXX ?= g++

# Compiler flags
CXXFLAGS ?= --std=c++17 -Wall -Werror -pedantic -g -Wno-sign-compare -Wno-comment

main.exe: main.cpp Shapes.hpp
	$(CXX) $(CXXFLAGS) main.cpp Shapes.hpp -o main.exe

clean:
	rm main.exe