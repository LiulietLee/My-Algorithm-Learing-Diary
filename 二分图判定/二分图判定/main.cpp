//
//  main.cpp
//  二分图判定
//
//  Created by Liuliet.Lee on 27/8/2017.
//  Copyright © 2017 Liuliet.Lee. All rights reserved.
//

#include <iostream>
#define _max 100
using namespace std;

int matrix[_max][_max];
int color[_max];

int main(int argc, const char * argv[]) {
    int n, a, b;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    color[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || matrix[i][j] == 0) { continue; }
            else if (color[i] == color[j]) {
                printf("no\n");
                return 0;
            } else if (color[j] == 0) {
                if (color[i] == 2) { color[j] = 1; }
                else { color[j] = 2; }
            }
        }
    }
    
    printf("yes\n");
    
    return 0;
}



/*
 
 input:
 4
 0 1
 0 3
 2 1
 2 3
 
 output:
 yes
 
 */



