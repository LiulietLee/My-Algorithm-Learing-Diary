int d[MAXN], counter[MAXN];
int n;

bool erdos_gallai() {
    memset(counter, 0, sizeof(counter));
    for (int i = 0; i < n; i++) counter[d[i]]++;
    
    int remaining = 0, i = 0, cur;
    ll left = 0, right = 0;
    for (int k = 0; k < n; k++) {
        cur = d[i++];
        left += cur;
        counter[cur]--;

        remaining += counter[k];
        right += n - k - remaining - min(cur, k);

        if (left > (ll)k * (k + 1) + right) {
            return false;
        }
    }

    return true;
}

