#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
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


// 10/10
int main() {
    setIO("diamond");

    int n, k;
    cin >> n >> k;

    vi arr(n);
    
    F0R(i, n) cin >> arr[i];

    sort(all(arr));
    
    vi maxVals(n, 1);

    int l = 0, r = 0;
    for (; l < n; l++) {
        while (r < n && arr[r] - arr[l] <= k) r++;
        maxVals[l] = r - l;
    }
    
    vi maxValAfter(n + 1);
    maxValAfter[n] = 0;
    R0F(i, n) {
        maxValAfter[i] = max(maxValAfter[i + 1], maxVals[i]);
    }
    
    int ans = 0;
    F0R(i, n) {
        ans = max(ans, maxVals[i] + maxValAfter[i + maxVals[i]]);
    }

    cout << ans << endl;    
}