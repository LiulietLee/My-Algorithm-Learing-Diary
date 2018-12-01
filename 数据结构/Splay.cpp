#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct Node {
    Node *ch[2];
    int s, v, flip;

    int cmp(int k) const {
        int d = k - ch[0]->s;
        if (d == 1) return -1;
        return d <= 0 ? 0 : 1;
    }
    void maintain() {
        s = ch[0]->s + ch[1]->s + 1;
    }
    void pushdown() {
        if (flip) {
            flip = 0;
            swap(ch[0], ch[1]);
            ch[0]->flip = !ch[0]->flip;
            ch[1]->flip = !ch[1]->flip;
        }
    }
};

Node *null = new Node();

void rotate(Node* &o, int d) {
    Node *k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o = k;
}

void splay(Node* &o, int k) {
    o->pushdown();
    int d = o->cmp(k);
    if (d == 1) {
        k -= o->ch[0]->s + 1;
    }
    if (d != -1) {
        Node *p = o->ch[d];
        p->pushdown();
        int d2 = p->cmp(k);
        int k2 = (d2 == 0 ? k : k - p->ch[0]->s - 1);
        if (d2 != -1) {
            splay(p->ch[d2], k2);
            if (d == d2) {
                rotate(o, d^1);
            } else {
                rotate(o->ch[d], d);
            }
        }
        rotate(o, d^1);
    }
}

Node* merge(Node *left, Node *right) {
    splay(left, left->s);
    left->ch[1] = right;
    left->maintain();
    return left;
}

void split(Node *o, int k, Node* &left, Node* &right) {
    splay(o, k);
    left = o;
    right = o->ch[1];
    o->ch[1] = null;
    left->maintain();
}

char str[MAXN];

Node* build(int l, int r) {
    if (l >= r) return null;
    int mid = (l + r) / 2;
    Node *n = build(l, mid);
    Node *o = new Node();
    o->v = str[mid];
    o->flip = o->s = 0;
    o->ch[0] = n;
    o->ch[1] = build(mid + 1, r);
    o->maintain();
    return o;
}

vector<int> ans;

void getAns(Node *o) {
    if (o != null) {
        o->pushdown();
        getAns(o->ch[0]);
        ans.push_back(o->v);
        getAns(o->ch[1]);
    }
}
