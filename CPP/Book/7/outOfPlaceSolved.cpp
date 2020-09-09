#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

int height[MAX_N], sorted[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("outofplace.in", "r" , stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> height[i];
        sorted[i] = height[i];
    }

    sort(sorted, sorted + n);

    int steps = -1;

    for (int a = 0; a < n; a++) {
        if (height[a] != sorted[a]) {
            steps++;
        }
    }

    cout << max(0, steps) << '\n';
}