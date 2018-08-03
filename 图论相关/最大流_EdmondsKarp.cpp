#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 20010
#define MAXVERTEX 10010
#define MAXEDGE 110
#define INF 999999999
typedef long long ll;
using namespace std;

struct Edge {
    int from, to, cap, flow;

    Edge(int u = 0, int v = 0, int c = 0, int f = 0):
    from(u), to(v), cap(c), flow(f) {}
};

int a[MAXVERTEX], p[MAXVERTEX];
int vertices, edges;
vector<Edge> edge;
vector<int> g[MAXVERTEX];

void init(int n) {
    for (int i = 0; i < vertices; i++) 
        g[i].clear();
    edge.clear();
}

void add(int u, int v, int c) {
    edge.push_back(Edge(u, v, c, 0));
    edge.push_back(Edge(v, u, 0, 0));
    edges = edge.size();
    g[u].push_back(edges - 2);
    g[v].push_back(edges - 1);
}

int maxflow(int s, int t) {
    int flow = 0;
    while (1) {
        memset(a, 0, sizeof(a));
        queue<int> q;
        q.push(s);
        a[s] = INF;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < g[x].size(); i++) {
                Edge& e = edge[g[x][i]];
                if (!a[e.to] && e.cap > e.flow) {
                    p[e.to] = g[x][i];
                    a[e.to] = min(a[x], e.cap - e.flow);
                    q.push(e.to);
                }
            }
            if (a[t]) break;
        }
        if (!a[t]) break;
        for (int u = t; u != s; u = edge[p[u]].from) {
            edge[p[u]].flow += a[t];
            edge[p[u]^1].flow -= a[t];
        }
        flow += a[t];
    }
    return flow;
}

int main() {
    int e, s, t, u, v, c;

    scanf("%d%d%d%d", &vertices, &e, &s, &t);
    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
    }
    printf("%d\n", maxflow(s, t));

    return 0;
}
