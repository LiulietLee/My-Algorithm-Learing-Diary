#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <cstring>
#include <algorithm>
#define MAXSIZE 10010
#define MAXN 20
#define MAXND MAXN / 10
#define MAXVERTEX 100010
#define MAXEDGE 3000010
#define INF 99999999
#define nil NULL
typedef long long ll;
using namespace std;

int vertics, edges;
int deg[MAXVERTEX], removed[MAXVERTEX];
vector<int> mp[MAXVERTEX];

void add(int u, int v) {
    mp[u].push_back(v);
}

bool checkCircle() {
    for (int counter = 0; counter < vertics - 1; counter++) {
        memset(deg, 0, sizeof(deg));
        for (int i = 1; i <= vertics; i++) {
            if (removed[i]) continue;
            for (int j = 0; j < mp[i].size(); j++) {
                int u = mp[i][j];
                if (!removed[u]) {
                    deg[u]++;
                }
            }
        }

        bool hasCircle = true;
        for (int i = 1; i <= vertics; i++) {
            if (!removed[i] && deg[i] == 0) {
                removed[i] = 1;
                hasCircle = false;
                break;
            }
        }

        if (hasCircle) {
            return true;
        }
    }

    return false;
}

int main() {
    int u, v;
    cin >> vertics >> edges;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        add(u, v);
    }

    if (checkCircle()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
