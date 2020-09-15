#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    int l, n, rf, rb;
    cin >> l >> n >> rf >> rb;

    int maxTastiness = 0, pf = 0, pb = 0;
    
    for (int i = 0; i < n; i++) {
        int pos, taste;
        cin >> pos >> taste;

        int secs = (pos - pb) * rb;
        int distanceForFarmer = pos - pf;
        int secsToGo = distanceForFarmer * rf - secs;

        maxTastiness += (int) secsToGo * taste;

        pf += distanceForFarmer, pb = pos;
    }

    cout << maxTastiness << '\n';
}