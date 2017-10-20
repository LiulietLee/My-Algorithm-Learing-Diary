#include <iostream>
#define MAX 1001
using namespace std;

int dp[MAX];

int main() {
    int w[MAX], v[MAX], n, wei;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    scanf("%d", &wei);
    
    // Dynamic Programming START
    for (int i = 1; i <= n; i++) {
        for (int j = wei; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    // END
    
    printf("%d\n", dp[wei]);
    
    return 0;
}

/*

运行时间：O(n*wei)

Example:

Input:
4
2 3
1 2
3 4
2 2
5

Output:
7
Program ended with exit code: 0

*/