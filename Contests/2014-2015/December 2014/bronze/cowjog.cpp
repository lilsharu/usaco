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

// 10 / 10

int main() {
    setIO("cowjog");

    int n;
    cin >> n;
    vpi v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].f >> v[i].s;
    }

    sort(all(v));
    
    for (int i = n - 1; i >= 1; i--) {
        if (v[i].s < v[i - 1].s) {
            v[i - 1].f = -1;
            v[i - 1].s = v[i].s;
        }
    }

    int total = 0;

    for (auto c : v) {
        if (c.f + 1) total++;
    }
    
    cout << total << endl;
}