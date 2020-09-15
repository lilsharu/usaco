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

    int maxTastiness = 0, pf, pb;
    
    for (int i = 0; i < n; i++) {
        int pos, taste;
        cin >> pos >> taste;

        int secs = (pos - pb) * rb;
        int secsToGo = (pos - (pf + (int)((double)secs/rf + 0.5))) * rf;

        maxTastiness += secsToGo * taste;

        pf = pos, pb = pos;
    }

    cout << maxTastiness << '\n';
}