// https://www.spoj.com/problems/SMPDIV/

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

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, x, y;
        cin >> n >> x >> y;

        for (int j = x; j < n; j += x) {
            if (j % y != 0) {
                cout << j << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
