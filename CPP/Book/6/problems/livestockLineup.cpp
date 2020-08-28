#include <bits/stdc++.h>

using namespace std;


int n;
vector<string> cows, beside_a, beside_b;

int where(string s) {
    for(int i = 0; i < 8; i++) {
        if (cows[i] == s) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    cows.push_back("Beatrice");
    cows.push_back("Sue");
    cows.push_back("Belinda");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Blue");
    cows.push_back("Bella");
    cows.push_back("Buttercup");
    sort(cows.begin(), cows.end());

    cin >> n;

    string* trash = new string;
    string* a = new string;
    string* b = new string;
    for (int i = 0; i < n; i++) {
        cin >> *a;
        cin >> *trash; //must
        cin >> *trash; //be
        cin >> *trash; //milked
        cin >> *trash; //beside
        cin >> *b;
        beside_a.push_back(*a);
        beside_b.push_back(*b);
    }
    delete trash;
    delete a;
    delete b;

    do {
        bool works = true;
        for (int i = 0; i < n; i++) {
            if (abs(where(beside_a[i]) - where(beside_b[i])) != 1) {
                works = false;
                break;
            }
        }

        if (works) {
            break;
        }

    } while (next_permutation(cows.begin(), cows.end()));

    for (int i = 0; i < 8; i++) {
        cout << cows[i] << '\n';
    }
}
