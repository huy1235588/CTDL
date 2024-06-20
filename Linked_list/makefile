# Command Line: make
CC=gcc
CXX=g++
TARGET=App	# Program name
OBJS=main.o singly_linked_list.c
DEPS=singly_linked_list.h
# $@	All content to left of the the colon
# $^	All content to right of the the colon
# $<	The first content to the right of the colon

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^
%.o: %.c $(DEPS)
	$(CXX) -c $<

# Command Line: make clean
clean:
	# rm -rf $(TARGET) $(OBJS)		# For Linux
	del $(TARGET) $(TARGET).exe $(OBJS)	# For Windows
