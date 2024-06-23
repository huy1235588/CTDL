# Command Line: make
CC=gcc
CXX=g++
TARGET=main# Program name
OBJS=main.o stack.c queue.c binary_search_tree.c
DEPS=stack.h queue.h binary_search_tree.h
# $@	All content to left of the the colon
# $^	All content to right of the the colon
# $<	The first content to the right of the colon

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^
%.o: %.c $(DEPS)
	$(CXX) -c $<

# Command Line: make run
run: $(TARGET)
	./$(TARGET)

# Command Line: make clean
clean:
	del $(TARGET).o $(TARGET).exe # For Windows	
