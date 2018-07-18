#define MAX 1001

int main() {
    int inf = MAX, nodeCount, lineCount, x, y, s;
    int map[MAX][MAX];
    
    for (int i = 0; i < MAX; i++) {
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
    
    // Floyd-Warshall START
    for (int k = 0; k < nodeCount; k++)
        for (int i = 0; i < nodeCount; i++)
            for (int j = 0; j < nodeCount; j++)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
    // END
    
    for (int i = 0; i < nodeCount; i++)
        for (int j = 0; j < nodeCount; j++) {
            printf("%d -> %d: ", i, j);
            if (map[i][j] >= inf) printf("can not reach\n");
            else printf("%d\n", map[i][j]);
        }
    
    return 0;
}

/*
 
 求多源最短路径
 运行时间：O(n^3)
 
 无法解决负权环
 
 Example:
 
 Input:
 3 4
 0 1 1
 1 2 2
 2 0 3
 0 2 2
 
 Output:
 0 -> 0: 0
 0 -> 1: 1
 0 -> 2: 2
 1 -> 0: 5
 1 -> 1: 0
 1 -> 2: 2
 2 -> 0: 3
 2 -> 1: 4
 2 -> 2: 0
 Program ended with exit code: 0
 
 */
