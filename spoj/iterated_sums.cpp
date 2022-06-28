// https://www.spoj.com/problems/SMPSUM/

#include <bits/stdc++.h>
using namespace std;

#define fastio              ios_base::sync_with_stdio(0); cin.tie(0)

int main(void) {
    int a, b;
    cin >> a >> b;

    long long squares = 0;
    for (int i = a; i <= b; ++i) {
        squares += (1LL * i * i);
    }

    cout << squares << '\n';

    return 0;
}
