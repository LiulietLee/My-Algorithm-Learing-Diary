bool isPrime[35000];

void initPrime(int n) {
    for (int i = 2; i < n; i++) {
        isPrime[i] = true;
    }
    
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}