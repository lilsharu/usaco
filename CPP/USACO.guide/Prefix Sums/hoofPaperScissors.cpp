#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n';

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("hps");
    
    int n;
    cin >> n;

    int h[n + 1], p[n + 1], s[n + 1];
    h[0] = 0;
    s[0] = 0;
    p[0] = 0;

    // P > H, H > S, S > P
    F0R(i, n) {
        char c; cin >> c;
        if (c == 'P') {
            s[i + 1] = s[i] + 1;
            p[i + 1] = p[i];
            h[i + 1] = h[i];
        } else if (c == 'H') {
            p[i + 1] = p[i] + 1;
            s[i + 1] = s[i];
            h[i + 1] = h[i];
        } else {
            h[i + 1] = h[i] + 1;
            s[i + 1] = s[i];
            p[i + 1] = p[i];
        }
    }

    int games = 0;
    
    FOR(i, 1, n + 1) {
        auto update = [&] (int a[], int b[]) {
            games = max(games, a[i] + b[n] - b[i]);
        };
        update(h, p);
        update(h, s);
        update(p, s);
        update(p, h);
        update(s, h);
        update(s, p);
    }

    cout << games << endl;
}