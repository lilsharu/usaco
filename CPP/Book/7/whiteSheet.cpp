#include <bits/stdc++.h>

#define y1 y12345

using namespace std;

bool contains(int x, int y, int x1, int y1, int x2, int y2) {
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    int x5, y5, x6, y6;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    bool bL = 0;
    bool tL = 0;
    bool bR = 0;
    bool tR = 0;

    string output = "YES";
    
    if (contains(x1, y1, x3, y3, x4, y4)) bL = true;
    if (contains(x1, y2, x3, y3, x4, y4)) tL = true;
    if (contains(x2, y1, x3, y3, x4, y4)) bR = true;
    if (contains(x2, y2, x3, y3, x4, y4)) tR = true;

    if (bL && tL && bR && tR) {
        cout << "NO\n";
        return 0;
    }

    bL = 0;
    tL = 0;
    bR = 0;
    tR = 0;
    
    if (contains(x1, y1, x5, y5, x6, y6)) bL = true;
    if (contains(x1, y2, x5, y5, x6, y6)) tL = true;
    if (contains(x2, y1, x5, y5, x6, y6)) bR = true;
    if (contains(x2, y2, x5, y5, x6, y6)) tR = true;
    
    if (bL && tL && bR && tR) {
        cout << "NO\n";
        return 0;
    }

    int cx1, cy1, cx2, cy2;
        
    //Need to check if the two black boxes are connected horizontally
    if (x3 <= x6 && x4 > x6) {
        cx1 = x5;
        cx2 = x4;
        cy1 = max(y5, y3);
        cy2 = min(y6, y4);

        if (contains(x1, y1, cx1, cy1, cx2, cy2)
        && contains (x1, y2, cx1, cy1, cx2, cy2)
        && contains(x2, y1, cx1, cy1, cx2, cy2)
        && contains(x2, y2, cx1, cy1, cx2, cy2)) {
            output = "NO";
        }
    } else if (x5 <= x4 && x6 > x4) {
        cx1 = x3;
        cx2 = x6;
        cy1 = max(y5, y3);
        cy2 = min(y6, y4);

        if (contains(x1, y1, cx1, cy1, cx2, cy2)
        && contains (x1, y2, cx1, cy1, cx2, cy2)
        && contains(x2, y1, cx1, cy1, cx2, cy2)
        && contains(x2, y2, cx1, cy1, cx2, cy2)) {
            output = "NO";
        }
    }

    //Now checks vertically
    if (y5 <= y4 && y6 > y4) {
        cy1 = y3;
        cy2 = y6;
        cx1 = max(x3, x5);
        cx2 = min(x4, x6);
        
        if (contains(x1, y1, cx1, cy1, cx2, cy2)
        && contains (x1, y2, cx1, cy1, cx2, cy2)
        && contains(x2, y1, cx1, cy1, cx2, cy2)
        && contains(x2, y2, cx1, cy1, cx2, cy2)) {
            output = "NO";
        }
    } else if (y3 <= y6 && y4 > y6) {
        cy1 = y5;
        cy2 = y4;
        cx1 = max(x3, x5);
        cx2 = min(x4, x6);
        
        if (contains(x1, y1, cx1, cy1, cx2, cy2)
        && contains (x1, y2, cx1, cy1, cx2, cy2)
        && contains(x2, y1, cx1, cy1, cx2, cy2)
        && contains(x2, y2, cx1, cy1, cx2, cy2)) {
            output = "NO";
        }
    }

    printout: cout << output << '\n';
}