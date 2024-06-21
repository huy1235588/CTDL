# Command Line: make
CC=gcc
CXX=g++
TARGET=test# Program name
OBJS=test.o linked_list.c
DEPS=linked_list.h
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
