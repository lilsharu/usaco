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

// CSES 1640
int main() {
    int n, x;
    cin >> n >> x;

    int vals[n], cvals[n];

    for (int i = 0; i < n; i++) {
        cin >> vals[i];
        cvals[i] = vals[i];
    }

    sort(vals, vals + n);

    int l = 0, r = n - 1;
    
    int ls = -1, rs = -1;
    while (l < r) {
        int sum = vals[l] + vals[r];
        if (sum == x) {
            // std::cout << l + 1 << ' ' << r + 1 << endl;
            ls = l, rs = r;
            break;
        } else if (sum > x) {
            r--;
        } else {
            l++;
        }
    }
    
    if (ls == -1 || rs == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    int lf = -1;

    for (int i = 0; i < n; i++) {
        if (vals[ls] == cvals[i]) {
            cout << i + 1 << ' ';
            lf = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (vals[rs] == cvals[i] && lf != i) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;    
}