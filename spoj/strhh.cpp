#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        char tmp[200];
        scanf("%s", tmp);

        int n = strlen(tmp);
        for (int j = 0; j < n / 2; j += 2) {
            printf("%c", tmp[j]);
        }

        printf("\n");
    }

    return 0;
}
