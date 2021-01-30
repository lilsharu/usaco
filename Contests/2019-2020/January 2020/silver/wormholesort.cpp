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

const int MX = 1e5 + 5;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

vi a, b, ind, w;
int n, m;
vi pos;

bool comp(int a, int b) {
    return w[b] < w[a];
}

struct DSU {
    vi e;
    void init(int N) {
        e = vi(N, -1);
    }

    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }

    bool sameSet(int a, int b) {
        int x = get(a);
        int y = get(b);
        return get(a) == get(b);
    }

    int size(int x) {
        return -e[get(x)];
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

bool valid(ll min) {
    DSU x;
    x.init(m);
    int i = 0;
    while (w[ind[i]] >= min) {
        int z = a[ind[i]];
        int y = b[ind[i]];
        x.unite(a[ind[i]], b[ind[i]]);
        i++;
    }
    for (int i = 0; i < n; i++) {
        if (!x.sameSet(i, pos[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setIO("wormsort");

    cin >> n >> m;
    a.resize(m);
    b.resize(m);
    ind.resize(m);
    w.resize(m);

    pos.resize(n);
    bool works = true;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
        pos[i]--;
        if (pos[i] != i) works = false;
    }

    if (works) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> w[i];
        a[i]--, b[i]--;
        ind[i] = i;
    }

    sort(all(ind), comp);

    ll c = 0, max = w[ind[0]];
    for (ll a = max; a >= 1; a = a >> 1) {
        while (valid(c + a)) c += a;
    }

    cout << c << endl;
}