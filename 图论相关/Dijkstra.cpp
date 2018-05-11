#include <iostream>
#define MAX 1001
using namespace std;

int main() {
    int inf = MAX, nodeCount, lineCount, x, y, s, point, u = 0, minimum;
    int map[MAX][MAX], dis[MAX];
    bool book[MAX];
    
    for (int i = 0; i < MAX; i++) {
        book[i] = false;
        for (int j = 0; j < MAX; j++) {
            if (i == j) map[i][j] = 0;
            else map[i][j] = inf;
        }
    }
    
    scanf("%d%d", &nodeCount, &lineCount);
    for (int i = 0; i < lineCount; i++) {
        scanf("%d%d%d", &x, &y, &s);
        map[x][y] = s;
    }
    scanf("%d", &point);
    
    // Dijkstra START
    for (int i = 0; i < nodeCount; i++) {
        dis[i] = map[point][i];
    }
    
    book[point] = true;
    
    for (int i = 0; i < nodeCount; i++) {
        minimum = inf;
        for (int j = 0; j < nodeCount; j++) {
            if (!book[j] && dis[j] < minimum) {
                minimum = dis[j];
                u = j;
            }
        }
        book[u] = true;
        for (int j = 0; j < nodeCount; j++)
            if (map[u][j] < inf)
                dis[j] = min(dis[j], dis[u] + map[u][j]);
    }
    // END
    
    for (int i = 0; i < nodeCount; i++) {
        printf("%d -> %d: ", point, i);
        if (dis[i] >= inf) printf("can not reach\n");
        else printf("%d\n", dis[i]);
    }
    
    return 0;
}

/*

求单源最短路径
运行时间：O(n^2) // 用堆和邻接表优化可以降至 O(m+N)logN

Example:

Input:
3 4
0 1 1
1 2 2
2 0 3
0 2 2
1

Output:
1 -> 0: 5
1 -> 1: 0
1 -> 2: 2
Program ended with exit code: 0

*/