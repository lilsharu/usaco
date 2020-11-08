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

    vector<val> arr(n);

    F0R(i, n) {
        cin >> arr[i].val;
        arr[i].id = i + 1;
    }

    sort(arr.begin(), arr.end(), comp);

    for (ll i = 0; i < n; i++) {
        ll j = i + 1;
        ll k = n - 1;
        while (j < k) {
            ll sum = arr[i].val + arr[j].val + arr[k].val;
            if (sum == x) {
                cout << arr[i].id << ' ' << arr[j].id << ' ' << arr[k].id << endl;
                return 0;
            } else if (sum < x) {
                j++;
            } else {
                k--;
            }
        }
    }


    cout << "IMPOSSIBLE" << endl;
    return 0;
}