#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXVERTEX 5010
#define MAXEDGE 200010
#define INF 999999999
using namespace std;

struct Edge {
    int from, to, w;

    Edge(int from = 0, int to = 0, int w = 0):
    from(from), to(to), w(w) {}

    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
} edge[MAXEDGE];

int parents[MAXVERTEX];
int vertices, edges;

void init() {
    for (int i = 1; i < MAXVERTEX; i++) {
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

int kruskal() {
    init();
    sort(edge, edge + edges);
    int ans = 0, counter = 1;
    for (int i = 0; i < edges; i++) {
        if (unite(edge[i].from, edge[i].to)) {
            continue;
        } else {
            ans += edge[i].w;
            counter++;
        }
        if (counter >= vertices) {
            break;
        }
    }
    if (counter >= vertices) {
        return ans;
    } else {
        return -1;
    }
}

int main() {
    int u, v, w;

    scanf("%d%d", &vertices, &edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edge[i] = Edge(u, v, w);
    }

    int ans = kruskal();
    if (ans == -1) {
        printf("orz\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}