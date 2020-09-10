#include <bits/stdc++.h>

using namespace std;

struct mountain {
    int x, y;

    bool contains(mountain b) {
        if (b.y > y) {
            return false;
        }

        double slope = ((double)(y - b.y))/(x - b.x);

        return abs(slope) <= 1;
    }
};

bool byHeight(mountain a, mountain b) {
    return a.y < b.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int n;
    cin >> n;

    vector<mountain> arr;

    for (int i = 0; i < n; i++) {
        mountain next;
        cin >> next.x >> next.y;
        arr.push_back(next);
    }

    sort (arr.begin(), arr.end(), byHeight);

    for (int i = n - 1; i >= 0; i--) {
        for (int k = i - 1; k >= 0; k--) {
            if (arr[i].contains(arr[k])) {
                arr.erase(arr.begin() + k);
                i--;
            }
        }
    }

    cout << arr.size() << '\n';
}