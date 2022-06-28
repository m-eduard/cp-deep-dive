#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;
typedef vector<ll>          vll;

#define MOD                 10000007
#define MOD2                998244353
#define INF                 1e18
#define debug(x)            cerr << #x << ' ' << x << '\n'
#define mem0(x)             memset(x, 0, sizeof(x))
#define mem0x3f(x)          memset(x, 0x3f, sizeof(x))

#define pb                  push_back
#define fst                 first
#define snd                 second

#define fastio              ios_base::sync_with_stdio(0); cin.tie(0)

const ld                    pi = acos(-1);

ll fast_exp(int a, int b) {
    if (b == 0) return 1;

    ll tmp = fast_exp(a, b / 2);

    if (b % 2 == 0) {
        return (tmp * tmp) % MOD;
    }

    return (a * ((tmp * tmp) % MOD)) % MOD;
}

int main(void) {
    fastio;
    
    while (true) {
        int n, k;
        cin >> n >> k;

        if (n == k && n == 0) break;

        ll eax = fast_exp(n - 1, k);
        ll ebx = fast_exp(n, k);
        ll ecx = fast_exp(n - 1, n - 1);
        ll edx = fast_exp(n, n);

        ll res = (((2 * eax) % MOD) + ebx) % MOD;
        res = ((res + ((2 * ecx) % MOD)) % MOD) + edx;

        cout << (res % MOD) << '\n';
    }

    return 0;
}
