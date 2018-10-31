// r == root
int n, m, r, mod;

int w[MAXN], wt[MAXN];
int son[MAXN], id[MAXN], fa[MAXN], dep[MAXN], siz[MAXN], top[MAXN];
int cnt, res;

/// MARK: - store edges

struct Edge {
    int next, to;
} edge[MAXN<<1];

int head[MAXN], cur;

void initedge() {
    cur = 0;
    memset(head, -1, sizeof(head));
    memset(edge, 0, sizeof(edge));
}

void addedge(int u, int v) {
    edge[cur] = Edge{head[u], v};
    head[u] = cur++;
}

/// MARK: - segment tree

struct node {
    int l, r;
    ll sum, lazy;

    node() = default;
    void update(int x) {
        sum += (ll)(r - l + 1) * x;
        sum %= mod;
        lazy += x;
        lazy %= mod;
    }
} t[MAXN << 2];

void pushup(int p) {
    t[p].sum = (t[p<<1].sum + t[p<<1|1].sum) % mod;
}

void pushdown(int p) {
    int lazyv = t[p].lazy;
    if (lazyv) {
        t[p].lazy = 0;
        t[p<<1].update(lazyv);
        t[p<<1|1].update(lazyv);
    }
}

void build(int p, int l, int r) {
    t[p].l = l; t[p].r = r;
    if (l == r) {
        t[p].sum = wt[l];
    } else {
        int mid = (l + r) / 2;
        build(p<<1, l, mid);
        build(p<<1|1, mid + 1, r);
        pushup(p);
    }
}

void addval(int p, int l, int r, int val) {
    if (l <= t[p].l && t[p].r <= r) t[p].update(val);
    else {
        pushdown(p);
        int mid = (t[p].l + t[p].r) / 2;
        if (l <= mid) addval(p<<1, l, r, val);
        if (mid < r) addval(p<<1|1, l, r, val);
        pushup(p);
    }
}

void getsum(int p, int l, int r) {
    if (l <= t[p].l && t[p].r <= r) res = (res + t[p].sum) % mod;
    else {
        pushdown(p);
        int mid = (t[p].l + t[p].r) / 2;
        if (l <= mid) getsum(p<<1, l, r);
        if (mid < r) getsum(p<<1|1, l, r);
    }
}

/// MARK: - heavy path decomposition

void dfs1(int x, int f, int d) {
    dep[x] = d;
    fa[x] = f;
    siz[x] = 1;
    int maxson = -1;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int y = edge[i].to;
        if (y == f) continue;
        dfs1(y, x, d + 1);
        siz[x] += siz[y];
        if (siz[y] > maxson)
            son[x] = y, maxson = siz[y];
    }
}

void dfs2(int x, int t) {
    id[x] = ++cnt;
    wt[cnt] = w[x];
    top[x] = t;
    if (!son[x]) return;
    dfs2(son[x], t);
    for (int i = head[x]; ~i; i = edge[i].next) {
        int y = edge[i].to;
        if (y == fa[x] || y == son[x]) continue;
        dfs2(y, y);
    }
}

int querypath(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        res = 0;
        getsum(1, id[top[x]], id[x]);
        ans += res;
        ans %= mod;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    res = 0;
    getsum(1, id[x], id[y]);
    ans += res;
    return ans % mod;
}

void updatepath(int x, int y, int k) {
    k %= mod;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        addval(1, id[top[x]], id[x], k);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    addval(1, id[x], id[y], k);
}

int querysubtree(int x) {
    res = 0;
    getsum(1, id[x], id[x] + siz[x] - 1);
    return res;
}

void updatesubtree(int x, int k) {
    addval(1, id[x], id[x] + siz[x] - 1, k);
}

int main() {
    // Luogu P3384
    int a, b, k, x, y, z;
    initedge();
    scanf("%d%d%d%d", &n, &m, &r, &mod);
    for (int i = 1; i <= n; i++) scanf("%d", w + i);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    dfs1(r, 0, 1);
    dfs2(r, r);
    build(1, 1, n);
    while (m--) {
        scanf("%d", &k);
        switch (k) {
        case 1:
            scanf("%d%d%d", &x, &y, &z);
            updatepath(x, y, z);
            break;
        case 2:
            scanf("%d%d", &x, &y);
            printf("%d\n", querypath(x, y));
            break;
        case 3:
            scanf("%d%d", &x, &z);
            updatesubtree(x, z);
            break;
        default: // 4
            scanf("%d", &x);
            printf("%d\n", querysubtree(x));
            break;
        }
    }

    return 0;
}
