#include <bits/stdc++.h>

using namespace std;

int r, s, m, n, p, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> s >> m >> n >> p >> q;

    int ax = 0, ay = 0, bx = 0, by = 0;
    
    bool meet = false;
    int moves, secs = 0;

    while (ax <= bx && ay <= by) {
        if ((ax == bx || ay == by) && (ax != bx || ay != by)) {
            meet = false;
            break;
        } else if (ax == bx && ay == by) {
            meet = true;
            secs++;
            break;
        }
        
        secs++;
        ax += m, ay += n, bx -= p, by -= q;
    }

    if (!meet) {
        cout << -1;
    } else {
        cout << secs;
    }
}
