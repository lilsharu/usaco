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

// CSES 1643
int main() {
    int n;
    cin >> n;

    vll arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll best = arr[0], current = arr[0];

    for (int i = 1; i < n; i++) {
        current = max(arr[i], current + arr[i]);
        best = max(best, current);
    }

    cout << best << endl;
}