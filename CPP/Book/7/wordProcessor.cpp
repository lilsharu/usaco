#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;

    cin >> n >> k;

    int currLineLength;

    string word;

    for (int i = 0; i < n; i++) {
        cin >> word;
        if (i == 0) {
            currLineLength = word.length();
            cout << word;
        } else if (currLineLength + word.length() > k) {
            currLineLength = word.length();
            cout << '\n' << word;
        } else {
            cout << ' ' << word;
            currLineLength += word.length();
        }
    }
}