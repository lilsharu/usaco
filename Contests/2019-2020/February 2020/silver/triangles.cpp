#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef pair<ll, ll> pll;


#define FOR(i, a, b)    for (int i = (a); i < (b); ++i)
#define F0R(i, a)       FOR(i, 0, a)
#define FORN            FOR(i, 0, n)
#define ROF(i, a, b)    for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a)       ROF(i, 0, a)
#define ROFN            ROF(i, 0, n)
#define trav(a, x)      for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'
#define f first
#define s second

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct indexedPair {
    pll p;
    int i;

    ll second;
    ll first;

    indexedPair() {
        p = pii();
        i = -1;;
    }

    indexedPair(const pii &pair, int index) {
        p = pair;
        i = index;
        second = pair.s;
        first = pair.f;
    }
};

bool sortBySecondTerm(const indexedPair &a, const indexedPair &b) {
    if (a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

bool sortByFirstTerm(const indexedPair &a, const indexedPair &b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}


int n;
vector<indexedPair> vals;

int main() {
    setIO("3");
    cin >> n;

    vals.resize(n);

    FORN {
        read2(x, y);
        vals[i] = indexedPair(pii(x + (int) 10E4, y + (int) 10E4), i);
    }

    // Sort By X
    sort(all(vals), sortByFirstTerm);

    vll xSum(n);
    vll ySum(n);

    for (int i = 0; i < n; i++) {
        int j = i;
        while (vals[j + 1].f == vals[i].f) j++;

        if (j == i) continue;

        for (int x = i; x < j; x++) {
            xSum[vals[i].i] += abs(vals[j].s - vals[x].s);
        }

        for (int x = i + 1; x <= j; x++) {
            xSum[vals[x].i] = xSum[vals[x-1].i];
            xSum[vals[x].i] += (x - i) * (vals[x].s - vals[x - 1].s);
            xSum[vals[x].i] -= (j + 1 - x)  * (vals[x].s - vals[x - 1].s);
        }

        i = j;
    }

    sort(all(vals), sortBySecondTerm);

    for (int i = 0; i < n; i++) {
        int j = i;
        while (vals[j + 1].s == vals[i].s) j++;

        if (j == i) continue;

        for (int x = i; x < j; x++) {
            ySum[vals[i].i] += abs(vals[j].f - vals[x].f);
        }

        for (int x = i + 1; x <= j; x++) {
            ySum[vals[x].i] = ySum[vals[x-1].i];
            ySum[vals[x].i] += (x - i) * (vals[x].f - vals[x - 1].f);
            ySum[vals[x].i] -= (j + 1 - x)  * (vals[x].f - vals[x - 1].f);
        }

        i = j;
    }

    ll total = 0;

    for (int i = 0; i < n; i++) {
        total += xSum[vals[i].i] * ySum[vals[i].i];
        total %= ((int) 10E9 + 7);
    }

    cout << total << endl;
}