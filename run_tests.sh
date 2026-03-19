#!/bin/bash

# Script de test automatique pour MiniLang
# Usage: ./run_tests.sh [--verbose]

VERBOSE=0
if [ "$1" = "--verbose" ] || [ "$1" = "-v" ]; then
    VERBOSE=1
fi

# Couleurs
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m'

# Compteurs
TOTAL=0
PASSED=0
FAILED=0
SKIPPED=0

# Vérifier que minilang existe
if [ ! -f "./minilang" ]; then
    echo -e "${RED}Erreur: ./minilang non trouvé${NC}"
    echo "Compilez d'abord avec 'make'"
    exit 1
fi

# Fonction pour afficher le résultat
print_result() {
    local test_name=$1
    local status=$2
    local message=$3
    
    if [ $status -eq 0 ]; then
        echo -e "${GREEN}✓${NC} $test_name"
        if [ $VERBOSE -eq 1 ] && [ -n "$message" ]; then
            echo "  $message"
        fi
        ((PASSED++))
    elif [ $status -eq 2 ]; then
        echo -e "${YELLOW}⊘${NC} $test_name (ignoré)"
        ((SKIPPED++))
    else
        echo -e "${RED}✗${NC} $test_name"
        if [ -n "$message" ]; then
            echo -e "  ${RED}$message${NC}"
        fi
        ((FAILED++))
    fi
    ((TOTAL++))
}

# Fonction pour exécuter un test
run_test() {
    local test_file=$1
    local expected_status=${2:-0}
    
    # Extraire juste le nom du fichier
    local test_name=$(basename "$test_file")
    
    # Timeout de 3 secondes
    timeout 3 ./minilang "$test_file" > /tmp/minilang_test_output.txt 2>&1
    local exit_code=$?
    
    if [ $exit_code -eq 124 ]; then
        print_result "$test_name" 1 "Timeout (boucle infinie?)"
        return
    fi
    
    # Détecter si c'est un test qui DOIT échouer
    # (nom contient "error", "invalid", "wrong", ou taille négative/zéro)
    if [[ $test_name =~ (error|invalid|wrong|negative|_31|_32|_22) ]]; then
        expected_status=1
    fi
    
    if [ $expected_status -eq 1 ]; then
        if [ $exit_code -ne 0 ] || grep -q "Erreur" /tmp/minilang_test_output.txt; then
            print_result "$test_name" 0
        else
            print_result "$test_name" 1 "Devrait échouer"
        fi
    else
        if [ $exit_code -eq 0 ]; then
            print_result "$test_name" 0
        else
            local error_msg=$(grep "Erreur" /tmp/minilang_test_output.txt | head -1)
            print_result "$test_name" 1 "$error_msg"
        fi
    fi
}

echo -e "${CYAN}════════════════════════════════════════════════════════${NC}"
echo -e "${CYAN}   🧪 MiniLang - Suite de Tests Automatiques${NC}"
echo -e "${CYAN}════════════════════════════════════════════════════════${NC}"
echo ""

VERSION=$(./minilang --version 2>&1 | grep -oP 'v\d+\.\d+\.\d+' | head -1)
echo -e "Version: ${GREEN}$VERSION${NC}"
echo -e "Date:    $(date '+%Y-%m-%d %H:%M:%S')"
echo ""

# Organiser les tests par catégorie
echo -e "${BLUE}[1] Tests Basiques${NC}"
for test in tests/test_basic_*.ml; do
    [ -f "$test" ] && run_test "$test"
done
echo ""

echo -e "${BLUE}[2] Tests Critiques de Sécurité${NC}"
for test in tests/test_critical_*.ml; do
    [ -f "$test" ] && run_test "$test"
done
echo ""

echo -e "${BLUE}[3] Opérations sur Chaînes${NC}"
for test in tests/test_str*.ml tests/test_string*.ml; do
    [ -f "$test" ] && run_test "$test"
done
echo ""

echo -e "${BLUE}[4] Tableaux et Paramètres${NC}"
for test in tests/test_array*.ml tests/test_reference.ml; do
    [ -f "$test" ] && run_test "$test"
done
echo ""

echo -e "${BLUE}[5] Opérations Spéciales${NC}"
for test in tests/test_div*.ml tests/test_mod*.ml tests/test_empty*.ml; do
    [ -f "$test" ] && run_test "$test"
done
echo ""

echo -e "${BLUE}[6] Tests Complets et Démos${NC}"
for test in tests/test_complete*.ml tests/test_all*.ml tests/demo*.ml; do
    [ -f "$test" ] && run_test "$test"
done
echo ""

echo -e "${BLUE}[7] Autres Tests${NC}"
# Tous les tests qui n'ont pas été couverts
shopt -s nullglob
covered_patterns="test_basic test_critical test_str test_string test_array test_reference test_div test_mod test_empty test_complete test_all demo"
for test in tests/*.ml; do
    test_name=$(basename "$test")
    skip=0
    for pattern in $covered_patterns; do
        if [[ $test_name == ${pattern}* ]]; then
            skip=1
            break
        fi
    done
    if [ $skip -eq 0 ]; then
        run_test "$test"
    fi
done
echo ""

# Résumé
echo -e "${CYAN}════════════════════════════════════════════════════════${NC}"
echo -e "${CYAN}   📊 Résumé${NC}"
echo -e "${CYAN}════════════════════════════════════════════════════════${NC}"
echo -e "Total:   $TOTAL tests"
echo -e "${GREEN}Réussis: $PASSED${NC}"
if [ $FAILED -gt 0 ]; then
    echo -e "${RED}Échoués: $FAILED${NC}"
fi
if [ $SKIPPED -gt 0 ]; then
    echo -e "${YELLOW}Ignorés: $SKIPPED${NC}"
fi
echo ""

if [ $TOTAL -gt 0 ]; then
    SUCCESS_RATE=$((PASSED * 100 / TOTAL))
    echo -e "Taux de réussite: ${GREEN}${SUCCESS_RATE}%${NC}"
    echo ""
    
    if [ $SUCCESS_RATE -eq 100 ]; then
        echo -e "${GREEN}✓ TOUS LES TESTS PASSENT !${NC} 🎉"
        exit 0
    elif [ $SUCCESS_RATE -ge 90 ]; then
        echo -e "${YELLOW}⚠ Quelques tests échouent${NC}"
        exit 1
    else
        echo -e "${RED}✗ Plusieurs tests échouent${NC}"
        exit 1
    fi
else
    echo -e "${YELLOW}Aucun test trouvé${NC}"
    exit 1
fi
