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

int n, m, k;

vi trans, pa, na;
vpi changes;

bool visited[100001];

void transform() {
    for (int i = 0; i < n; i++) {
        na[trans[i]] = pa[i];
    }

    auto temp = pa;
    pa = na;
    na = temp;
}

int main() {
    setIO("swap");
    cin >> n >> m >> k;

    trans.resize(n);
    pa.resize(n);
    na.resize(n);
    changes.resize(m);

    for (int i = 0; i < n; i++) {
        trans[i] = i;
        pa[i] = i;
    }

    for (int i = 0; i < m; i++) {
        read2(f, s);
        f--; s--;
        for (int j = 0; j < (s - f + 1) / 2; j++) {
            int temp = trans[f + j];
            trans[f + j] = trans[s - j];
            trans[s - j] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int start = trans[i];
            vi cycle;
            cycle.pb(i);
            while (start != i) {
                visited[start] = true;
                cycle.pb(start);
                start = trans[start];
            }

            int modVal = k % cycle.size();

            for (int j = 0; j < cycle.size(); j++) {
                trans[cycle[j]] = cycle[(j + modVal) % cycle.size()];
            }
        }
    }

    for (auto x : trans) {
        cout << x + 1 << endl;
    }
}