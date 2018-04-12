#define MAXEDGE 5000
#define MAXVERTEX 500
typedef long long ll;
using namespace std;

int num[MAXVERTEX], low[MAXVERTEX];
int vertics, edges, root, idx;
vector<int> impor, edge[MAXVERTEX];

void add(int u, int v) {
    edge[u].push_back(v);
    edge[v].push_back(u);
}

void dfs(int cur, int fa) {
    int children = 0;
    
    idx++;
    num[cur] = idx;
    low[cur] = idx;
    for (int i = 0; i < edge[cur].size(); i++) {
        int u = edge[cur][i];
        if (num[u] == 0) {
            children++;
            dfs(u, cur);
            low[cur] = min(low[cur], low[u]);
            if (cur != root && low[u] >= num[cur]) {
                impor.push_back(cur);
            }
            if (cur == root && children == 2) {
                impor.push_back(cur);
            }
        } else if (u != fa) {
            low[cur] = min(low[cur], num[u]);
        }
    }
}

int main() {
    int u, v;
    
    cin >> vertics >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        add(u, v);
    }
    
    root = 1;
    dfs(1, root);
    
    for (auto i = impor.begin(); i != impor.end(); i++) {
        cout << *i << endl;
    }
    
    return 0;
}
