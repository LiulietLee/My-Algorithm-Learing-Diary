#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int mod = 1e9+9;

struct Matrix {
    ll m[2][2];
    
    Matrix() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                m[i][j] = 0;
            }
        }
    }
    
    Matrix operator * (const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.m[i][j] = (c.m[i][j] + m[i][k] * b.m[k][j]) % mod;
                }
            }
        }
        return c;
    }
    
    void operator *= (const Matrix &b) {
        Matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.m[i][j] = (c.m[i][j] + m[i][k] * b.m[k][j]) % mod;
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                m[i][j] = c.m[i][j];
            }
        }
    }
};

Matrix powerMod(Matrix a, ll n) {
    Matrix b;
    b.m[0][0] = b.m[1][1] = 1;
    while (n) {
        if (n & 1) {
            b *= a;
        }
        a *= a;
        n >>= 1;
    }
    return b;
}

int main() {
    for (int i = 1; i < 100; i++) {
        Matrix a;
        a.m[0][0] = a.m[0][1] = a.m[1][0] = 1;
        Matrix ans = powerMod(a, i);
        cout << ans.m[0][1] << endl;
    }
    
    return 0;
}
