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

int n, t;
vi d;

bool check(int k) {
    int time = 0;
    int i = k;
    vi v(k);
    F0R(x, k) v[x] = d[x];
    while (i < n + k) {
        int mv = *min_element(all(v));
        v.erase(find(all(v), mv));
        F0R(x, v.size()) v[x] -= mv;
        time += mv;
        if (i < n) v.pb(d[i]);
        if (time > t) return false;
        i++;
    }
    
    return time <= t;
}

int solve(int lo, int hi) {
    for (hi++; lo < hi;) {
        int mid = (lo + hi + 1) / 2;
        check(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

int main() {
    setIO("cowdance");
    cin >> n >> t;
    F0R(i, n) {
        int a;
        cin >> a;
        d.pb(a);
    }

    cout << solve(1, n) << endl;
}