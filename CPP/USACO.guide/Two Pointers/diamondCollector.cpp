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

    vi arr(n);
    
    F0R(i, n) cin >> arr[i];

    sort(all(arr));

    int i = 0, j = 0;
    
    int sumA = 0, sumB = 0;

    for (i = 0; i < n; i++) {
        if (arr[j] - arr[i] > k) {
            if (j - i > sumA) {
                sumA = j - i;
            } else if (j - i > sumB) sumB = j - 1;

            i++;
        } 
        if (arr[j] - arr[i] <= k) j++;
    }

    cout << sumA + sumB << endl;
}