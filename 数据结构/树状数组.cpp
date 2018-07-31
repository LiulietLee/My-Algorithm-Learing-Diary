int a[MAXN], bit[MAXN];
int n;

int lowbit(int x) {
    return x&-x;
}

void build() {
    for (int i = 1; i <= n; i++) {
        bit[i] = a[i - 1];
        for (int j = i - 2; j >= i - lowbit(i); j--) {
            bit[i] += a[j];
        }
    }
}

void edit(int idx, int x) {
    for (int i = idx; i <= n; i += lowbit(i)) {
        bit[i] += x;
    }
}

int sum(int k) {
    int ans = 0;
    for (int i = k; i > 0; i -= lowbit(i)) {
        ans += bit[i];
    }
    return ans;
}

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    build();

    /// об╠Й -> [1, n]
    edit(2, 2);
    for (int i = 1; i <= n; i++) {
        printf("%d ", sum(i));
    }

    return 0;
}
