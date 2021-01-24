#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define all(x) x.begin(), x.end()

#define endl '\n'

int n;

vector<pii> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if (n <= 2) {
        cout << floor(pow(2, n) + 0.5) << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.pb(pii(x, y));
    }

    ll total = 0;
    
    sort(all(v));

    pii minX = v[0];
    pii maxX = v[n - 1];

    sort(all(v), [](const pii &a, const pii &b) {
        return a.second < b.second
	     || (!(b.second < a.second) && a.first < b.first);
    });

    pii minY = v[0];
    pii maxY = v[n - 1];

    if (v[0].first != minX.first) {
        pii toAdd(minX.first, minY.second); 
        v.pb(toAdd);
        
        int toSubtract = -1;
        pii otherEnd(minY.first, minX.second);

        for (int i = 0; i < v.size(); i++) {
            if (v[i].first >= toAdd.first && v[i].first <= otherEnd.first && v[i].second >= toAdd.second && v[i].second <= otherEnd.second) {
                toSubtract++;
            } 
        }

        total -= toSubtract;
    }

    if (v[n - 1].first != maxX.first) {
        pii toAdd(maxX.first, maxY.second);
        v.pb(toAdd);
        
        int toSubtract = -1;
        pii otherEnd(maxY.first, maxX.second);

        for (int i = 0; i < v.size(); i++) {
            if (v[i].first >= otherEnd.first && v[i].first <= toAdd.first && v[i].second >= otherEnd.second && v[i].second <= toAdd.second) {
                toSubtract++;
            } 
        }
    }

    sort(all(v));

    for (int i = 0; i < v.size(); i++) {
        for (int k = i + 1; k < v.size(); k++) {
            total++;
        }
    }

    total += 1 + n;

    cout << total << endl;
}