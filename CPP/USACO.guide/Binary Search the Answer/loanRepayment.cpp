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

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n';

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

ll pow(ll a, ll b) {
    ll q = 1ll;
    while (b--) {
        q *= a;
    }
    return q;
}

ll n, k, m;

ll calcGive(ll x, ll i) {
    if (i == 1) return n / x;

    ll numerator = 0;
    ll oi = i;
    while (i) {
        i--;
        numerator += ((oi - i) % 2 ? pow(x, i) : -pow(x, i));
    }

    numerator *= n;

    return numerator / pow(x, oi);
}

ll calcTotal(ll x, ll i) {
    if (i == 1) return n / x;

    ll numerator = 0;
    ll oi = i;
    while (i) {
        i--;
        numerator += ((oi - i) % 2 ? pow(x, i) : -pow(x, i)) * (i != 0 ? 2 : 1);
    }

    numerator *= n;

    return numerator / pow(x, oi);
}

bool check(int x) {
    int lo = 1, hi = k;
    for (lo--; lo < hi; ) {
       int mid = (lo + hi + 1)/2;
       calcGive(x, mid) > m ? lo = mid : hi = mid - 1;
    }
    
    // for (ll i = 0; i < k && g < n; i++) {
    //     ll y = (n - g) / x;
    //     if (y < m) {
    //         ll rounds = k - i;
    //         g += rounds * m;
    //         break;
    //     } else g += y;
    // }

    ll g = calcTotal(x, lo) + (k - lo >= 1 ? m * (k - lo) : 0);

    return g >= n;
}

int main() {
    setIO("loan");
    cin >> n >> k >> m;

    ll pos = 0, max = 2E9;
    for (ll a = max; a >= 1; a /= 2) {
        while (check(pos + a)) pos += a;
    }

    cout << pos << endl;
}