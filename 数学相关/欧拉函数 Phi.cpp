int phi[MAXN];

// get nth phi
int getPhi(int n) {
    int m = (int)sqrt(n + 0.5);
    ll ans = n;
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

void initPhi() {
    phi[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
