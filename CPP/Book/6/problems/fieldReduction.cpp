#include <bits/stdc++.h>
#include <climits>

using namespace std;

int n;
int y[50000], y11 = INT_MAX, y2 = INT_MAX, y3 = 0, y4 = 0;
int x[50000], x1 = INT_MAX, x2 = INT_MAX, x3 = 0, x4 = 0;

int calcArea(int x1, int x2, int y1, int y2) {
    return abs(x1 - x2) * abs(y1 - y2);
}

void update(int x, int y) {
    if (x < x1) {
        x2 = x1;
        x1 = x;
    } else if (x < x2) {
        x2 = x;
    }
    if (x > x4) {
        x3 = x4;
        x4 = x;
    } else if (x > x3) {
        x3 = x;
    }

    if (y < y11) {
        y2 = y11;
        y11 = y;
    } else if (y < y2) {
        y2 = y;
    }
    if (y > y4) {
        y3 = y4;
        y4 = y;
    } else if (y > y3) {
        y3 = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        update(x[i], y[i]);
    }

    int ans = calcArea(x1, x4, y11, y4);

    for (int i = 0; i < n; i++) {
        int xMin = x1;
        if (x[i] == x1) {
            xMin = x2;
        }
        int xMax = x4;
        if (x[i] == x4) {
            xMax = x3;
        }

        int yMin = y11;
        if (y[i] == y11) {
            yMin = y2;
        }
        int yMax = y4;
        if (y[i] == y4) {
            yMax = y3;
        }

        ans = min(calcArea(xMin, xMax, yMin, yMax), ans);
    }

    cout << ans << '\n';
}
