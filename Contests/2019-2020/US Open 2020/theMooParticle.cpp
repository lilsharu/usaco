#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'
#define f first
#define s second

#define MAXN 100001

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int id[MAXN];
int x[MAXN], y[MAXN];
int miny[MAXN], maxy[MAXN];

bool cmp(int a, int b) {
    return x[a] < x[b] || x[a] == x[b] && y[a] < y[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setIO("moop");

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        id[i] = i;
    }

    sort(id, id + n, cmp);

    miny[0] = y[id[0]];
    for (int i = 1; i < n; i++) {
        miny[i] = min(miny[i - 1], y[id[i]]);
    }

    maxy[n - 1] = y[id[n - 1]];
    for (int i = n - 2; i >= 0; i--) {
        maxy[i] = max(maxy[i + 1], y[id[i]]);
    }

    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (miny[i] > maxy[i + 1]) ans++;
    }

    cout << ans << endl;
}