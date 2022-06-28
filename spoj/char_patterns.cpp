// https://www.spoj.com/problems/CPTTRN1/

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
                cout << ((i + j) % 2 == 0 ? '*' : '.');
            }
            cout << '\n';
        }

        cout << '\n';
    }

    return 0;
}
