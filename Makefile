# Compiler and flags 
CC = gcc 
CFLAGS = -std=gnu11 -Wall 
LDLIBS = -lpthread -lm

# Directories 
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Binaries
TSP = $(BINDIR)/tsp

# Common 
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ_COMMON = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


# Link rules
$(TSP): $(OBJ_COMMON)
	$(CC) -o $(TSP) $(OBJ_COMMON) $(LDLIBS)

# Compile rules
# '%' matches filename
# $@  for the pattern-matched target
# $<  for the pattern-matched dependency
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

dirs:
	@mkdir -p $(OBJDIR) $(BINDIR)

# Housekeeping
clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/* 