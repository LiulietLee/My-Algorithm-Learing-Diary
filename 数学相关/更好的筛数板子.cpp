#define MAXN 100000000
#define MAXND 10000000 // MAXND = MAXN / 10

bool isPrime[MAXN + 1];
int prime[MAXND];

void init() {
    int counter = 1;
    for (int i = 3; i <= MAXN; i += 2) {
        isPrime[i] = true;
    }
    isPrime[2] = true;
    prime[0] = 2;
    for (int i = 3; i <= MAXN; i += 2) {
        if (isPrime[i]) {
            prime[counter++] = i;
        }
        for (int j = 1; i * prime[j] <= MAXN && j < counter; j++) {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    } 
}