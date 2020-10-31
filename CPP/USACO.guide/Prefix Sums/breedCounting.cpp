#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

int N, Q, prefix[3][100001];

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("bcount");

    cin >> N >> Q;

    prefix[0][0] = 0; 
    prefix[1][0] = 0; 
    prefix[2][0] = 0; 

    for (int i = 1; i < N + 1; i++) {
        int t;
        cin >> t;
        t--;
        prefix[t][i] = prefix[t][i - 1] + 1;
        prefix[(t + 1) % 3][i] = prefix[(t + 1) % 3][i - 1];
        prefix[(t + 2) % 3][i] = prefix[(t + 2) % 3][i - 1];
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefix[0][b] - prefix[0][a - 1] << ' ';
        cout << prefix[1][b] - prefix[1][a - 1] << ' ';
        cout << prefix[2][b] - prefix[2][a - 1] << '\n';
    }
}