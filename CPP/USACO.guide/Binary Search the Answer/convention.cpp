#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define FORN FOR(i, 0, n)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define ROFN ROF(i, 0, n)
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

int n, m, c, ttop, tbottom;
vi cows;

bool checkTime(int tmax) {
    int i = 0;
    int mm = m;
    priority_queue<int> pq;
    for (int t = tbottom; t < ttop; t++) {
        while (cows[i] <= t) pq.push(-cows[i++]);
        if (pq.size() > 0) {
            if ((pq.size() >= c || t + pq.top() == tmax || t == ttop)) {
                mm--;
                int i = pq.size();
                while (pq.size() > 0 && i - pq.size() < c) {
                    pq.pop(); 
                }
            }
            if (t + pq.top() > tmax || !mm) return false; 
        }
    }

    return true;
}

int main() {
    setIO("convention");
    
    cin >> n >> m;
    cin >> c;

    F0R(i, n) {
        int t;
        cin >> t;
        cows.pb(t);
    }

    sort(all(cows));
    ttop = cows[n - 1];
    tbottom = cows[0];

    int x;
    cin >> x;

    bool a = checkTime(x);

    cout << a ? 1 : 0;
}