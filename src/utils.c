#include "../include/minilang.h"

// Afficher une erreur avec le numéro de ligne
void print_error(const char *message, int line) {
    fprintf(stderr, "Erreur ligne %d: %s\n", line, message);
}
