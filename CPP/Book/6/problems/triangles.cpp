#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

int n, x[MAX_N], y[MAX_N];

int area(int x1, int x2, int x3, int y1, int y2, int y3) {
    return abs((x1*y2 + x2*y3 + x3*y1) - (x1*y3 + x2 * y1 + x3 * y2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            for (int j = k + 1; j < n; j++) {
                if ((x[i] == x[j] && (y[i] == y[k] || y[j] == y[k])) || (x[i] == x[k] && (y[i] == y[j] || y[k] == y[j])) || (x[j] == x[k] && (y[i] == y[j] || y[i] == y[k]))) {
                    maxArea = max(maxArea, area(x[i], x[j], x[k], y[i], y[j], y[k]));
                }
            }
        }
    }

    cout << maxArea;
}
