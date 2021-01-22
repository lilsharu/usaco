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

int n, m;
vpi cows;

int main() {
    setIO("cereal");
    cin >> n >> m;

    cows.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i].f >> cows[i].s;
    }

    vi solutions(n);

    for (int i = 0; i < n; i++) {
        vector<bool> cereal(m);
        int t = 0;
        for (int j = i; j < n; j++) {
            if (!cereal[cows[j].f]) {
                cereal[cows[j].f] = 1;
                t++;
            } else if (!cereal[cows[j].s]) {
                cereal[cows[j].s] = 1;
                t++;
            }

            if (t == m) break;
        }
        solutions[i] = t;
    }

    for (auto i : solutions) {
        cout << i << endl;
    }
}