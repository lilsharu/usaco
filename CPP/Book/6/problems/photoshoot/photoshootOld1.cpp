#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;

int n, b[MAX_N - 1], a[MAX_N], sequence[MAX_N];

bool used[MAX_N];

bool test(int i) {
    int current = i;
    sequence[0] = i;
    used[i] = true;
    for (int j = 1; j < n; j++) {
        current = b[j - 1] - sequence[j - 1];

        if (current < 0 || used[current]) {
            return false;
        }
        used[current] = true;
        
        sequence[j] = current;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("photo.in", "r", stdin);
    //freopen("photo.out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    bool found = false;

    for (int i = 0; i < b[i] && !found; i++) {
        used[0] = true;
        for (int j = 1; j <= n; j++) {
            used[j] = 0;
        }
        for (int j = 1; j <= n && !found; j++) {
            found = test(j); 
        }
    }

    for (int i = 0; i < n; i++) {
        cout << sequence[i] << ' ';
    }
    cout << '\n';

}
