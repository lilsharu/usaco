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

#define endl '\n';

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int n, m, c, ttop, tbottom;
vi cows;

bool checkTime(int tmax) {
    int busses = 1;
    int start = cows[0];
    int startIndex = 0;
    FOR(i, 1, n) {
       if (cows[i] - start > tmax || i - startIndex + 1 > c) {
           busses++;
           start = cows[i];
           startIndex = i; 
       } 
    }

    return busses <= m;
}

// 1/10
int main() {
    setIO("convention");
    
    cin >> n >> m;
    cin >> c;

    F0R(i, n) {
        int t;
        cin >> t;
        cows.pb(t);
    }

    sort(all(cows));
    ttop = cows[n - 1];
    tbottom = cows[0];

    if (ttop == tbottom) {
        cout << cows.size() / c + (cows.size() % c > 0) ? 1 : 0 << endl;
        return 0;
    }

    int lo = 0;
    int hi = ttop - tbottom;

    for (hi++; lo < hi;) {
        int mid = (lo + hi) / 2;
        checkTime(mid) ? hi = mid : lo = mid + 1;
    }

    cout << lo << endl;
    return 0;
}