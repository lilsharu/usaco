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
    setIO("highcard");

    int n;
    cin >> n;

    vector<bool> ecard((n << 1) + 1);

    for (int i = 0; i < n; i++) {
        read(x);
        ecard[x] = 1;
    }

    vi bessie, elsie;

    for (int i = 1; i <= n; i++) {
        if (ecard[i]) {
            elsie.pb(i);
        } else {
            bessie.pb(i);
        }
    }

    int j = 0, total = 0;
    for (int i = 0; i < n && j < n; i++) {
        while (j + 1 < n && bessie[j + 1] < elsie[i]) j++;
        if (j < n && bessie[j] > elsie[i]) {
            total++;
        }
    }

    cout << total << endl;
}