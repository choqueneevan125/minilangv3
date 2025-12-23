CC = gcc
CFLAGS = -std=gnu99 -Wall -Wextra -O2 -g
TARGET = minilang
SOURCES = main.c lexer.c symbols.c evaluator.c parser.c utils.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = minilang.h

all: $(TARGET)
	@echo "✓ MiniLang v3 compilé avec succès"
	@echo "  Architecture modulaire activée"
	@echo "  Support des fonctions ajouté"

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
	@echo "✓ Nettoyage effectué"

# Tests individuels
test-functions: $(TARGET)
	@echo "=== Test: Fonctions ==="
	./$(TARGET) test_functions.ml

test-factorial: $(TARGET)
	@echo "=== Test: Factorielle récursive ==="
	./$(TARGET) test_factorial.ml

test-fibonacci: $(TARGET)
	@echo "=== Test: Fibonacci avec fonction ==="
	./$(TARGET) test_fibonacci_func.ml

test-arithmetic-func: $(TARGET)
	@echo "=== Test: Fonctions arithmétiques ==="
	./$(TARGET) test_arithmetic_func.ml

test-scope: $(TARGET)
	@echo "=== Test: Scopes ==="
	./$(TARGET) test_scope.ml

# Tests complets
test-all: $(TARGET)
	@echo "╔══════════════════════════════════════╗"
	@echo "║   Tests MiniLang v3 - Fonctions     ║"
	@echo "╚══════════════════════════════════════╝"
	@echo ""
	@echo "┌─ Test 1: Fonctions basiques ──────────┐"
	@./$(TARGET) test_functions.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "┌─ Test 2: Factorielle ──────────────────┐"
	@./$(TARGET) test_factorial.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "┌─ Test 3: Fibonacci ────────────────────┐"
	@./$(TARGET) test_fibonacci_func.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "┌─ Test 4: Arithmétique ─────────────────┐"
	@./$(TARGET) test_arithmetic_func.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "┌─ Test 5: Scopes ───────────────────────┐"
	@./$(TARGET) test_scope.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "✅ Tests terminés!"

# Info sur le projet
info:
	@echo "MiniLang v3 - Architecture modulaire"
	@echo ""
	@echo "Fichiers sources:"
	@echo "  - main.c       : Point d'entrée"
	@echo "  - lexer.c      : Analyse lexicale"
	@echo "  - parser.c     : Analyse syntaxique"
	@echo "  - evaluator.c  : Évaluation des expressions"
	@echo "  - symbols.c    : Gestion variables et fonctions"
	@echo "  - utils.c      : Fonctions utilitaires"
	@echo "  - minilang.h   : Déclarations et structures"
	@echo ""
	@echo "Fonctionnalités:"
	@echo "  ✓ Types: int, float, str, tableaux"
	@echo "  ✓ Opérateurs: +, -, *, /, %, ==, !=, <, >, <=, >=, &&, ||, !"
	@echo "  ✓ Structures: if/else, while, for"
	@echo "  ✓ Fonctions avec paramètres et return"
	@echo "  ✓ Scopes isolés pour chaque fonction"
	@echo "  ✓ Commentaires // et /* */"

help:
	@echo "Cibles disponibles:"
	@echo "  make              - Compiler MiniLang v3"
	@echo "  make all          - Compiler MiniLang v3"
	@echo "  make clean        - Supprimer les fichiers compilés"
	@echo ""
	@echo "Tests individuels:"
	@echo "  make test-functions       - Tester les fonctions basiques"
	@echo "  make test-factorial       - Tester la factorielle"
	@echo "  make test-fibonacci       - Tester Fibonacci"
	@echo "  make test-arithmetic-func - Tester fonctions arithmétiques"
	@echo "  make test-scope           - Tester les scopes"
	@echo ""
	@echo "Tests groupés:"
	@echo "  make test-all     - Exécuter tous les tests"
	@echo ""
	@echo "Informations:"
	@echo "  make info         - Afficher les infos du projet"
	@echo "  make help         - Afficher cette aide"

.PHONY: all clean test-functions test-factorial test-fibonacci test-arithmetic-func test-scope test-all info help
