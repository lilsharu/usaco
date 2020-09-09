
#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    for (int x = 0; x < t; x++) {
        int n; 
        cin >> n;

        vector<int> arr, sol;

        int* temp = new int;
        for(int i = 0; i < n; i++) {
            cin >> *temp;
            arr.push_back(*temp);
        }
        delete temp;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n/2.0 + 0.5; i++) {
            sol.push_back(arr[i]);
            sol.push_back(arr[n - i - 1]);
        }

        for (int i = n - 1; i >= 0; i--) {
            cout << sol[i] << (i == 0 ? '\n' : ' ');
        }
    }
}