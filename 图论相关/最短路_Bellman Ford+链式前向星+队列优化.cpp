#define MAXVERTEX 100
#define MAXEDGE 100
#define INF 99999999

struct node {
    int next, int to, int w;
    node(int next = 0, int to = 0, int w = 0):
    next(next), to(to), w(w) {}
} edge[MAXEDGE];

int head[MAXVERTEX + 1], dis[MAXVERTEX + 1], vis[MAXVERTEX + 1];
int vertics, edges, cur;

void init() {
    cur = 0;
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void add(int u, int v, int w) {
    edge[cur] = node(head[u], v, w);
    head[u] = cur++;
}

int bellman(int start, int end) {
    queue<int> que;
    int current, counter[MAXVERTEX + 1];

    memset(counter, 0, sizeof(counter));
    for (int i = 1; i <= vertics; i++) {
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[start] = 0;
    que.push(start);
    counter[start]++;

    while (!que.empty()) {
        current = que.front();
        que.pop();
        vis[current] = 1;

        for (int i = head[current]; ~i; i = edge[i].next) {
            if (dis[edge[i].to] > dis[current] + edge[i].w) {
                dis[edge[i].to] = dis[current] + edge[i].w;

                if (vis[edge[i].to]) continue;
                vis[edge[i].to] = 1;

                que.push(edge[i].to);
                counter[edge[i].to]++;

                if (counter[edge[i].to] > vertics) {
                    printf("have negative circle!\n");
                    return dis[end];
                }
            }
        }
    }

    return dis[end];
}