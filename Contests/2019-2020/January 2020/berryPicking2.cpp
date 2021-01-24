#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n'
#define f first
#define s second

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

// 11 / 11

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    setIO("berries");

    int n, k;
    cin >> n >> k;

    vi b(n);

    int maximum = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        maximum = max(maximum, b[i]);
    }

    int sol = 0;

    for (int i = 1; i <= maximum; i++) {
        vi chunks(i + 1);
        for (int j = 0; j < n; j++) {
            chunks[i] += b[j] / i;
            chunks[b[j] % i]++;
        }

        if (chunks[i] <= k >> 1) {
            break;
        }

        int btotal = 0;
        chunks[i] -= (k >> 1);

        int counted = 0;
        for (int j = i; j >= 0 && counted <= k >> 1; j--) {
            btotal += j * min((k >> 1) - counted, chunks[j]);
            counted += min((k >> 1) - counted, chunks[j]);
        }

        sol = max(sol, btotal);
    }

    cout << sol << endl;
}