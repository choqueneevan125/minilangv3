// Test méthodes sur chaînes - v3.3.0

print("=== TEST MÉTHODES CHAÎNES ===");

str texte = "Bonjour MiniLang";

// Test .length()
print("Texte: Bonjour MiniLang");
int len = texte.length();
print("Longueur:");
print(len);  // 16

// Test .substring()
print("Substring(0, 7):");
str partie1 = texte.substring(0, 7);
print(partie1);  // Bonjour

print("Substring(8, 16):");
str partie2 = texte.substring(8, 16);
print(partie2);  // MiniLang

// Utilisation dans conditions
if (texte.length() > 10) {
    print("Texte long");
}

// Extraire premiers caractères
str nom = "Alexandre";
print("Nom: Alexandre");
str initiale = nom.substring(0, 1);
print("Initiale:");
print(initiale);  // A

// Longueur de chaîne vide
str vide = "";
print("Chaîne vide - longueur:");
print(vide.length());  // 0

print("=== FIN TEST ===");
