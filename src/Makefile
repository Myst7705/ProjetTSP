# ===============================
#   Makefile pour test TSPLIB
# ===============================

# Nom de l'exécutable
EXEC = tspreader

# Compilateur + options
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11

# Fichiers sources (ici, seulement lectureTSPLIB.c pour l’instant)
SRC = lectureTSPLIB.c

# Fichiers objets générés automatiquement
OBJ = $(SRC:.c=.o)

# Headers utilisés
HEADERS = struct.h lectureTSPLIB.h

# Règle par défaut
all: $(EXEC)

# Construction de l’exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation de chaque .c en .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ)

# Nettoyage complet
mrproper: clean
	rm -f $(EXEC)

# Exécution rapide
run: $(EXEC)
	./$(EXEC)

