#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;

int n;
vector<int> r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        r.push_back(temp);
    }
    
    int maxTotalDistance = INT_MAX;

    for (int i = 0; i < n; i++) {
        r.insert(r.begin(), r.back());
        r.pop_back();

        int distance = 0;

        for (int i = 0; i < n; i++) {
            distance += r[i] * i;
        }

        maxTotalDistance = min(distance, maxTotalDistance);
    }

    cout << maxTotalDistance;
}
