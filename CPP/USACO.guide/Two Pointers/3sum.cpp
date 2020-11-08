#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n';

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct val {
    ll val, id;
};

bool comp(val& a, val& b) {
    return a.val < b.val;
}

// CSES 1641
int main() {
    ll n, x;
    cin >> n >> x;

    vector<val>arr(n);

    F0R(i, n) {
        cin >> arr[i].val;
        arr[i].id = i + 1;
    }

    sort(arr.begin(), arr.end(), comp);

    int l = 0, r = n - 1;
    
    while (l < r) {
        int sum = arr[l].val + arr[r].val;
        if (sum <= x) {
            for (int i = 0; i < n; i++) {
                if (i == l || i == r) continue;
                if (sum + arr[i].val == x) {
                    cout  << arr[l].id << ' ' << arr[r].id << ' ' << arr[i].id << endl;
                    return 0;
                }
            }

            l++;
        } else {
            r--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}