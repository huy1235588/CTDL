# Command Line: make
CC=gcc
CXX=g++
TARGET=test_menu# Program name
OBJS=test_menu.o libs/stack.c libs/queue.c libs/linked_list.c
DEPS=libs/stack.h libs/queue.h libs/linked_list.c
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
