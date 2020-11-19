#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define FORN FOR(i, 0, n)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define ROFN ROF(i, 0, n)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int a; cin >> a
#define read2(a, b) read(a); read(b)
#define read3(a, b, c) read2(a, b); read(c)
#define read4(a, b, c, d) read3(a, b, c), read(d)

#define endl '\n';

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read(n);

    string s;
    cin >> s;

    char val[n];
    F0R(i, n) val[i] = s[i];

    read(q);

    F0R(x, q) {
        read(changes);
        char c; cin >> c;

        if (changes >= n) {
            cout << n << endl;
            continue;
        }

        int sol = changes;

        int j = 0;
        int pos = s.find(c);

        int start = 0;
        if (n - pos > changes * 2) start = pos;
        
        if (pos == -1) goto printsol;

        FOR(i, start, n) {
            if (i >= pos && val[i] != c) continue;
            int ch = changes;
            j = i;
            while (j < n && (val[j] == c || ch--)) {
                j++;
            }
            if (j == n && ch && j - i + ch <= n) j += ch;
            sol = max(sol, j - i);
            if (i + sol + 1 > n) break;
        }

        printsol:
        cout << sol << endl;
    }
}