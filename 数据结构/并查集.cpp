int parents[MAXN];

void init() {
    for (int i = 1; i < MAXN; i++) {
        parents[i] = i;
    }
}

int find(int x) {
    if (parents[x] == x) {
        return x;
    } else {
        return parents[x] = find(parents[x]);
    }
}

// 如果 x y 已经在同一集合则返回 true，否则合并并返回 false
bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return true;
    } else {
        parents[y] = x;
    }
    return false;
}
