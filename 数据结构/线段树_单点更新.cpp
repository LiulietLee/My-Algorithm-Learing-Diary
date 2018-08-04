#define MAXN 10010
#define INF 999999999

int a[MAXN];

struct SegTree {
    int l, r, dat;
} t[MAXN * 4];

// use: build(1, 1, n);
// build the seg tree
void build(int p, int l, int r) {
    t[p].l = l; t[p].r = r;
    if (l == r) {
        t[p].dat = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    t[p].dat = max(t[p * 2].dat, t[p * 2 + 1].dat);
}

// use: change(1, x, v);
// change the value of index x to v
void change(int p, int x, int v) {
    if (t[p].l == t[p].r) {
        t[p].dat = v;
        return;
    }
    int mid = (t[p].l + t[p].r) / 2;
    if (x <= mid) change(p * 2, x, v);
    else change(p * 2 + 1, x, v);
    t[p].dat = max(t[p * 2].dat, t[p * 2 + 1].dat);
}

// use: cout << ask(1, l, r) << endl;
// get the max value in [l, r]
int ask(int p, int l, int r) {
    if (l <= t[p].l && r >= t[p].r)
        return t[p].dat;
    int mid = (t[p].l + t[p].r) / 2;
    int val = -INF;
    if (l <= mid) val = max(val, ask(p * 2, l, r));
    if (r > mid) val = max(val, ask(p * 2 + 1, l, r));
    return val;
}
