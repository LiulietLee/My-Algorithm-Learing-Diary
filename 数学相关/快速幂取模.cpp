#include <iostream>
#include <cstdio>
typedef long long ll;

// a 的逆元 = powerMod(a, MOD - 2, MOD)
ll powerMod(ll a, ll b, ll c) {
    ll ans = 1;
    a %= c;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}
