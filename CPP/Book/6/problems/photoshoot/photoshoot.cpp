#include <bits/stdc++.h>

using namespace std;

int n, b[100000], ans[100000];
bool used[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        ans[0] = i;
        ans[1] = b[0] - i;

        for (int j = 2; j < n; j++) {
           ans[j] = b[j - 1] - ans[j - 1];
        }
        for (int i = 1; i <= n; i++) {
            used[i] = false;
        }
        bool bad = 0;
        for (int i = 0; i < n; i++) {
            if (used[ans[i]] || ans[i] <= 0 || ans[i] > n) {
                bad = true;
                break;
            }
            used[ans[i]] = true;
        }

        if (!bad) {
            for (int i = 0; i < n; i++) {
                cout << ans[i];
                if (i < n - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
            return 0;
        }
    }
}
