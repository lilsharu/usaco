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

int main() {
    setIO("paintbarn");
    
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        barn[a][b]++;
        barn[a][d]--;
        barn[c][b]--;
        barn[c][d]++;
    }

    int solution = 0;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (i) barn[i][j] += barn[i - 1][j];
            if (j) barn[i][j] += barn[i][j - 1];
            if (i && j) barn[i][j] -= barn[i - 1][j - 1];
            if (barn[i][j] == K) solution++;
        }
    }

    cout << solution << endl;
}