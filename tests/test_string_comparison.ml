// Test comparaison de chaînes - v3.3.0

print("=== TEST COMPARAISON CHAÎNES ===");

str nom1 = "Alice";
str nom2 = "Bob";
str nom3 = "Alice";

// Test égalité
print("Alice == Alice:");
print(nom1 == nom3);  // true (1)

print("Alice == Bob:");
print(nom1 == nom2);  // false (0)

// Test différence
print("Alice != Bob:");
print(nom1 != nom2);  // true (1)

// Test ordre alphabétique
print("Alice < Bob:");
print(nom1 < nom2);  // true (1)

print("Bob > Alice:");
print(nom2 > nom1);  // true (1)

// Test avec conditions
if (nom1 == "Alice") {
    print("Le nom est Alice");
}

if (nom2 != "Alice") {
    print("Le nom n'est pas Alice");
}

// Validation de mot de passe
str password = input("Mot de passe: ");
if (password == "secret123") {
    print("Accès autorisé!");
} else {
    print("Accès refusé!");
}

print("=== FIN TEST ===");
