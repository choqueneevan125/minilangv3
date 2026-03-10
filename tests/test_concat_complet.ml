// Test complet de concaténation - v3.2.2

print("=== TEST CONCATENATION COMPLETE ===");

// Test 1: Simple
str nom = "Alice";
print("Bonjour " + nom);

// Test 2: Avec int
int age = 25;
print(nom + " a " + age + " ans");

// Test 3: Avec float
float prix = 19.99;
print("Prix: " + prix + " euros");

// Test 4: Multiples
int a = 10;
int b = 5;
print(a + " + " + b + " = " + (a + b));
print(a + " - " + b + " = " + (a - b));
print(a + " * " + b + " = " + (a * b));

// Test 5: Avec bool
bool actif = true;
print("Actif: " + actif);

// Test 6: Expression dans concaténation
print("Résultat: " + (3 + 4 * 2));

print("=== FIN TEST ===");
