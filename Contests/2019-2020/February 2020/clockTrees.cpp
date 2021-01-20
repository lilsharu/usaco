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

int dfs(int current, int parent) {
    for (auto a : adj[current]) {
        if (a != parent) {
            dfsv[current] += 12 - dfs(a, current);
            dfsv[current] = (dfsv[current] - 1) % 12 + 1;
        }
    }
    dfsv[parent]++;
    return dfsv[current];
}

int n;
int dfsv[2501];
int cv[2501];
vi adj[2501];

int main() {
    setIO("clocktree");

    cin >> n;
    FORN cin >> cv[i + 1];

    for (int i = 0; i < n - 1; i++) {
        read2(a, b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= n; i++) {
            dfsv[i] = cv[i];
        }

        if (dfs(i, 0) == 12) {
            total++;
        }
    }

    cout << total << endl;
}