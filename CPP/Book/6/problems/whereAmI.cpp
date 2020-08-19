#include <bits/stdc++.h>

using namespace std;

int n;
string road;

bool hasMore(string sub) {
    int len = sub.length();

    int count = -1;
    
    for (int i = 0; i < road.length() - len + 1; i++) {
        if (road.substr(i, len) == sub) {
            count++;
        }

        if (count > 0) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    
    cin >> n >> road;

    int minMax = 1;

    for (int i = 0; i < n; i++) {
        for (int k = i + minMax; k <= n; k++) {
            if (hasMore(road.substr(i, k))) {
                minMax = k - i;
            }
        }
    }

    cout << minMax + 1 << '\n';
}
