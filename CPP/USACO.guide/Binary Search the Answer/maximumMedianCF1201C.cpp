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

int n;
ll k;
vll v;

bool check(ll x) {
    ll sum = 0;
    FOR(i, (n - 1)/2, n) {
        sum += max(0ll, x - v[i]);
    }

    return sum <= k;
}

ll search() {
    ll pos = 0, max = 2E9;
    for (ll a = max; a >= 1; a /= 2) {
        while(check(pos + a)) pos += a;
    }

    return pos;
}

int main() {
    cin >> n >> k;

    FORN {
        int t;
        cin >> t;
        v.pb(t);
    }

    sort(all(v));

    cout << search() << endl;
}