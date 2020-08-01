#include <bits/stdc++.h>

using namespace std;

int capacity[3], contains[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    
    for (int i = 0; i < 3; i++) {
        cin >> capacity[i] >> contains[i];
    }
    
    int pos = 0;

    for (int i = 0; i < 100; i++) {
        int toPour = min(capacity[(pos + 1) % 3] - contains[(pos + 1) % 3], contains[pos]);
        contains[pos] -= toPour;
        contains[(pos + 1) % 3] += toPour;

        ++pos %= 3;
    }

    cout << contains[0] << '\n' << contains[1] << '\n' << contains[2] << '\n';
}
