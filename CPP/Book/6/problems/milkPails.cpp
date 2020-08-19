#include <bits/stdc++.h>

using namespace std;

int x, y, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> x >> y >> m;

    int filled = 0, total = m;

    int minTimes = total / y;
    int maxTimes = total / x;

    for (int i = 0; i < maxTimes; i++) {
        int part1 = x * i;
        int other = total - part1;
        int part2 = other - (other % y);
        filled = max(filled, part1 + part2);
    }
    for (int i = 0; i < minTimes; i++) {
        int part1 = y * i;
        int other = total - part1;
        int part2 = other - (other % x);
        filled = max(filled, part1 + part2);
    }



    cout << filled;
}
