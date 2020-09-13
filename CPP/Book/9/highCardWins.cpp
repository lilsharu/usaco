#include <bits/stdc++.h>

#define vi vector<int>
#define pb push_back

using namespace std;

int indexUp(vi arr, int toBeat) {
    int n = 0, k = arr.size() - 1, key = n/k;
    while (n < k) {
        key = n/k;
        if (toBeat > arr[key]) {
            n = key;
        } else {
            k = key;
        }
    }

    return key;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int n;
    cin >> n;

    vi elsie(n), bessie(n);

    for (int i = 0; i < n; i++) {
        int temp; 
        cin >> temp;

        elsie[i] = temp;
    }

    int eIndex = 0, bIndex;
    for (int i = 0; i < 2 * n; i++) {
        if (elsie[eIndex] == i) {
            eIndex++;
        } else {
            bessie[bIndex++] = i;
        }
    }


}