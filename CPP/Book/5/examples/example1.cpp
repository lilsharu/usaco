#include <bits/stdc++.h>

using namespace std;

int r, s, m, n, p, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> s >> m >> n >> p >> q;

    int ax = 0, ay = 0, bx = 0, by = 0;
    
    bool meet = false;
    int secs = 0;

    while (ax < bx && ay < by) {
        secs++;
        ax += m, ay += n, bx -= p, by -= q;
    }

    if (ax == bx && ay == by) {
        cout << secs << '\n';
    } else {
        cout << -1 << '\n';
    }
}
