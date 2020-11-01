#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

const int MX = 1000005;

int n;
int prefix[MX];
set<int> ids = {0};
map<int, int> pos;

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("div7");

    cin >> n;

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        prefix[i + 1] = (prefix[i] + val) % 7;

        if (ids.count(prefix[i + 1])) {
            int distance = (i - pos[prefix[i + 1]]);
            maxLen = max(maxLen, distance);
        } else {
            ids.insert(prefix[i + 1]);
            pos[prefix[i + 1]] = i;
        }
    }

    cout << maxLen << '\n';
}