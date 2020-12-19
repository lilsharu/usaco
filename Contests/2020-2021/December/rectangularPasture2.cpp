#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n';

int n;

vpii v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    v = *new vpii(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(all(v));
    
    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i].second > v[j].second) {
                v.pb(pii(v[i].second, v[j].first));
                for (int k = 0; k < v.size() - 1; k++) {
                    if (
                        v[k].second <= v[i].second &&
                        v[k].first <= v[j].first &&
                        v[k].second >= v[j].second &&
                        v[k].first >= v[i].second
                    )
                    total--;
                }
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            total++;
        }
    }

    cout << total << endl; 
}