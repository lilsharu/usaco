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


int main() {
    setIO("maxcross");
    
    int N, K, B;
    cin >> N >> K >> B;

    vi working(N + 1), broken(N + 1);
    vi b(B);
    
    F0R(i, B) {
        int pos;
        cin >> pos;

        b[i] = pos;     
    }

    sort(all(b));

    trav(pos, b) { 
        broken[pos] = broken[pos - 1] + 1;
    }

    FOR(i, 1, N + 1) {
        if (!broken[i]) {
            working[i] = working[i - 1] + 1;
            if (working[i] >= K) {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    int minFix = K;
    
    FOR(i, 1, N + 1) {
        int sum = 0, p = i + K - 1;
         bool w = true;
        while(p >= i) {
            if (working[p]) {
                p -= working[p];
            } else {
                sum += broken[p];
                p -= broken[p];
            }
        }

        minFix = min(minFix, sum);
    }

    cout << minFix << endl;
    return 0;
}