#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    int n; 
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (count <= arr[i]) {
            count++;
        }
    }

    cout << count << '\n';
}