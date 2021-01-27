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
    setIO("measurement");

    read2(n, g);

    map<int, int> vals;

    int numChanges = 0;
    int cmax = g;
    vector<int> participants;

    vector<tuple<int, int, int>> val;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        val[i] = {a, b, c};
    }

    sort(all(val));

    int changes = 0;
    for (int i = 0; i < n; i++) {
        int cowNum = get<1>(val[i]);
        int change = get<2>(val[i]);

        if (vals.find(cowNum) == vals.end()) vals[cowNum] = g;
        if (change < 0) {
            if (participants.empty()) {
                vals[cowNum] += change;
                changes++;
            } else if (find(all(participants), cowNum) == participants.end()) {
                vals[cowNum] += change;
            } else {
                if (participants.size() == 1) {
                    vals[cowNum] += change;
                    for (auto a : vals) {

                    }
                }
            }
        }
    }
}