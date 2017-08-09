//
//  main.cpp
//  Union-find Sets
//
//  Created by Liuliet.Lee on 9/8/2017.
//  Copyright © 2017 Liuliet.Lee. All rights reserved.
//

#include <iostream>
#define max 21
using namespace std;

int main(int argc, const char * argv[]) {
    int s[max] = {0}, people, relation, n, m, count = 0;
    
    for (int i = 1; i <= max; i++) {
        s[i] = i;
    }
    
    scanf("%d%d", &people, &relation);
    for (int i = 1; i <= relation; i++) {
        scanf("%d%d", &n, &m);
        while (s[m] != m) {
            m = s[m];
        }
        while (s[n] != n) {
            n = s[n];
        }
        s[m] = n;
    }
    
    for (int i = 1; i <= people; i++) {
        if (s[i] == i) {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}

/*
 
 input:
 
 10 9
 1 2
 3 4
 5 2
 4 6
 2 6
 8 7
 9 7
 1 6
 2 4	

 output:
 
 3
 
 */
