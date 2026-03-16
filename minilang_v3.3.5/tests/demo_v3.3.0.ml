// Démonstration MiniLang v3.3.0

print("=== MINILANG v3.3.0 - DEMO ===");

// 1. Opérateurs composés
print("--- Operateurs composes ---");
int score = 100;
print("Score initial: " + score);

score += 50;
print("Apres bonus (+50): " + score);

score -= 30;
print("Apres malus (-30): " + score);

score *= 2;
print("Double points (*2): " + score);

score /= 4;
print("Division par 4: " + score);

// 2. Comparaison de chaînes
print("--- Comparaison de chaines ---");
str motDePasse = "secret123";
str tentative = input("Entrez le mot de passe: ");

if (tentative == motDePasse) {
    print("Acces autorise !");
} else {
    print("Acces refuse !");
}

// 3. Programme interactif complet
print("--- Mini Quiz ---");
str nom = input("Votre nom: ");
print("Bonjour " + nom + " !");

int points = 0;

print("Question 1: Combien font 5 + 3?");
int rep1 = input("Reponse: ");
if (rep1 == 8) {
    print("Correct!");
    points += 10;
} else {
    print("Faux!");
}

print("Question 2: Quelle est la capitale de la France?");
str rep2 = input("Reponse: ");
if (rep2 == "Paris") {
    print("Correct!");
    points += 10;
} else {
    print("Faux! C'etait Paris");
}

print("--- Resultats ---");
print("Joueur: " + nom);
print("Score: " + points + " / 20");

if (points >= 15) {
    print("Excellent!");
} else if (points >= 10) {
    print("Pas mal!");
} else {
    print("Retentez votre chance!");
}

print("=== FIN DEMO ===");
