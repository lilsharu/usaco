#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

int n, pos[MAX_N], cows[MAX_N], newCows[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int indexTo;
        cin >> indexTo;

        pos[indexTo - 1] = i;
    }
    
    for (int i = 0; i < n; i++) {
        int cow;
        cin >> cow;

        cows[i] = cow;
    }

    for (int i = 0; i < 3; i++) {
        for (int i = 0; i < n; i++) {
            newCows[pos[i]] = cows[i];
        }
        for (int i = 0; i < n; i++) {
            cows[i] = newCows[i];
        }
    }


    for (int i = 0; i < n; i++) {
        cout << cows[i] << '\n';
    }
}
