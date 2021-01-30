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

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setIO("berries");

    int n, k;
    cin >> n >> k;

    int m = 0;

    vi sz(n);
    for (int i = 0; i < n; i++) {
        cin >> sz[i];
        m = max(m, sz[i]);
    }

    int sum = 0;

    for (int i = 1; i <= m; i++) {
        vi num(i + 1);
        for (int j = 0; j < n; j++) {
            num[i] += sz[j] / i;
            num[sz[j] % i]++;
        }

        int tot = 0, pass = 0;
        for (int j = i; j >= 1 && pass < k; j--) {
            if (pass < k >> 1) {
                int toRemove = min((k >> 1) - pass, num[j]);
                num[j] -= toRemove;
                pass += toRemove;
            }

            int times = min(k - pass, num[j]);
            tot += j * times;
            pass += times;
            num[j] -= times;
        }

        sum = max(sum, tot);
    }

    cout << sum << endl;
}