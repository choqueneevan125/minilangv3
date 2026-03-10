// Test input() - v3.2.0
// À tester interactivement

print("=== TEST INPUT ===");

str nom = input("Entrez votre nom: ");
print("Bonjour " + nom);

int age = input("Entrez votre âge: ");
print("Vous avez " + age + " ans");

// Test avec bool
print("Actif? (true/false): ");
bool actif = input();
if (actif) {
    print("Système activé");
} else {
    print("Système désactivé");
}

// Calcul interactif
int a = input("Premier nombre: ");
int b = input("Deuxième nombre: ");
int somme = a + b;
print(a + " + " + b + " = " + somme);

print("=== FIN TEST INPUT ===");
