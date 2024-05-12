#!make -f

CXX=clang++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

run: demo
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test



	
# CC = clang++
# CFLAGS = -Wall -Wextra -std=c11

# SRCDIR = src
# OBJDIR = obj
# BINDIR = bin

# SRC = $(wildcard $(SRCDIR)/*.c)
# OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
# EXEC = $(BINDIR)/main

# .PHONY: all clean

# all: $(EXEC)

# $(EXEC): $(OBJ) | $(BINDIR)
# 	$(CC) $(CFLAGS) $^ -o $@

# $(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJDIR):
# 	mkdir -p $(OBJDIR)

# $(BINDIR):
# 	mkdir -p $(BINDIR)

# clean:
# 	rm -rf $(OBJDIR) $(BINDIR)
