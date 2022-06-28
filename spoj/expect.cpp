// https://www.spoj.com/problems/EXPECT/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a;

    while (true) {
        cin >> a;
        cout << a << '\n';
        fflush(stdout);

        if (a == 42) break;
    }

    return 0;
}
