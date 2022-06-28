// https://www.spoj.com/problems/SMPSEQ3/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int m;
    cin >> m;

    vector<int> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }

    // print all the numbers that appear in s, but not in q
    for (auto it : s) {
        int left = 0, right = m - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (q[mid] < it) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if (q[left] != it) {
            cout << it << ' ';
        }
    }

    cout << endl;

    return 0;
}

