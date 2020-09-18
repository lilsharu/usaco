#include <bits/stdc++.h>

using namespace std;

int n;
bool cows[10][10];

void flip(int bottom, int side) {
    for(int i = 0; i <= bottom; i++) {
        for (int k = 0; k <= side; k++) {
            cows[i][k] = !cows[i][k];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int k = 0; k < n; k++) {
            cows[i][k] = (bool) (((int) input[k]) - 48);
        }
    }

    int count = 0;

    for (int bottom = n - 1; bottom >= 0; bottom--) {
        for (int side = n - 1; side >= 0; side--) {
            if (cows[bottom][side]) {
                flip(bottom, side);
                count++;
            }
        }
    }

    cout << count << '\n';
}