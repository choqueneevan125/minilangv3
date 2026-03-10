// Fibonacci avec fonction

print("=== FIBONACCI AVEC FONCTION ===");

func int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    
    int a = 0;
    int b = 1;
    int temp = 0;
    
    for (int i = 2; i <= n; i = i + 1) {
        temp = a + b;
        a = b;
        b = temp;
    }
    
    return b;
}

print("Les 15 premiers nombres de Fibonacci:");
for (int i = 0; i < 15; i = i + 1) {
    print(fibonacci(i));
}

print("Fibonacci(20):");
print(fibonacci(20));
