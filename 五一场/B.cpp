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
#define MAXSIZE 10000000
#define MAXN 10
#define MAXND MAXN / 10
#define INF 99999999
#define MAXEDGE 1000000
#define MAXVERTEX 10
#define EPS 0.00001
#define PI 3.14159265
#define nil NULL
typedef long long ll;
using namespace std;

int length;
int converted[MAXSIZE], my_next[MAXN];
int pattern[] = { 13, 15, 14, 9, 11, 1 };

void convertToIntArray(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            if (text[i] <= 'z' && text[i] >= 'a') {
                if (text[i] == 'l') {
                    converted[i] = 'i' - 'a' + 1;
                } else {
                    converted[i] = text[i] - 'a' + 1;
                }
            } else {
                converted[i] = text[i] - 'A' + 1;
            }
        } else if (isdigit(text[i])) {
            if (text[i] == '1') {
                converted[i] = 'i' - 'a' + 1;
            } else if (text[i] == '0') {
                converted[i] = 'o' - 'a' + 1;
            } else {
                converted[i] = -1;
            }
        } else {
            converted[i] = -1;
        }
    }
}

void getNext(int str[], int len) {
    int j = -1;
    my_next[0] = -1;
    for (int i = 1; i < len; i++) {
        while (j != -1 && str[i] != str[j + 1]) {
            j = my_next[j];
        }
        if (str[i] == str[j + 1]) {
            j++;
        }
        my_next[i] = j;
    }
}

int findMonika(int text[], int pattern[]) {
    int ans = 0, n = length, m = 6, j = -1;
    
    getNext(pattern, m);
    for (int i = 0; i < n; i++) {
        while (j != -1 && text[i] != pattern[j + 1]) {
            j = my_next[j];
        }
        if (text[i] == pattern[j + 1]) {
            j++;
        }
        if (j == m - 1) {
            ans++;
        }
    }
    
    return ans;
}

int main() {
    string text;
    
    getline(cin, text);
    length = (int)text.length();
    convertToIntArray(text);
    cout << findMonika(converted, pattern);
    
    return 0;
}
