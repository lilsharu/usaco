#include <bits/stdc++.h>

using namespace std;

int n;
string road;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    
    cin >> n >> road;

    for (int i = 1; i <= n; i++) {
        bool good = true;
        for (int j = 0; j + i <= n; j++) {
            for (int k = 0; k < j; k++) {
                if (road.substr(j, i) == road.substr(k, i)) {
                    good = false;
                }
            }
        }

        if (good) {
            cout << i << '\n';
            break;
        }
    }
}
