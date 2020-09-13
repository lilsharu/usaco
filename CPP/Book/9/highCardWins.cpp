#include <bits/stdc++.h>

#define vi vector<int>
#define pb push_back

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int n;
    cin >> n;

    vi elsie(n), bessie(n);

    int temp; 
    for (int i = 0; i < n; i++) {
        cin >> temp;
        elsie[i] = temp;
    }

    sort(elsie.begin(), elsie.end());

    int eIndex = 0, bIndex = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (elsie[eIndex] == i) {
            eIndex++;
        } else {
            bessie[bIndex++] = i;
        }
    }
    
    int points = 0;

    int b = 0, e = 0;

    while (b < n && e < n) {
        if (bessie[b++] > elsie[e]) {
            points++;
            e++;
        }
    }

    cout << points << '\n';
}