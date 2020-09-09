#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("outofplace.in", "r" , stdin);
    freopen("outofplace.out", "w", stdout);

    int n, wrongIndex;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (i == 0 || arr.size() > 0 && temp != arr[arr.size() - 1]) {
            if (i != 0 && temp < arr[arr.size() - 1]) {
                wrongIndex = arr.size();
            }
            arr.push_back(temp);
        }
    }

    int count = 0; 

    while (arr[wrongIndex] < arr[wrongIndex - 1]) {
        int movement;
        for (movement = 0; arr[wrongIndex - 1] == arr[wrongIndex - 2 - movement]; movement++) {
            //Just record the movement
        }
        int temp = arr[wrongIndex];
        arr[wrongIndex] = arr[wrongIndex - 1 - movement];
        arr[wrongIndex - 1 - movement] = temp;
        wrongIndex = wrongIndex - 1 - movement;
        count++;
    }
    
    cout << count << '\n';
}