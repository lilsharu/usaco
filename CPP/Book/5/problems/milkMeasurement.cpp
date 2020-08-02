#include <bits/stdc++.h>

using namespace std;

#define Bc "Bessie"
#define Ec "Elsie"
#define Mc "Mildred"

const int MAX_N = 100;

struct change {
    int day = 101;
    int change;
    int cow; //0 Bessie, 1 Elsie, 2 Mildred
};

bool operator < (const change& a, const change& b) {
    return a.day < b.day;
}

bool comp(int a, int b) {
    return a < b;
}

int n;
change cows[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        change c;
        string cowName;
        cin >> c.day >> cowName >> c.change;

        if (cowName == Bc) c.cow = 0;
        else if (cowName == Ec) c.cow = 1;
        else c.cow = 2;

        cows[i] = c;
    }

    sort(cows, cows + n);

    int numChanges = 0;
    
    int prevMax = 1 + 3 + 5;
    int val[] = {7, 7, 7};

    for (int i = 0; i < n; i++) {
        int currentMax = 0;
        val[cows[i].cow] += cows[i].change;

        int maximum = max(val[0], max(val[1], val[2]));

        if (maximum == val[0]) currentMax += 1;
        if (maximum == val[1]) currentMax += 3;
        if (maximum == val[2]) currentMax += 5;

        if (currentMax != prevMax) {
            numChanges++;
            prevMax = currentMax;
        }
    }

    cout << numChanges << '\n';
}
