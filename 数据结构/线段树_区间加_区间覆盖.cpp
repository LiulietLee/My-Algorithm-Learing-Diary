struct node {
    int l, r;
    int setv, addv, min, max, sum;

    void updateadd(int v) {
        addv += v;
        sum += (r - l + 1) * v;
        max += v;
        min += v;
    }
    void updateset(int v) {
        sum = (r - l + 1) * v;
        addv = 0;
        max = min = setv = v;
    }
} t[MAXN<<2];

void pushup(int p) {
    t[p].sum = t[p<<1].sum + t[p<<1|1].sum;
    t[p].max = max(t[p<<1].max, t[p<<1|1].max);
    t[p].min = min(t[p<<1].min, t[p<<1|1].min);
}

void pushdown(int p) {
    int &setv = t[p].setv, &addv = t[p].addv;
    if (setv) {
        t[p<<1].updateset(setv);
        t[p<<1|1].updateset(setv);
        setv = 0;
    }
    if (addv) {
        t[p<<1].updateadd(addv);
        t[p<<1|1].updateadd(addv);
        addv = 0;
    }
}

void build(int p, int l, int r) {
    t[p].l = l; t[p].r = r;
    if (l != r) {
        int mid = (l + r) / 2;
        build(p<<1, l, mid);
        build(p<<1|1, mid + 1, r);
    }
}

void addval(int p, int l, int r, int v) {
    if (l <= t[p].l && t[p].r <= r) t[p].updateadd(v);
    else {
        pushdown(p);
        int mid = (t[p].l + t[p].r) / 2;
        if (l <= mid) addval(p<<1, l, r, v);
        if (mid < r) addval(p<<1|1, l, r, v);
        pushup(p);
    }
}

void setval(int p, int l, int r, int v) {
    if (l <= t[p].l && t[p].r <= r) t[p].updateset(v);
    else {
        pushdown(p);
        int mid = (t[p].l + t[p].r) / 2;
        if (l <= mid) setval(p<<1, l, r, v);
        if (mid < r) setval(p<<1|1, l, r, v);
        pushup(p);
    }
}

struct strans {
    int sum, max, min;
};

strans getans(int p, int l, int r) {
    if (l <= t[p].l && t[p].r <= r) return strans {
        t[p].sum, t[p].max, t[p].min
    };
    pushdown(p);
    int mid = (t[p].l + t[p].r) / 2;
    strans ans;
    int sum = 0, ma = -INF, mi = INF;
    if (l <= mid) {
        ans = getans(p<<1, l, r);
        sum += ans.sum;
        ma = max(ans.max, ma);
        mi = min(ans.min, mi);
    }
    if (mid < r) {
        ans = getans(p<<1|1, l, r);
        sum += ans.sum;
        ma = max(ans.max, ma);
        mi = min(ans.min, mi);
    }
    ans = strans {sum, ma, mi};
    return ans;
}
