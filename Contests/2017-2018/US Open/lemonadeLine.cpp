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
    setIO("lemonade");

    int n;
    cin >> n;

    vi vals(n);

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        vals[i] = -t;
    }
    
    sort(all(vals));
    
    vi positions;
    int i;
    for(i = 0; -vals[i] >= positions.size(); i++) {
        positions.pb(vals[i]);
    } 
    
    cout << i << endl;
}