#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    set<int> boxers;

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    
    for (auto temp : arr) {
        if (boxers.count(max(1, temp - 1)) != 0) {
            if (boxers.count(temp) != 0) {
                boxers.insert(temp + 1);
            } else {
                boxers.insert(temp);
            }
        } else {
            boxers.insert(max(1, temp - 1));
        }
    }

    cout << boxers.size() << '\n';
}