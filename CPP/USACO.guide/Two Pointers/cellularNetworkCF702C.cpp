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

#define dist(a, b) abs((a) - (b))

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
    int n, m;
    cin >> n >> m;
    
    vi cities(n);
    vi towers(m);
    
    F0R(i, n) {
        cin >> cities[i];
    }
    
    F0R(i, m) {
        cin >> towers[i];
    }
    
    sort(all(cities));
    sort(all(towers));

    {
        auto temp = unique(all(cities));
        cities.erase(temp, cities.end());

        temp = unique(all(towers));
        towers.erase(temp, towers.end());
    }

    int t = 0;
    int sol = -1;
    F0R(c, n) {
        int cDist = dist(cities[c], towers[t]);

        while (t + 1 < m && dist(cities[c], towers[t + 1]) < cDist) {
            cDist = dist(cities[c], towers[++t]);   
        }

        sol = max(sol, cDist);
    }

    cout << sol << endl;
}