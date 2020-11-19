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

int n, k;

bool check(int pos, vll arr) {
    ll sum = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        sum += max(0ll, arr[pos] - arr[i]);
    }

    return sum <= k;
}

int main() {
    cin >> n >> k;
    
    vll arr(n);

    sort(all(arr));

    ll pos = 0, maximum = n;
    for (ll a = maximum; a >= 1; a /= 2) {
        while (check(pos + a, arr)) pos += a;
    }

    cout << pos << endl;
}