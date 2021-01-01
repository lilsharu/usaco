#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define FORN FOR(i, 0, n)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define ROFN ROF(i, 0, n)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n';

#define f first
#define s second

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
vpi c;

ll dist(int i, int j) {
    return abs(c[i].f - c[j].f) + abs(c[i].s - c[j].s);
}

// 15 / 15

int main() {
    setIO("marathon");

    cin >> n;
    c.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
    }

    ll td = 0;

    for (int i = 0; i < n - 1; i++) {
        td += dist(i, i + 1);
    }

    ll  md = td;

    for (int i = 1; i < n - 1; i++) {
        ll dw = td - dist(i - 1, i) - dist(i, i + 1) + dist(i - 1, i + 1);
        md = min(md, dw);
    }

    cout << md << endl;
}