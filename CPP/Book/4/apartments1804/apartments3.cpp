#include <bits/stdc++.h>

using namespace std;

const int MAX = 200000;

int applicants[MAX];
multiset<int> apartments;

int n, m, k;

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> applicants[i];
    }
    
    int temp = 0;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        apartments.insert(temp);
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        int applicant = applicants[i];
        int possibleHouse = *apartments.lower_bound(applicant - k);

        if (possibleHouse <= applicant + k) {
            while (abs(possibleHouse - applicant) < abs(*apartments.upper_bound(possibleHouse))) {
                possibleHouse = *apartments.upper_bound(possibleHouse);
            }

            apartments.erase(possibleHouse);
            count++;
        }
    }

    cout << count;
}
