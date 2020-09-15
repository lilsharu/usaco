#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct specialCow {
    ll min, max;
};
bool cowComp(specialCow a, specialCow b) {
    return (a.max - a.min) < (b.max - b.min);
}


int n, c;
multiset<int> chickens;
vector<pair<int, int>> cows;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    cin >> c >> n;

    int x, y, total = 0;

    for (int i = 0; i < c; i++) {
        cin >> x;
        chickens.insert(x);
    }

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cows.push_back(pair<int, int>(y, x));
    }

    sort(cows.begin(), cows.end());

    for (int i = 0; i < n; i++) {
        auto which_chicken = chickens.lower_bound(cows[i].second);
        if (which_chicken != chickens.end() && *which_chicken <= cows[i].first) {
            total++;
            chickens.erase(which_chicken);
        }
    }

    cout << total;
}