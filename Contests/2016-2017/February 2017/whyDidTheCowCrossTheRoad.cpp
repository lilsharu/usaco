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

bool sorter(const pii &a, const pii &b) {
    return a.f - a.s < b.f - b.s;
}

// 3 / 10

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setIO("helpcross");

    int c, n;
    cin >> c >> n;

    vi chickens(c);
    vpi cows(n);

    for (int i = 0; i < c; i++) {
        cin >> chickens[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> cows[i].f >> cows[i].s;
    }

    sort(all(chickens));
    sort(all(cows), sorter);

    int total = 0;

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < n; i++) {
            if (chickens[j] >= cows[i].f && chickens[j] <= cows[i].s) {
                total++;
                cows.erase(cows.begin() + i);
                j++;
                i = -1;
            }
        }
    }

    cout << total << endl;
}