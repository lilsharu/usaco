#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'
#define f first
#define s second

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

bool test(ll n, ll k, ll m, ll x) {
    ll g = 0;
    while (k > 0 && g < n) {
        ll y = (n - g) / x;
        if (y < m) {
            ll turns = (n - g + m - 1) / m;
            return turns <= k;
        }
        ll maxMatch = n - x * y;
        ll runsOfY = (maxMatch - g) / y + 1;
        if (runsOfY > k) runsOfY = k;
        g += y * runsOfY;
        k -= runsOfY;
    }

    return g >= n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setIO("loan");

    ll n, k, m;

    cin >> n >> k >> m;

    ll lo = 1, hi = 1e12;
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if(test(n, k, m, mid)) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << lo << endl;
    return 0;
}