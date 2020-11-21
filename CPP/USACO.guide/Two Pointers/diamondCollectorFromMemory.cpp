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

int main() {
    setIO("diamond");
    cin >> n >> k;
    
    int sizes[n];

    F0R(i, n) cin >> sizes[i];

    sort(sizes, sizes + n);

    vi caseMax(n);
    int r = 0;

    F0R(i, n) {
        while (r < n && sizes[r] - sizes[i] <= k) r++;
        caseMax[i] = r - i;        
    }

    vi maxSize(n + 1); 
    maxSize[n] = 0;

    R0F(i, n) {
        maxSize[i] = max(caseMax[i], maxSize[i + 1]);    
    }

    int maxInCase = 0;
    F0R(i, n) {
        maxInCase = max(maxInCase, (caseMax[i] + maxSize[i + caseMax[i]]));
    }

    cout << maxInCase << endl;
}