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

// Scores 3/10
int main() {
    setIO("paintbarn");
    cin >> N >> K;

    int count = 0;

    int xMin = 1001, xMax = 0, yMin = 1001, yMax = 0; 
    F0R(i, N) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        xMin = min(x1, xMin);
        xMax = max(x2, xMax);
        yMin = min(y1, yMin);
        yMax = max(y2, yMax);

        FOR(j, x1, x2) {
            FOR(k, y1, y2) {
                barn[j][k]++;
            }
        }
    }

    FOR(i, xMin, xMax) {
        FOR(j, yMin, yMax) {
            if (barn[i][j] == K) {
                count++;
            }
        }
    }

    cout << count << endl;
}