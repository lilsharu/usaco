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
    read(n);

    string val;
    cin >> val;

    read(q);

    F0R(x, q) {
        read(changes);
        char c; cin >> c;

        int sol = 0;
        F0R(i, n) {
            int j = changes, ind = i, sum = 0;
            while ((val[ind] == c || j--) && ind < n) {
                if (val[ind] == c) j++;
                sum++;
            }
            sol = max(sol, sum);
        }
        cout << sol << endl;
    }
}