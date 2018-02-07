typedef long long ll;

ll power(ll a, ll b) {
    ll ans = 1, base = a;

    while (b != 0) {  
        if (b & 1) { 
            ans *= base; 
        }
        base *= base;
        b >>= 1;
    }

    return ans;  
}  