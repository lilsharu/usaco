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

int N, K;
int barn[1001][1001];

// Score 10/10
int main() {
    setIO("paintbarn");
    cin >> N >> K;

    FOR(i, 0, N) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        FOR(j, a, c) {
            barn[j][b]++;
            barn[j][d]--;
        }
    }

    int count = 0;

    FOR(i, 0, 1001) {
        FOR(j, 0, 1001) {
            if (barn[i][j] == K) {
                count++;
            }
            barn[i][j + 1] += barn[i][j];
        }
    }

    cout << count << endl;
}