vector<int> pa, si; // parents, size of set

void init(int n) {
    pa = vector<int>(n);
    iota(pa.begin(), pa.end(), 0);
    si = vector<int>(n, 1);
}

int find(int x) {
    if (pa[x] == x) {
        return x;
    } else {
        return pa[x] = find(pa[x]);
    }
}

// 如果 x y 已经在同一集合则返回 true，否则合并并返回 false
bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return true;
    } else {
        pa[y] = x;
        si[x] += si[y];
    }
    return false;
}
