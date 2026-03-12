// Test récursivité
func int factorielle(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorielle(n - 1);
}

int result = factorielle(5);
print("5! =");
print(result);
