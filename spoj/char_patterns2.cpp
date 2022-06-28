// https://www.spoj.com/problems/CPTTRN2/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;

        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                cout << ((i == 0 || i == a - 1 || j == 0 || j == b - 1) ? '*' : '.');
            }
            cout << '\n';
        }

        cout << '\n';
    }

    return 0;
}
