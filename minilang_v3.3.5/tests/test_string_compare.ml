// Test comparaison de chaînes

print("=== TEST COMPARAISON CHAINES ===");

str nom1 = "Alice";
str nom2 = "Alice";
str nom3 = "Bob";

print("nom1:");
print(nom1);
print("nom2:");
print(nom2);
print("nom3:");
print(nom3);

if (nom1 == nom2) {
    print("nom1 == nom2: true");
} else {
    print("nom1 == nom2: false");
}

if (nom1 == nom3) {
    print("nom1 == nom3: true");
} else {
    print("nom1 == nom3: false");
}

if (nom1 != nom3) {
    print("nom1 != nom3: true");
} else {
    print("nom1 != nom3: false");
}

// Test avec input
str reponse = input("Entrez 'oui': ");
if (reponse == "oui") {
    print("Vous avez dit oui!");
} else {
    print("Vous n'avez pas dit oui");
}

print("=== FIN TEST ===");
