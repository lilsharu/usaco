#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll x, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> n;

    set<ll> positions;
    positions.insert(0);
    positions.insert(x);
    
    ll above = x, below = 0, maxLen = x, count = 1;

    for (ll i = 0; i < n; i++) {
        ll input;
        cin >> input;
        positions.insert(input);
        
        if (input >= below && input <= above) {
            if (positions.count(input - 1) != 0 && count <= 1) {
                maxLen--;
            } else {
                count = 0;
                ll previous = *positions.begin();
                maxLen = -1;
                for (auto pos : positions) {
                    ll diff = pos - previous;

                    if (diff >= maxLen) {
                        if (diff == maxLen) count++;
                        else {
                            maxLen = diff;
                            above = pos;
                            below = previous;
                            count = 1;
                        }
                    }

                    previous = pos;
                } 
            }
        }

        cout << maxLen << ' ';
    }
}
