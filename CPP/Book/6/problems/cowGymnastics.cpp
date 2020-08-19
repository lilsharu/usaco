#include <bits/stdc++.h>

using namespace std;

int n, k, places[10][20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int cow;
            cin >> cow;
            places[i][cow - 1] = j;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool good = true;
            //Check in one direction
            for (int a = 0; a < k; a++) {
                if (!(places[a][i] > places[a][j])) {
                    good = false;
                }
            }
            if (!good) {
                good = true;
                for (int a = 0; a < k; a++) {
                    if (!(places[a][j] > places[a][i])) {
                        good = false;
                    }
                }
            }

            if (good) count++;
        }
    }

    cout << count;
}
