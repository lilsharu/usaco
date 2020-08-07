#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;

#define ll long long

ll n, m;
ll finalChoices[MAX_N];

int main() {


    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    multiset<ll> tickets;

    for (ll i = 0; i < n; i++) {
        ll temp; cin >> temp; tickets.insert(-temp);
    }

    for (ll i = 0; i < m; i++) {
        ll tempMax;
        cin >> tempMax;

        ll poss = *tickets.lower_bound(-tempMax);

        if (poss == *tickets.end() && -poss >= tempMax) {
            finalChoices[i] = -1;
        } else {
            finalChoices[i] = -poss;
            std::multiset<ll>::iterator hit(tickets.find(poss));
            if (hit != tickets.end()) {
                tickets.erase(hit);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << finalChoices[i] << endl;
    }
}
