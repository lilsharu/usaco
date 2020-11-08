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

int main() {
    setIO();
    int n, m;
    cin >> n >> m;

    vi arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = 0, sum = 0, sol = 0;;
    for (r = 0; r < n; r++) {
        sum += arr[r];
        while (sum > m && l < r) {
            sum -= arr[l++];
        }
        sol = arr[r] <= m ? max(sol, r - l + 1) : sol;
    }

    cout << sol << endl;
}