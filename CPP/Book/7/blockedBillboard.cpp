#include <bits/stdc++.h>

using namespace std;

int ax1, ax2, ay1, ay2; 
int bx1, bx2, by1, by2;
int tx1, tx2, ty1, ty2;

int maxArea, obscured;

int rectArea(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) * abs(y2 - y1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;
    cin >> tx1 >> ty1 >> tx2 >> ty2;

    maxArea = rectArea(ax1, ay1, ax2, ay2) + rectArea(bx1, by1, bx2, by2);

    int minY1 = max(ay1, ty1);
    int maxY1 = min(ay2, ty2);
    int minX1 = max(ax1, tx1);
    int maxX1 = min(ax2, tx2);

    int minY2 = max(by1, ty1);
    int maxY2 = min(by2, ty2);
    int minX2 = max(bx1, tx1);
    int maxX2 = min(bx2, tx2);

    obscured = rectArea(minX1, minY1, maxX1, maxY1) + rectArea(minX2, minY2, maxX2, maxY2);
    
    cout << maxArea - obscured << '\n';

    return 0;
}