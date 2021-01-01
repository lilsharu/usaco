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
    setIO("crosswords");
    int n, m;
    cin >> n >> m;
    
    vector<char> v[n];

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        v[i] = vector<char>(input.begin(), input.end());
    }

    int clues = 0;
    vpi vals;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool s = (j + 2 < m && v[i][j] == '.' && v[i][j + 1] == '.' && v[i][j + 2] == '.' && (j == 0 || v[i][j - 1] == '#'));
            bool t = (i + 2 < n && v[i][j] == '.' && v[i + 1][j] == '.' && v[i + 2][j] == '.' && (i == 0 || v[i - 1][j] == '#'));

            if (s || t) {
                clues++;
                vals.pb(pii(i, j));
            }
        }
    }

    cout << clues << endl;
    for (auto p : vals) {
        cout << p.f + 1 << ' ' << p.s + 1 << endl;
    }
}