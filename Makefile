# Makefile pour MiniLang v3.3.0
# Structure organisée avec dossiers src/, include/, tests/

# ============================================================================
# CONFIGURATION
# ============================================================================

CC = gcc
VERSION = 3.3.0
CFLAGS = -std=gnu99 -Wall -Wextra -O2 -g -Iinclude
TARGET = minilang

# Dossiers
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests
BUILD_DIR = build

# Fichiers
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
HEADERS = $(wildcard $(INC_DIR)/*.h)

# ============================================================================
# RÈGLES PRINCIPALES
# ============================================================================

.PHONY: all

all: $(BUILD_DIR) $(TARGET)
	@echo ""
	@echo "✓ MiniLang v$(VERSION) compilé avec succès"
	@echo "  Structure organisée :"
	@echo "    src/      - Sources C"
	@echo "    include/  - Headers"
	@echo "    tests/    - Fichiers de test"
	@echo ""
	@echo "  Fonctionnalités :"
	@echo "    - Opérateurs composés : +=, -=, *=, /="
	@echo "    - Comparaison de chaînes : ==, !="
	@echo "    - input() fonctionnel"
	@echo "    - Concaténation complète"

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# ============================================================================
# TESTS
# ============================================================================

.PHONY: test test-verbose test-concat test-bool test-break test-functions

test: all
	@echo ""
	@echo "════════════════════════════════════════════════════════"
	@echo "   Lancement de la suite de tests..."
	@echo "════════════════════════════════════════════════════════"
	@./run_tests.sh

test-verbose: all
	@./run_tests.sh --verbose

test-concat: $(TARGET)
	./$(TARGET) $(TEST_DIR)/test_concat_complet.ml

test-bool: $(TARGET)
	./$(TARGET) $(TEST_DIR)/test_bool.ml

test-break: $(TARGET)
	./$(TARGET) $(TEST_DIR)/test_break_continue.ml

test-functions: $(TARGET)
	./$(TARGET) $(TEST_DIR)/test_functions.ml

# ============================================================================
# NETTOYAGE
# ============================================================================

.PHONY: clean clean-all

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo "✓ Nettoyage effectué"

clean-all: clean
	rm -f $(TEST_DIR)/*.out

# ============================================================================
# INSTALLATION
# ============================================================================

.PHONY: install uninstall

install: $(TARGET)
	cp $(TARGET) /usr/local/bin/
	@echo "✓ MiniLang installé dans /usr/local/bin/"

uninstall:
	rm -f /usr/local/bin/$(TARGET)
	@echo "✓ MiniLang désinstallé"

# ============================================================================
# DOCUMENTATION
# ============================================================================

.PHONY: info

info:
	@echo "MiniLang v$(VERSION) - Structure du projet"
	@echo ""
	@echo "Dossiers :"
	@echo "  src/      - Sources C ($(words $(SOURCES)) fichiers)"
	@echo "  include/  - Headers ($(words $(HEADERS)) fichiers)"
	@echo "  tests/    - Tests .ml"
	@echo "  build/    - Objets compilés"
	@echo ""
	@echo "Commandes :"
	@echo "  make              - Compiler"
	@echo "  make test         - Exécuter la suite complète"
	@echo "  make test-verbose - Tests détaillés"
	@echo "  make clean        - Nettoyer"
	@echo "  make install      - Installer"
	@echo "  make info         - Cette aide"

# ============================================================================
# DÉVELOPPEMENT
# ============================================================================

.PHONY: debug count

debug: CFLAGS += -DDEBUG -g3
debug: clean $(TARGET)
	@echo "✓ Version debug compilée"

count:
	@echo "Lignes de code :"
	@wc -l $(SRC_DIR)/*.c $(INC_DIR)/*.h | tail -1
	@echo ""
	@echo "Détail sources :"
	@wc -l $(SRC_DIR)/*.c | grep -v total
	@echo ""
	@echo "Détail headers :"
	@wc -l $(INC_DIR)/*.h | grep -v total
