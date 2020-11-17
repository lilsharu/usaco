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

int main() {
    setIO("diamond");

    int n, k;
    cin >> n >> k;

    vi arr(n + 1);
    
    F0R(i, n) cin >> arr[i];
    arr[n] = INT_MAX - arr[n - 1];

    sort(all(arr));
    
    int l = 0, r = 0;

    vi maxVals(n, 1);
    
    F0R(i, n) {
        int j = i + 1;
        while (arr[j++] - arr[i] <= k) {
            maxVals[i]++;
        }
    }

    int max = 0, m = 0;
    F0R(i, n) {
        if (maxVals[i] > max) {
            max = maxVals[i];
            m = i;
        }
    }

    int max2 = 0;
    F0R(i, n) {
        if (i >= m && i < m + max - 1) {
            continue;
        }
        if (maxVals[i] > max2) {
            max2 = maxVals[i];
        }
    }

    cout << max + max2 << endl;
}