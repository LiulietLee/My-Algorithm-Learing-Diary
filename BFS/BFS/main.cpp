//
//  main.cpp
//  BFS
//
//  Created by Liuliet.Lee on 26/7/2017.
//  Copyright © 2017 Liuliet.Lee. All rights reserved.
//

#include <iostream>
#define nil NULL
#define width 5
#define height 5
using namespace std;

bool book[width][height] = { false };
int map[width][height] = {
    {0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 0, 0, 2},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};
int direction[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

struct node {
    int x;
    int y;
    int previous;
};

node queue[height * width];
int head;
int tail;

void createNodeBy(int index, int previous, int x, int y) {
    queue[index].x = x;
    queue[index].y = y;
    queue[index].previous = previous;
    tail++;
}

void shortestPathTo(int endIndex) {
    int index = endIndex;
    while (index != 0) {
        printf("(%d, %d) <- ", queue[index].y, queue[index].x);
        index = queue[index].previous;
    }
    printf("(0, 0)\n");
}

int scanNexts() {
    for (int i = 0; i < sizeof(direction) / sizeof(*direction); i++) {
        int x = queue[head].x + direction[i][0];
        int y = queue[head].y + direction[i][1];
        
        if (x < 0 || x >= width || y < 0 || y >= height) {
            continue;
        } else if (map[x][y] == 1 || book[x][y]) {
            continue;
        }
        
        createNodeBy(tail, head, x, y);
        if (map[queue[tail - 1].x][queue[tail - 1].y] == 2) {
            shortestPathTo(tail - 1);
            return 1;
        }
        book[x][y] = true;
    }
    
    head++;
    return 0;
}

int main(int argc, const char * argv[]) {
    createNodeBy(0, 0, 0, 0);
    bool isFindPath = false;
    
    while (!isFindPath) {
        if (scanNexts() == 1) {
            isFindPath = true;
        }
    }
    
    return 0;
}
