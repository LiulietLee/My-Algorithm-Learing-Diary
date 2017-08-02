//
//  main.cpp
//  DP_1
//
//  Created by Liuliet.Lee on 2/8/2017.
//  Copyright © 2017 Liuliet.Lee. All rights reserved.
//

#include <iostream>
#define maxN 100
#define maxW 10000

int ws[maxN], vs[maxN];
int dp[maxN][maxW];

int main(int argc, const char * argv[]) {
    int n, w;
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ws[i], &vs[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j < ws[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = std::max(dp[i][j], dp[i][j - ws[i]] + vs[i]);
            }
        }
    }
    
    printf("%d", dp[n][w]);
    
    return 0;
}
