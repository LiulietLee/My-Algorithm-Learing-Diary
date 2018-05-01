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
#define MAXSIZE 70
#define MAXN 9999
#define MAXND MAXN / 10
#define INF 99999999
#define MAXEDGE 1000000
#define MAXVERTEX 10
#define EPS 0.00001
#define PI 3.14159265
#define nil NULL
typedef long long ll;
using namespace std;

int main() {
    int n;
    string title;
    
    cin >> n;
    getchar();
    while (n--) {
        getline(cin, title);
        cout << "<<" << title << ">>" << endl;
    }

    return 0;
}
