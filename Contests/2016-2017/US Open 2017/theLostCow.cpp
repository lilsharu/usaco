#include <bits/stdc++.h>

using namespace std;

int x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lostcow.in", "r", stdin);
//    freopen("lostcow.out", "w", stdout);

    cin >> x >> y;
    
    int val = 1, valPrevious = 0, totalCount = 0;

    while((x > y && !(x - val < y)) || (x < y && !(x + val > y))) {
        val *= -2;
        totalCount += abs(val) + abs(valPrevious);
        valPrevious = val;
    }

    cout << totalCount;
}
