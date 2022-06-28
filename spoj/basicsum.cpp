// https://www.spoj.com/problems/BASICSUM/

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
///////////////////////////////////////////////////////////////////////////////

int main(void) {
    fastio;

    int n, q;
    cin >> n >> q;
    
    // precalculate the partial sums
    vector<long long> psum(n, 0);

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;

        psum[i] = (i - 1 >= 0 ? psum[i - 1] : 0) + tmp;
    }

    for (int i = 0; i < q; ++i) {
        int k, start;
        cin >> k >> start;

        start = (start - 1) % n;

        // add cycles
        long long res = 1LL * (start + k - 1 >= psum.size() ? (k - (psum.size() - start)) / psum.size() : 0) * psum[psum.size() - 1];

        if (start + k >= psum.size()) {
            // add what remains after cycles
            if ((k - (psum.size() - start)) % psum.size() != 0) {
                res += psum[(k - (psum.size() - start)) % psum.size() - 1];
            }
        }

        // add the beginning
        res += (start + k - 1 < psum.size() ? psum[start + k - 1] - (start - 1 >= 0 ? psum[start - 1] : 0)
                : psum[psum.size() - 1] - (start - 1 >= 0 ? psum[start - 1] : 0));

        cout << res << '\n';
    }

    return 0;
}
