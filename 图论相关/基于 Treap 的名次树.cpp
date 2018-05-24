struct node {
    node *ch[2];
    int priority, value, size = 1;
    int cmp(int x) {
        if (x == value) return -1;
        return x < value ? 0 : 1;
    }
    void maintain() {
        size = 1;
        if (ch[0] != nil)
            size += ch[0]->size;
        if (ch[1] != nil)
            size += ch[1]->size;
    }
};

void rotate(node* &n, int d) {
    node *k = n->ch[d^1];
    n->ch[d^1] = k->ch[d];
    k->ch[d] = n;
    // 下面两句不能换位置
    n->maintain();
    k->maintain();
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
        n->priority = rand();
        n->ch[0] = n->ch[1] = nil;
    } else {
        int d = n->cmp(x);
        insert(n->ch[d], x);
        if (n->ch[d]->priority > n->priority) {
            rotate(n, d^1);
        }
        n->maintain();
    }
}

void remove(node* &n, int x) {
    int d = n->cmp(x);
    if (d == -1) {
        if (n->ch[0] == nil) n = n->ch[1];
        else if (n->ch[1] == nil) n = n->ch[0];
        else {
            int d2 = (n->ch[0]->priority > n->ch[1]->priority ? 1 : 0);
            rotate(n, d2);
            remove(n->ch[d2], x);
        }
    } else {
        remove(n->ch[d], x);
    }
    if (n != nil) n->maintain();
}

node* getKthNode(node* n, int k) {
    static int preRank = 0;
    if (preRank + n->size < k) return nil;
    int rank = (n->ch[0] == nil ? 1 : n->ch[0]->size + 1);
    if (rank + preRank == k) {
        preRank = 0;
        return n;
    } else if (rank + preRank < k) {
        preRank += rank;
        return getKthNode(n->ch[1], k);
    } else {
        return getKthNode(n->ch[0], k);
    }
}

int getRank(node* n, int x) {
    int rank = 0;
    while (n != nil) {
        int d = n->cmp(x);
        if (d == -1) break;
        else {
            if (d == 1)
                rank += (n->ch[0] == nil ? 0 : n->ch[0]->size) + 1;
            n = n->ch[d];
        }
    }
    rank += (n->ch[0] == nil ? 0 : n->ch[0]->size);
    return rank + 1;
}

int main() {
    srand((int)time(nil));
    
    node *root = nil;
    
    for (int i = 0; i < 100; i++) {
        insert(root, i);
    }
    
    for (int i = 1; i < 9; i++) {
        cout << i << "th number is " << getKthNode(root, i)->value << endl;
        cout << "rank of " << i << " is " << getRank(root, i) << endl;
    }
    
    return 0;
}
