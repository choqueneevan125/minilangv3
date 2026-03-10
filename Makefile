# Makefile pour MiniLang v3.2.0

CC = gcc
CFLAGS = -std=gnu99 -Wall -Wextra -O2 -g
TARGET = minilang

SOURCES = main.c lexer.c symbols.c evaluator.c parser.c utils.c version.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)
	@echo "✓ MiniLang v3.2.0 compilé avec succès"
	@echo "  Nouvelles fonctionnalités:"
	@echo "    - Type bool natif (true/false)"
	@echo "    - break et continue dans les boucles"
	@echo "    - input() pour lire l'entrée utilisateur"
	@echo "    - Concaténation de chaînes avec +"
	@echo "    - Print amélioré avec concaténation"

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c minilang.h version.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
	@echo "✓ Nettoyage effectué"

test: $(TARGET)
	@echo "🧪 Tests de base..."
	@./$(TARGET) test_bool.ml
	@echo ""
	@./$(TARGET) test_break_continue.ml

install: $(TARGET)
	cp $(TARGET) /usr/local/bin/
	@echo "✓ MiniLang installé dans /usr/local/bin/"

uninstall:
	rm -f /usr/local/bin/$(TARGET)
	@echo "✓ MiniLang désinstallé"

.PHONY: all clean test install uninstall
