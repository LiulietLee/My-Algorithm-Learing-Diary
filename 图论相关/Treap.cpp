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
#include <fstream>
#define MAXSIZE 200010
#define MAXN 1010
#define MAXND MAXN / 10
#define INF 99999999
#define MAXEDGE 1000000
#define MAXVERTEX 510
#define EPS 0.000001
#define PI 3.14159265
#define MOD 1000000009
#define nil NULL
typedef long long ll;
using namespace std;

struct node {
    node *ch[2];
    int rank, value;
    int cmp(int x) {
        if (x == value) return -1;
        return x < value ? 0 : 1;
    }
};

void rotate(node* &n, int d) {
    node *k = n->ch[d^1];
    n->ch[d^1] = k->ch[d];
    k->ch[d] = n;
    n = k;
}

bool search(node *n, int x) {
    while (n != nil) {
        int d = n->cmp(x);
        if (d == -1) return true;
        else n = n->ch[d];
    }
    return false;
}

void insert(node* &n, int x) {
    if (n == nil) {
        n = new node();
        n->value = x;
        n->rank = rand();
        n->ch[0] = n->ch[1] = nil;
    } else {
        int d = n->cmp(x);
        insert(n->ch[d], x);
        if (n->ch[d]->rank > n->rank) {
            rotate(n, d^1);
        }
    }
}

void remove(node* &n, int x) {
    int d = n->cmp(x);
    if (d == -1) {
        if (n->ch[0] == nil) n = n->ch[1];
        else if (n->ch[1] == nil) n = n->ch[0];
        else {
            int d2 = (n->ch[0]->rank > n->ch[1]->rank ? 1 : 0);
            rotate(n, d2);
            remove(n->ch[d2], x);
        }
    } else {
        remove(n->ch[d], x);
    }
}

int main() {
    srand((int)time(nil));
    
    node *root = new node();
    
    insert(root, 1);
    insert(root, 2);
    remove(root, 2);
    
    cout << search(root, 1) << endl;
    cout << search(root, 2) << endl;
    
    return 0;
}
