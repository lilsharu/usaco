#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define ff0r(i, a) ffor(i, 0, a)
#define rrof(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define rr0f(i, a) rrof(i, 0, a)
#define trav(a, x) for (auto& a : x)
#define fforn ff0r(i, n)

#define read(a) \
    int(a);     \
    cin >> (a)
#define read2(a, b) \
    read(a);        \
    read(b)

#define endl '\n'
#define f first
#define s second

#define sqr(a) (a) * (a)

void setIO(const string& name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("cbarn");

    int n;
    cin >> n;

    vi v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    int start = -1;

    for (int i = 0; i < n && start == -1; i++) start = v[i] > 1 ? i : -1;

    if (start == -1) {
        cout << 0 << endl;
        return 0;
    }

    queue<int> q;
    int time = 0;
    while (v[start]--) q.push(time);

    vector<bool> vis(n);
    vis[start] = true;
    int visTot = n - 1;

    int totCost = 0;
    // Cycle through while we have at least one with no cows
    for (int i = start + 1; visTot; i = (i + 1) % n) {
        time++;
        if (!vis[i]) {
            if (!q.empty()) {
                while (v[i]--) {
                    q.push(time);
                }
                int cur = q.front();
                q.pop();
                totCost += sqr(time - cur);
                v[i]++;
            } else
                while (v[i]--) q.push(time);

            vis[i] = v[i];
            visTot -= vis[i];
        }
    }

    cout << totCost << endl;
}