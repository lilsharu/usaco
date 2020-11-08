#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

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

// CSES 1660
int main() {
    int n, x;
    cin >> n >> x;
    
    vi vals(n);

    FOR(i, 0, n) {
        cin >> vals[i];
    }

    int count = 0, l = 1, r = 1, sum = vals[0];

    for (r = 0; r < n; r++) {
        sum += vals[r];
        while (sum < x && l < r) {
            sum -= vals[l++];
        }

        if (sum == x) count++;
    }

    cout << count << endl;
}