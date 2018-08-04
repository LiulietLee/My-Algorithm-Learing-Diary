struct Edge {
    int from, to, cap, flow;
    ll cost;

    Edge(int u = 0, int v = 0, int c = 0, int f = 0, ll cost = 0):
    from(u), to(v), cap(c), flow(f), cost(cost) {}
};

int vertices, edges;
vector<Edge> edge;
vector<int> g[MAXVERTEX];
int inq[MAXVERTEX], d[MAXVERTEX], p[MAXVERTEX], a[MAXVERTEX];

void init(int n) {
    vertices = n;
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
    edge.clear();
}

void add(int from, int to, int cap, ll cost) {
    edge.push_back(Edge(from, to, cap, 0, cost));
    edge.push_back(Edge(to, from, 0, 0, -cost));
    edges = edge.size();
    g[from].push_back(edges - 2);
    g[to].push_back(edges - 1);
}

bool bellmanFord(int s, int t, int& flow, ll& cost) {
    for (int i = 0; i < vertices; i++) d[i] = INF;
    memset(inq, 0, sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;

    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = 0; i < g[u].size(); i++) {
            Edge& e = edge[g[u][i]];
            if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost;
                p[e.to] = g[u][i];
                a[e.to] = min(a[u], e.cap - e.flow);
                if (!inq[e.to]) {
                    q.push(e.to);
                    inq[e.to] = 1;
                }
            }
        }
    }
    if (d[t] == INF) return false;
    flow += a[t];
    cost += (ll)d[t] * (ll)a[t];
    for (int u = t; u != s; u = edge[p[u]].from) {
        edge[p[u]].flow += a[t];
        edge[p[u]^1].flow -= a[t];
    }
    return true;
}

void mincost_maxflow(int s, int t, ll& cost, int& maxflow) {
    maxflow = cost = 0;
    while (bellmanFord(s, t, maxflow, cost));
}

int main() {
    int e, s, t, u, v, w, mf;
    ll c, mc;

    scanf("%d%d%d%d", &vertices, &e, &s, &t);
    init(vertices);
    for (int i = 0; i < e; i++) {
        scanf("%d%d%d%lld", &u, &v, &w, &c);
        add(u - 1, v - 1, w, c);
    }
    mincost_maxflow(s - 1, t - 1, mc, mf);
    printf("%d %lld\n", mf, mc);

    return 0;
}
