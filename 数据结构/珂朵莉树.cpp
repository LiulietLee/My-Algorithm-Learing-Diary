struct node {
    int l, r;
    mutable ll v;
    node(int l, int r = -1, ll v = 0):
    l(l), r(r), v(v) {}
    bool operator <(const node &n) const {
        return l < n.l;
    }
};

set<node> s;
ll a[MAXN];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        s.insert(node(i, i, a[i]));
    }
    s.insert(node(n + 1, n + 1, 0));
}

set<node>::iterator split(int pos) {
    set<node>::iterator it = s.lower_bound(node(pos));
    if (it != s.end() && it->l == pos) return it;
    it--;
    int l = it->l, r = it->r;
    ll v = it->v;
    s.erase(it);
    s.insert(node(l, pos - 1, v));
    return s.insert(node(pos, r, v)).first;
}

void add(int l, int r, ll val = 1) {
    set<node>::iterator itr = split(r + 1), itl = split(l);
    for (; itl != itr; itl++) itl->v += val;
}

void assign(int l, int r, ll val = 0) {
    set<node>::iterator itr = split(r + 1), itl = split(l);
    s.erase(itl, itr);
    s.insert(node(l, r, val));
}

ll getRank(int l, int r, int k) {
    vector<pair<ll, int> > v;
    v.clear();
    set<node>::iterator itr = split(r + 1), itl = split(l);
    for (; itl != itr; itl++)
        v.push_back(make_pair(itl->v, itl->r - itl->l + 1));
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        k -= v[i].second;
        if (k <= 0) return v[i].first;
    }
    return -1;
}

ll sum(int l, int r, int ex, int mod) {
    set<node>::iterator itr = split(r + 1), itl = split(l);
    ll res = 0;
    for (; itl != itr; itl++)
        res = (res + (ll)(itl->r - itl->l + 1) * powmod(itl->v, (ll)ex, (ll)mod)) % mod;
    return res;
}