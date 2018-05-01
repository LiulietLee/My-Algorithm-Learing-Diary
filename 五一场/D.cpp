#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <functional>
#include <fstream>
#define MAXSIZE 510
#define MAXN 10
#define MAXND MAXN / 10
#define INF 99999999
#define MAXEDGE 1000000
#define MAXVERTEX 510
#define EPS 0.00001
#define PI 3.14159265
#define nil NULL
typedef long long ll;
using namespace std;
 
int vertices;
vector<int> mp[MAXVERTEX * 2];
int match[MAXVERTEX * 2], vis[MAXVERTEX * 2];
 
void add(int u, int v) {
    mp[u].push_back(v);
    mp[v].push_back(u);
}
 
bool dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < mp[u].size(); i++) {
        int v = mp[u][i], w = match[v];
        if (w < 0 || (!vis[w] && dfs(w))) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}
 
int solve() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int u = 0; u < vertices; u++) {
        if (match[u] < 0) {
            memset(vis, 0, sizeof(vis));
            if (dfs(u)) {
                ans++;
            }
        }
    }
    return ans;
}
 
int main() {
    char ch;
     
    scanf("%d", &vertices);
    getchar();
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            ch = getchar();
            if (ch == '#') {
                add(i, vertices + j);
            }
        }
        ch = getchar();
    }
     
    vertices *= 2;
    int ans = solve();
     
    printf("%d\n", ans);
     
    return 0;
}