# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -g

# Sources
SRCS = main.c matrice.c

# Header files (for dependencies)
HEADERS = matrice.h struct.h

# Executable name
TARGET = test_matrix

# Default target
all: $(TARGET)

# Compile the executable
$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lm

# Clean object files and executable
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
