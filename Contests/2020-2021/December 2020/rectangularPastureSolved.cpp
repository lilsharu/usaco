#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define FORN FOR(i, 0, n)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define ROFN ROF(i, 0, n)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n';

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
int sum[5001][5001];

int main() {
    setIO();
    cin >> n;

    vpi val(n);

    for (int i = 0; i < n; i++) {
        cin >> val[i].f >> val[i].s;
    }

    sort(all(val), [](const pii &a, const pii &b) {
        return a.s < b.s
	     || (!(b.s < a.s) && a.f < b.f);
    });

    for(int i = 1; i < n + 1; i++) {
        val[i - 1].s = i;
    }
    
    sort(all(val));

    for(int i = 1; i < n + 1; i++) {
        val[i - 1].f = i;
    }
    
    for (auto &a : val) {
        sum[a.f][a.s]++;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    
    ll ans = n + 1;

    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int maxX = max(val[i].f, val[j].f);
            int minX = min(val[i].f, val[j].f);
            int maxY = max(val[i].s, val[j].s);
            int minY = min(val[i].s, val[j].s);

            int top = sum[maxX][n] - sum[maxX][maxY - 1] - sum[minX - 1][n] + sum[minX - 1][maxY - 1];
            int bottom = sum[maxX][minY] - sum[maxX][0] - sum[minX - 1][minY] + sum[minX - 1][0];
            
            ans += (top) * (bottom);
        }
    }

    cout << ans << endl;
}