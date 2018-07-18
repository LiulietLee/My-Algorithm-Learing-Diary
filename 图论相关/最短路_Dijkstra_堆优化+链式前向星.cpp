#define MAXVERTEX 1010
#define MAXEDGE 10010
#define INF 999999999

struct Node {
	int next, to, w;
} edge[MAXEDGE];

int head[MAXVERTEX], dis[MAXVERTEX], vis[MAXVERTEX];
int cur, edges, vertices;

void init() {
	cur = 0;
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));
}

void add(int u, int v, int w) {
	edge[cur] = Node{head[u], v, w};
	head[u] = cur++;
}

int dijkstra(int begin, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;

	for (int i = 1; i <= vertices; i++) {
		dis[i] = INF;
		vis[i] = 0;
	}

	dis[begin] = 0;
	heap.push(make_pair(dis[begin], begin));

	while (!heap.empty()) {
		int u = heap.top().second;
		heap.pop();

		if (vis[u]) continue;
		vis[u] = 1;

		for (int i = head[u]; ~i; i = edge[i].next) {
			int v = edge[i].to;
			int w = edge[i].w;
			if (!vis[v]) {
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					heap.push(make_pair(dis[v], v));
				}
			}
		}
	}

	return dis[end];
}