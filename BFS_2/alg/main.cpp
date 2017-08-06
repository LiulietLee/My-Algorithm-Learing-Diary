//
//  main.cpp
//  alg
//
//  Created by Liuliet.Lee on 6/8/2017.
//  Copyright © 2017 Liuliet.Lee. All rights reserved.
//

#include <iostream>
using namespace std;

struct node {
    int cur;
    int step;
};

int main(int argc, const char * argv[]) {
    node queue[6] = {0};
    bool flag = false, book[5] = {false};
    int start, end, head = 0, tail = 1, city, line, x, y, map[5][5] = {0};
    
    scanf("%d%d%d%d", &city, &line, &start, &end);
    for (int i = 0; i < line; i++) {
        scanf("%d%d", &x, &y);
        map[x - 1][y - 1] = 1;
        map[y - 1][x - 1] = 1;
    }
    
    queue[head].cur = start;
    queue[head].step = 0;
    book[head] = true;
    
    while (head < tail) {
        for (int i = 0; i < city; i++) {
            if (map[head][i] == 1 && !book[i]) {
                queue[tail].cur = i;
                queue[tail].step = queue[head].step + 1;
                book[i] = true;
                tail++;
                
                if (i == end) {
                    flag = true;
                    break;
                }
            }
        }
        
        if (flag) {
            break;
        }
        head++;
    }
    
    printf("%d\n", queue[tail - 1].step);
    
    return 0;
}
