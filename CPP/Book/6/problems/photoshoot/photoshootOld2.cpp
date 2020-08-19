#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;

int n, b[MAX_N - 1], a[MAX_N];

bool works(int sum, int i, int n) {
    if (sum >= b[i]) {
        return false;
    }
    if (i == n) {
        return true;
    }
    return(b[i] - sum, ++i, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("photo.in", "r", stdin);
    //freopen("photo.out", "w", stdout);

    cin >> n;
    vector<int> v;
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
        v.push_back(i + 1);
    }
    v.push_back(v.back() + 1);

    do {
        if (works(v.at(0), 0, n)) {
            break;
        }   
    } while (next_permutation(v.begin(), v.end()));

    for (int i = 0; i < n; i++) {
        cout << v.at(i) << " ";
    }
}
