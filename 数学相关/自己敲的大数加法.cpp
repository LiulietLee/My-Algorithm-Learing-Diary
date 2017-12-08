#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#define nil NULL
#define MAXN 40
using namespace std;
typedef long long ll;

string add(string a, string b) {
    string ans = "";
    
    if (a.length() > b.length()) {
        string temp = a;
        a = b; b = temp;
    }
    
    char ch;
    int posa = (int)a.length() - 1, posb = (int)b.length() - 1;
    int na, nb, ns, ca = 0;
    while (posa >= 0 && posb >= 0) {
        na = a[posa] - '0'; nb = b[posb] - '0';
        ns = na + nb + ca;
        if (ns >= 10) {
            ns = ns % 10;
            ca = 1;
        } else {
            ca = 0;
        }
        ch = ns + '0';
        ans = ch + ans;
        posa--; posb--;
    }
    
    if (posb >= 0) {
        string sp = b.substr(0, posb + 1);
        if (ca == 1) {
            ans = add("1", sp) + ans;
        } else {
            ans = sp + ans;
        }
    } else if (ca == 1 && posb < 0) {
        ans = "1" + ans;
    }
    
    return ans;
}

int main() {
    string a, b;
    
    while (cin >> a >> b) {
        cout << add(a, b) << endl;
    }
    
    return 0;
}
