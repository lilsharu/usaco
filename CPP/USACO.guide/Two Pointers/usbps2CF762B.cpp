#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n';

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    vi usb;
    vi ps2;

    F0R(i, m) {
        int val; string vals;
        cin >> val >> vals;

        if (vals == "USB") usb.pb(val);
        else ps2.pb(val);
    }

    sort(all(usb));
    sort(all(ps2));

    int u = 0, p = 0, cost = 0, total = 0;
    
    while (a && u < usb.size()) {
        cost += usb[u++];
        total++;
        a--;
    }
    
    while (b && p < ps2.size()) {
        cost += ps2[p++];
        total++;
        b--;
    }

    while (c && (u < usb.size() || p < ps2.size())) {
        if (u >= usb.size()) {
            cost += ps2[p++];
            total++;
            c--;
        } else if (p >= ps2.size()) {
            cost += usb[u++];
            total++;
            c--;
        } else {
            if (ps2[p] < usb[u]) {
                cost += ps2[p++];
                total++;
                c--;
            } else {
                cost += usb[u++];
                total++;
                c--;
            }
        }
    }

    cout << total << ' ' << cost << endl;
}