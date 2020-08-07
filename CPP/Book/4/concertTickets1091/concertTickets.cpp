#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;

int n, m;
int finalChoices[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    multiset<int> tickets;

    for (int i = 0; i < n; i++) {
        int temp; cin >> temp; tickets.insert(-temp);
    }

    for (int i = 0; i < m; i++) {
        int tempMax;
        cin >> tempMax;

        int poss = *tickets.lower_bound(-tempMax);

        if (poss == *tickets.end() && -poss >= tempMax) {
            finalChoices[i] = -1;
        } else {
            finalChoices[i] = -poss;
            std::multiset<int>::iterator hit(tickets.find(poss));
            if (hit != tickets.end()) {
                tickets.erase(hit);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << (finalChoices[i] <= 0 ? -1 : finalChoices[i]) << endl;
    }
}
