// Test 4 : Utiliser le tableau retourné
func int[] fibonacci(int n) {
    int tab[10];
    tab[0] = 0;
    tab[1] = 1;
    
    for (int i = 2; i < n; i += 1) {
        tab[i] = tab[i-1] + tab[i-2];
    }
    
    return tab;
}

int[] fib = fibonacci(10);
print("Suite de Fibonacci:");
for (int i = 0; i < 10; i += 1) {
    print(fib[i]);
}
