#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<pair<ll, ll>> vpll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define FORN FOR(i, 0, n)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define ROFN ROF(i, 0, n)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) x.begin(), x.end()

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'
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

vpll g;

int n, m;

bool check(int c) {
    int count = n;
    ll pl = g[0].f;
    count--;
    int x = 0;
    while (count > 0 && x < m) {
        ll mv = pl + c;
        while (x < m && mv > g[x].s) x++;
        if (x == m) break;
        count--;
        pl = max(g[x].f, mv);
    }

    return count == 0;
}

// 10 / 10
// Method: Binary Search on the Answer

int main() {
    setIO("socdist");
    cin >> n >> m;

    g.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> g[i].f >> g[i].s;
    }

    sort(all(g));

    ll cm = 1, max = g[m - 1].s;
    for (int i = max; i >= 1; i /= 2) {
        while(check(cm + i)) cm += i;
    }

    cout << cm << endl;
}