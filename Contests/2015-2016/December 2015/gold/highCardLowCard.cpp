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

// 15 / 15

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setIO("cardgame");

    read(n);

    vi e1(n >> 1), e2(n >> 1), b1(n >> 1), b2(n >> 1);

    vector<bool> taken((n << 1) + 1);

    for (int i = 0; i < n >> 1; i++) {
        cin >> e1[i];
        taken[e1[i]] = 1;
    }

    for (int i = 0; i < n >> 1; i++) {
        cin >> e2[i];
        taken[e2[i]] = 1;
    }

    int bnum = 0, bi = 0;
    vi *x = &b2;

    for (int i = 1; i <= n << 1; i++) {
        if (!taken[i]) {
            (*x)[bi++] = i;
        }
        if (bi == n >> 1) {
            x = &b1;
            bi = 0;
        }
    }

    sort(all(b1));
    sort(all(b2));
    sort(all(e1));
    sort(all(e2));

    int total = 0;

    int bind = 0, eind = 0;
    while (bind < n >> 1 && eind < n >> 1) {
        if (b1[bind++] > e1[eind]) {
            total++;
            eind++;
        }
    }

    bind = (n >> 1) - 1, eind = (n >> 1) - 1;
    while (bind >= 0&& eind >= 0) {
        if (b2[bind--] < e2[eind]) {
            total++;
            eind--;
        }
    }

    cout << total << endl;
}