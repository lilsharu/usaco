#include <bits/stdc++.h>

using namespace std;

struct constraint {
    string a, b;
};

int n;
constraint c[7];
string cows[] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string* trash = new string;
        cin >> c[i].a >> *trash >> *trash >> *trash >> *trash >> c[i].b;
        delete trash;
    }

    do {
        bool works = true;
        for (int i = 0; i < n; i++) {
            cout << c[i].a;
            cout << cows->find(c[i].a);
            cout << cows[cows->find(c[i].a)] << '\n';
            if (cows[cows->find(c[i].a) - 1] != c[i].b || cows[cows->find(c[i].a) + 1] != c[i].b) {
                works = false;
                break;
            }
        }

        if (works) {
            break;
        }

    } while (next_permutation(cows, cows + n));

    for (int i = 0; i < 8; i++) {
        cout << cows[i] << '\n';
    }
}
