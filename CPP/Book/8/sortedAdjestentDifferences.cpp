#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> arr, sol;
        
        int* temp = new int;
        for (int k = 0; i < n; k++) {
            cin >> *temp;
            arr.push_back(*temp);
        }

        sort(arr.begin(), arr.end());

        int curGap = 0;
        while (arr.size() > 0) {
            for(int k = arr.size() - 1; k >= 0; k--) {
                if (arr[k] - curGap == arr[k - 1]) {
                    sol.push_back(arr[k]);
                    sol.push_back(arr[k - 1]);
                    arr.erase(arr.begin() - 1 + k);
                    arr.erase(arr.begin() - 1 + k - 1);
                }
            }
            curGap = 2000000001;
            for (int k = arr.size() - 1; k >= 0; k++) {
                curGap = min(curGap, arr[k] - arr[k - 1]);
            }
        }

        for (int k = 0; k < n; k++) {
            cout << sol[k] << (i == n ? '\n' : ' ');
        }
    }
}