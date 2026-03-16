# Makefile pour MiniLang v3.2.3
# Structure organisée avec dossiers src/, include/, tests/

# ============================================================================
# CONFIGURATION
# ============================================================================

CC = gcc
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

all: $(BUILD_DIR) $(TARGET)
	@echo ""
	@echo "✓ MiniLang v3.3.0 compilé avec succès"
	@echo "  Structure organisée :"
	@echo "    src/      - Sources C"
	@echo "    include/  - Headers"
	@echo "    tests/    - Fichiers de test"
	@echo ""
	@echo "  Nouvelles fonctionnalités v3.3.0 :"
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

test: $(TARGET)
	@echo "🧪 Exécution des tests..."
	@echo ""
	@echo "--- Test Bool ---"
	@./$(TARGET) $(TEST_DIR)/test_bool.ml
	@echo ""
	@echo "--- Test Concaténation ---"
	@./$(TARGET) $(TEST_DIR)/test_concat_complet.ml
	@echo ""
	@echo "✅ Tous les tests passent !"

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

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo "✓ Nettoyage effectué"

clean-all: clean
	rm -f $(TEST_DIR)/*.out

# ============================================================================
# INSTALLATION
# ============================================================================

install: $(TARGET)
	cp $(TARGET) /usr/local/bin/
	@echo "✓ MiniLang installé dans /usr/local/bin/"

uninstall:
	rm -f /usr/local/bin/$(TARGET)
	@echo "✓ MiniLang désinstallé"

# ============================================================================
# DOCUMENTATION
# ============================================================================

info:
	@echo "MiniLang v3.2.3 - Structure du projet"
	@echo ""
	@echo "Dossiers :"
	@echo "  src/      - Sources C ($(words $(SOURCES)) fichiers)"
	@echo "  include/  - Headers ($(words $(HEADERS)) fichiers)"
	@echo "  tests/    - Tests .ml"
	@echo "  build/    - Objets compilés (créé à la compilation)"
	@echo ""
	@echo "Commandes :"
	@echo "  make              - Compiler"
	@echo "  make test         - Exécuter tous les tests"
	@echo "  make clean        - Nettoyer"
	@echo "  make install      - Installer (sudo requis)"
	@echo "  make info         - Cette aide"

# ============================================================================
# DÉVELOPPEMENT
# ============================================================================

debug: CFLAGS += -DDEBUG -g3
debug: clean $(TARGET)
	@echo "✓ Version debug compilée"

# Compter les lignes de code
count:
	@echo "Lignes de code :"
	@wc -l $(SRC_DIR)/*.c $(INC_DIR)/*.h | tail -1
	@echo ""
	@echo "Détail :"
	@wc -l $(SRC_DIR)/*.c | grep -v total
	@echo ""
	@wc -l $(INC_DIR)/*.h | grep -v total

.PHONY: all test test-concat test-bool test-break test-functions clean clean-all install uninstall info debug count
