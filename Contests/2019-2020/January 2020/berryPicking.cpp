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

    read2(n, k);

    vi bi(n);

    vi b(k);

    for (int i = 0; i < n; i++) {
        cin >> bi[i];
    }

    sort(all(bi));

    int j = k - 1;
    for (int i = n - 1; i >= 0 && j >= 0; i--) {
        b[j--] = bi[i];
    }

    int bmax = b[(k >> 1) - 1];
    int bmin = b[0];
    int emax = b[k - 1];

    while (emax - bmax > bmin) {
        b[0] = bmax;
        b[k - 1] = emax - bmax;
        sort(all(b));
        bmax = b[(k >> 1) - 1];
        bmin = b[0];
        emax = b[k - 1];
    }

    int total = 0;
    for (int i = 0; i < k >> 1; i++) {
        total += b[i];
    }

    cout << total << endl;
}