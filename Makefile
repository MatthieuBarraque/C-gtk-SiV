CC=gcc
CFLAGS=-Iinclude $(shell pkg-config --cflags gtk+-3.0) -g
LDFLAGS=$(shell pkg-config --libs gtk+-3.0)
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
TARGET=bin/SpaceVaders

# Cible par défaut
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compilation des fichiers source
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

# Nettoyage des fichiers intermédiaires
clean:
	rm -rf src/*.o

# Nettoyage total y compris l'exécutable
mrproper: clean
	rm -rf $(TARGET)

# Nettoyage complet (alias de mrproper)
fclean: mrproper

# Recompilation
re: fclean all
