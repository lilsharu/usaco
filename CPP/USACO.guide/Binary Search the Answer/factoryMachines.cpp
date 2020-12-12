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

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n';

int n, t;
vi v;

bool check(int s) {
    int total = 0;
    trav(x, v) {
        total += s / x; 
    }
    
    return total >= t;
}

int main() {
    cin >> n >> t;

    FORN {
        read(t);
        v.pb(t);
    }
    
    int lo = 0, hi = 2E9;
    for (hi ++; lo < hi; ) {
        int mid = lo + (hi - lo) / 2;
        check(mid) ? hi = mid : lo = mid + 1;
    }

    cout << hi << endl;
}