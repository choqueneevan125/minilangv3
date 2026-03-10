// Test du type bool - v3.2.0

print("=== TYPE BOOL ===");

// Déclaration de bool
bool actif = true;
bool termine = false;

print("actif:");
print(actif);
print("termine:");
print(termine);

// Bool dans conditions
if (actif) {
    print("Système actif");
}

if (!termine) {
    print("Non terminé");
}

// Fonction retournant bool
func bool estPair(int n) {
    if (n % 2 == 0) {
        return true;
    }
    return false;
}

print("5 est pair?");
print(estPair(5));
print("10 est pair?");
print(estPair(10));

// Fonction avec paramètre bool
func void afficherEtat(bool etat) {
    if (etat) {
        print("ON");
    } else {
        print("OFF");
    }
}

afficherEtat(true);
afficherEtat(false);

// Opérations logiques
bool a = true;
bool b = false;

print("true && false:");
print(a && b);
print("true || false:");
print(a || b);
print("!true:");
print(!a);

print("=== FIN TEST BOOL ===");
