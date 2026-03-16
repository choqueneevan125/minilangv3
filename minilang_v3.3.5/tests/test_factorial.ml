// Factorielle avec fonction

print("=== FACTORIELLE ===");

func int factorielle(int n) {
    if (n <= 1) {
        return 1;
    }
    
    int result = 1;
    for (int i = 2; i <= n; i = i + 1) {
        result = result * i;
    }
    return result;
}

print("Factorielle de 5:");
print(factorielle(5));

print("Factorielle de 6:");
print(factorielle(6));

print("Factorielle de 7:");
print(factorielle(7));

print("Factorielle de 10:");
print(factorielle(10));

// Calculer plusieurs factorielles
for (int i = 1; i <= 10; i = i + 1) {
    print(factorielle(i));
}
