#include <iostream>
#include <cstdio>
typedef long long ll;

// result = a ^ b % c
ll powerMod(ll a, ll b, ll c) {
    ll ans = 1;
    a %= c;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % c;
        b /= 2;
        a = (a * a) % c;
    }
    return ans;
}