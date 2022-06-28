// https://www.spoj.com/problems/CPTTRN3/

#include <bits/stdc++.h>
using namespace std;

#define fastio              ios_base::sync_with_stdio(0); cin.tie(0)

int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;

        // print the first round of '*'s
        for (int i = 0; i < b * 3 + 1; ++i) {
            cout << '*';
        }
        cout << '\n';

        for (int i = 0; i < a; ++i) {
            cout << '*';
            for (int j = 0; j < b; ++j) {
                cout << "..*";
            }
            cout << '\n';

            cout << '*';
            for (int j = 0; j < b; ++j) {
                cout << "..*";
            }
            cout << '\n';

            for (int i = 0; i < b * 3 + 1; ++i) {
                cout << '*';
            }
            cout << '\n';
        }

        cout << '\n';
    }

    return 0;
}
