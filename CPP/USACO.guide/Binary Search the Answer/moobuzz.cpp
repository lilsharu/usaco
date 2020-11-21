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


// 13/13
int main() {
    setIO("moobuzz");
    ll n;
    cin >> n;

    vi vals = {0};
    
    // Can't use precomputed values, so computes it by itself
    F0R(i, 15) {
        if (i % 3 && i % 5) {
            vals.pb(i);
        }
    }

    ll ans = (n / 8ll) * 15ll + vals[n % 8];
    
    if (!(n % 8)) ans--;
    
    cout << ans << endl;
    return 0;
}