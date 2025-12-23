CC = gcc
CFLAGS = -std=gnu99 -Wall -Wextra -O2 -g
TARGET = minilang
SOURCES = main.c lexer.c symbols.c evaluator.c parser.c utils.c version.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = minilang.h version.h

all: $(TARGET)
	@echo "✓ MiniLang v3.1.0 compilé avec succès"
	@echo "  Nouvelles fonctionnalités:"
	@echo "    - Support void pour les procédures"
	@echo "    - Système de versioning (--version)"
	@echo "    - Aide intégrée (--help)"

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
	@echo "✓ Nettoyage effectué"

# Tests individuels
test-void: $(TARGET)
	@echo "=== Test: Procédures void ==="
	./$(TARGET) test_void.ml

test-functions: $(TARGET)
	@echo "=== Test: Fonctions ==="
	./$(TARGET) test_functions.ml

test-factorial: $(TARGET)
	@echo "=== Test: Factorielle ==="
	./$(TARGET) test_factorial.ml

test-fibonacci: $(TARGET)
	@echo "=== Test: Fibonacci ==="
	./$(TARGET) test_fibonacci_func.ml

test-arithmetic-func: $(TARGET)
	@echo "=== Test: Fonctions arithmétiques ==="
	./$(TARGET) test_arithmetic_func.ml

test-scope: $(TARGET)
	@echo "=== Test: Scopes ==="
	./$(TARGET) test_scope.ml

# Version et aide
version: $(TARGET)
	@./$(TARGET) --version

help-cmd: $(TARGET)
	@./$(TARGET) --help

# Tests complets
test-all: $(TARGET)
	@echo "╔══════════════════════════════════════╗"
	@echo "║   Tests MiniLang v3.1 - Void        ║"
	@echo "╚══════════════════════════════════════╝"
	@echo ""
	@echo "┌─ Test 1: Procédures void ─────────────┐"
	@./$(TARGET) test_void.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "┌─ Test 2: Fonctions basiques ──────────┐"
	@./$(TARGET) test_functions.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "┌─ Test 3: Factorielle ──────────────────┐"
	@./$(TARGET) test_factorial.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "┌─ Test 4: Fibonacci ────────────────────┐"
	@./$(TARGET) test_fibonacci_func.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "┌─ Test 5: Arithmétique ─────────────────┐"
	@./$(TARGET) test_arithmetic_func.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "┌─ Test 6: Scopes ───────────────────────┐"
	@./$(TARGET) test_scope.ml 2>&1 || true
	@echo "└─────────────────────────────────────────┘"
	@echo ""
	@echo "✅ Tests terminés!"

# Info sur le projet
info:
	@./$(TARGET) --version
	@echo ""
	@echo "Architecture modulaire:"
	@echo "  - main.c       : Point d'entrée avec CLI"
	@echo "  - lexer.c      : Analyse lexicale"
	@echo "  - parser.c     : Analyse syntaxique"
	@echo "  - evaluator.c  : Évaluation des expressions"
	@echo "  - symbols.c    : Gestion variables et fonctions"
	@echo "  - utils.c      : Fonctions utilitaires"
	@echo "  - version.c    : Système de versioning"
	@echo "  - minilang.h   : En-tête principal"
	@echo "  - version.h    : Informations de version"

# Aide
help:
	@echo "Cibles disponibles:"
	@echo "  make              - Compiler MiniLang v3.1"
	@echo "  make all          - Compiler MiniLang v3.1"
	@echo "  make clean        - Supprimer les fichiers compilés"
	@echo ""
	@echo "Commandes CLI:"
	@echo "  make version      - Afficher la version"
	@echo "  make help-cmd     - Afficher l'aide de minilang"
	@echo ""
	@echo "Tests individuels:"
	@echo "  make test-void            - Tester les procédures void"
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

.PHONY: all clean test-void test-functions test-factorial test-fibonacci test-arithmetic-func test-scope test-all version help-cmd info help
