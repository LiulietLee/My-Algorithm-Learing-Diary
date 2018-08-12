#define INF 999999999
#define MAXN 100010
typedef long long ll;

// [1, n]
int a[MAXN];

struct Node {
    int l, r;
    ll max, sum, lazy; // 维护区间最大值和区间和

    Node() {
        this->l = this->r = this->lazy = 
        this->max = this->sum = 0;
    }

    void update(int x) {
        sum += (ll)(r - l + 1) * x;
        max += x;
        lazy += x;
    }
} t[MAXN << 2];

void pushUp(int p) {
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
    t[p].max = max(t[p << 1].max, t[p << 1 | 1].max);
}

void pushDown(int p) {
    int lazyVal = t[p].lazy;
    if (lazyVal) {
        t[p].lazy = 0;
        t[p << 1].update(lazyVal);
        t[p << 1 | 1].update(lazyVal);
    }
}

// build(1, 1, n);
void build(int p, int l, int r) {
    t[p].l = l; t[p].r = r;
    if (l == r) {
        t[p].sum = t[p].max = a[l];
    } else {
        int mid = (l + r) / 2;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        pushUp(p);
    }
}

// addVal(1, l, r, val);
void addVal(int p, int l, int r, int val) {
    if (l <= t[p].l && t[p].r <= r) {
        t[p].update(val);
    } else {
        pushDown(p);
        int mid = (t[p].l + t[p].r) / 2;
        if (l <= mid) addVal(p << 1, l, r, val); 
        if (mid < r) addVal(p << 1 | 1, l, r, val);
        pushUp(p);
    }
}

// int sum = getSum(1, l, r);
ll getSum(int p, int l, int r) {
    if (l <= t[p].l && t[p].r <= r) {
        return t[p].sum;
    } else {
        pushDown(p);
        ll ans = 0;
        int mid = (t[p].l + t[p].r) / 2;
        if (l <= mid) ans += getSum(p << 1, l, r);
        if (mid < r) ans += getSum(p << 1 | 1, l, r);
        pushUp(p);
        return ans;
    }
}

// int maxv = getMax(1, l, r);
ll getMax(int p, int l, int r) {
    if (l <= t[p].l && t[p].r <= r) {
        return t[p].max;
    } else {
        pushDown(p);
        ll ans = -INF;
        int mid = (t[p].l + t[p].r) / 2;
        if (l <= mid) ans = max(ans, getMax(p << 1, l, r));
        if (mid < r) ans = max(ans, getMax(p << 1 | 1, l, r));
        pushUp(p);
        return ans;
    }
}

int main() {
    int n, m, op, l, r, k;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    build(1, 1, n);
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &l, &r, &k);
            addVal(1, l, r, k);
        } else {
            scanf("%d%d", &l, &r);
            printf("%lld %lld\n", getSum(1, l, r), getMax(1, l, r));
        }
    }

    return 0;
}
