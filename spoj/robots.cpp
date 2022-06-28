// https://www.spoj.com/problems/CROBOTS/

#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;
typedef vector<ll>          vll;

#define MOD                 1000000007
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

struct Action {
    int robot;
    char action;
    int repeat;
};

int main(void) {
    fastio;

    int k; cin >> k;

    for (int l = 0; l < k; ++l) {
        int a, b;
        cin >> b >> a;

        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> positions(n);
        vector<char> dir(n);

        vector<vector<char>> grid(a + 1, vector<char>(b + 1, '-'));
        for (int i = 0; i < n; ++i) {
            cin >> positions[i].snd >> positions[i].fst >> dir[i];
            grid[positions[i].first][positions[i].second] = dir[i];
        }

        vector<Action> actions(m);
        for (int i = 0; i < m; ++i) {
            cin >> actions[i].robot >> actions[i].action >> actions[i].repeat;
            actions[i].robot -= 1;
        }

        // exectute the actions
        bool status = false;
        for (int i = 0; i < m; ++i) {
            pair<int, int> start_pos = positions[actions[i].robot];
            // cout << start_pos.fst << ' ' << start_pos.snd << grid[start_pos.fst][start_pos.snd] << '\n';

            if (actions[i].action == 'L') {
                for (int j = 0; j < actions[i].repeat; ++j) {
                    if (grid[start_pos.fst][start_pos.snd] == 'N') {
                        grid[start_pos.fst][start_pos.snd] = 'W';
                    } else if (grid[start_pos.fst][start_pos.snd] == 'S') {
                        grid[start_pos.fst][start_pos.snd] = 'E';
                    } else if (grid[start_pos.fst][start_pos.snd] == 'E') {
                        grid[start_pos.fst][start_pos.snd] = 'N';
                    } else {
                        grid[start_pos.fst][start_pos.snd] = 'S';
                    }
                }

                continue;
            } else if (actions[i].action == 'R') {
                for (int j = 0; j < actions[i].repeat; ++j) {
                    if (grid[start_pos.fst][start_pos.snd] == 'N') {
                        grid[start_pos.fst][start_pos.snd] = 'E';
                    } else if (grid[start_pos.fst][start_pos.snd] == 'S') {
                        grid[start_pos.fst][start_pos.snd] = 'W';
                    } else if (grid[start_pos.fst][start_pos.snd] == 'E') {
                        grid[start_pos.fst][start_pos.snd] = 'S';
                    } else {
                        grid[start_pos.fst][start_pos.snd] = 'N';
                    }
                }

                continue;
            }
            

            pair<int, int> next_pos = positions[actions[i].robot];
            pair<int, int> offset = {0, 0};

            if (grid[start_pos.fst][start_pos.snd] == 'N') {
                offset.fst = 1;
            } else if (grid[start_pos.fst][start_pos.snd] == 'S') {
                offset.fst = -1;
            } else if (grid[start_pos.fst][start_pos.snd] == 'E') {
                offset.snd = 1;
            } else {
                offset.snd = -1;
            }

            for (int j = 0; j < actions[i].repeat; ++j) {
                next_pos = {next_pos.fst + offset.fst, next_pos.snd + offset.snd};

                if (next_pos.first <= 0 || next_pos.second <= 0
                    || next_pos.first > a || next_pos.second > b)
                {
                    cout << "Robot " << (actions[i].robot + 1) << " crashes into the wall\n";
                    status = true;
                    break;
                }

                if (grid[next_pos.fst][next_pos.snd] != '-') {
                    // search for the index
                    int idx = -1;
                    for (int q = 0; q < n; ++q) {
                        if (positions[q] == next_pos) {
                            cout << "Robot " << (actions[i].robot + 1) << " crashes into robot " << (q + 1) << '\n';
                            break;
                        }
                    }

                    status = true;
                    break;
                }
            }

            // cout << positions[actions[i].robot].first << ' ' << positions[actions[i].robot].second << '\n';

            if (status) break;

            grid[next_pos.fst][next_pos.snd] = grid[start_pos.fst][start_pos.snd];
            grid[start_pos.fst][start_pos.snd] = '-';
            positions[actions[i].robot] = {next_pos.fst, next_pos.snd};
        }

        if (!status) {
            cout << "OK\n";
        }
    }


    return 0;
}
