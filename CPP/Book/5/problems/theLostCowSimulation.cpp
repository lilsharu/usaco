#include <bits/stdc++.h>

using namespace std;

int x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    
    cin >> x >> y;

    int prevPos = x, currentPos = x + 1, toChange = 1, distance = 0;

    while (!(y >= min(prevPos, currentPos) && y <= max(prevPos, currentPos))) {
        distance += abs(prevPos - currentPos);
        prevPos = currentPos;
        currentPos = x + (toChange *= -2);
    }

    distance += abs(prevPos - y);

    cout << distance;
}
