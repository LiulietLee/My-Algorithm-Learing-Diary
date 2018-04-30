#define MAXSIZE 100
#define sigma_size 26

struct Trie {
    int ch[MAXSIZE][sigma_size];
    int val[MAXSIZE];
    int sz;
    
    Trie() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }
    
    int idx(char c) {
        return c - 'a';
    }
    
    /// 添加前缀 s，以及对应的权值 v（v 不能等于 0）
    void insert(string s, int v) {
        int u = 0, len = (int)s.length();
        for (int i = 0; i < len; i++) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    
    /// 检查 s 是否是本 Trie 中的前缀
    bool preciseMatch(string s) {
        int u = 0, len = (int)s.length();
        for (int i = 0; i < len; i++) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                return false;
            }
            u = ch[u][c];
        }
        return val[u] != 0;
    }
    
    /// 返回 s 在本 Trie 中的所有匹配前缀
    vector<string> findPrefixsOf(string s) {
        vector<string> prefixs;
        int u = 0, len = (int)s.length();
        string prefix = "";
        
        for (int i = 0; i < len; i++) {
            prefix += s[i];
            int c = idx(s[i]);
            if (!ch[u][c]) {
                break;
            }
            u = ch[u][c];
            if (val[u] != 0) {
                prefixs.push_back(prefix);
            }
        }
        
        return prefixs;
    }
};

void match(Trie trie, string str) {
    if (trie.preciseMatch(str)) {
        cout << "matched." << endl;
    } else {
        cout << "not matched." << endl;
    }
}

int main() {
    Trie trie = Trie();
    
    trie.insert("str", 1);
    trie.insert("st", 1);
    
    match(trie, "str");
    match(trie, "st");
    match(trie, "stra");
    
    auto prefixs = trie.findPrefixsOf("strstrss");
    for (vector<string>::iterator it = prefixs.begin(); it != prefixs.end(); it++) {
        cout << *it << endl;
    }
    
    return 0;
}