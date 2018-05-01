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
#define MAXSIZE 600
#define MAXN 9999
#define MAXND MAXN / 10
#define INF 99999999
#define MAXEDGE 1000000
#define MAXVERTEX 10
#define EDGE 20
#define EPS 0.00001
#define PI 3.14159265
#define nil NULL
typedef long long ll;
using namespace std;

int n, m;
char mp[MAXSIZE][MAXSIZE], nxt[MAXSIZE][MAXSIZE];

int neighborCountAt(int row, int col) {
    int ans = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (row == i && col == j) continue;
            if (mp[i][j] == '#') ans++;
        }
    }
    return ans;
}

void evolve() {
    for (int i = 1; i < MAXSIZE - 1; i++) {
        for (int j = 1; j < MAXSIZE - 1; j++) {
            int neighbor = neighborCountAt(i, j);
            nxt[i][j] = mp[i][j];
            if (mp[i][j] == '#') {
                if (neighbor < 2 || neighbor > 3) {
                    nxt[i][j] = '.';
                }
            } else {
                if (neighbor == 3) {
                    nxt[i][j] = '#';
                }
            }
        }
    }
    
    for (int i = 1; i < MAXSIZE - 1; i++) {
        for (int j = 1; j < MAXSIZE - 1; j++) {
            mp[i][j] = nxt[i][j];
        }
    }
}

int main() {
    for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
            mp[i][j] = '.';
        }
    }
    
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[i + EDGE][j + EDGE] = getchar();
        }
        getchar();
    }
    
    for (int i = 0; i < m; i++) {
        evolve();
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", mp[i + EDGE][j + EDGE]);
        }
        printf("\n");
    }
    
    return 0;
}
