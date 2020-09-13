#include <bits/stdc++.h>

#define vi vector<int>
#define pb push_back

using namespace std;

int indexUp(vi arr, int toBeat) {
    if (arr.size() == 1 || arr.size() == 0) return 0;
    if (arr.size() == 2) return 1;
    if (arr.size() == 3) return 2;
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

    vi elsie(n), bessie(n), calculator(n);

    int temp; 
    for (int i = 0; i < n; i++) {
        cin >> temp;
        elsie[i] = temp;
        calculator[i] = temp;
    }
    sort(calculator.begin(), calculator.end());

    int eIndex = 0, bIndex = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (calculator[eIndex] == i) {
            eIndex++;
        } else {
            bessie[bIndex++] = i;
        }
    }

    int points = 0;
    for (int i = 0; i < n; i++) {
        int elsieCard = elsie[i];
        int index = indexUp(bessie, elsieCard);
        if (!(index - 1 >= bessie.size()) && bessie[index - 1] > elsieCard) {
            bessie.erase(bessie.begin() + index - 1);
            points++;
        } else if (!(index >= bessie.size()) && bessie[index] > elsieCard) {
            bessie.erase(bessie.begin() + index);
            points++;
        } else if (!(index + 1 >= bessie.size()) && bessie[index + 1] > elsieCard) {
            bessie.erase(bessie.begin() + index + 1);
            points++;
        } else {
            bessie.erase(bessie.begin());
        }
    }

    cout << points << '\n';
}