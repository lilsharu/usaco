#include <bits/stdc++.h>

using namespace std;

bool cornerCovered(int x, int y, int bx1, int by1, int bx2, int by2) {
    return bx1 <= x && bx2 >= x && by1 <= y && by2 >= y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    
    int ax1, ax2, ay1, ay2;
    int bx1, bx2, by1, by2;

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    int coveredCorners;
    if (cornerCovered(ax1, ay1, bx1, by1, bx2, by2)) coveredCorners++;
    if (cornerCovered(ax1, ay2, bx1, by1, bx2, by2)) coveredCorners++;
    if (cornerCovered(ax2, ay2, bx1, by1, bx2, by2)) coveredCorners++;
    if (cornerCovered(ax2, ay1, bx1, by1, bx2, by2)) coveredCorners++;

    if (coveredCorners < 2) {
        cout << (ay2 - ay1) * (ax2 - ax1);
    } else if (coveredCorners == 4) {
        cout << 0;
    } else {
        // int x1 = min(ax1, bx1);
        // int y1 = min(ay1, by1);
        // int x2 = max(ax2, bx2);
        // int y2 = max(ay2, by2);
        int x1 = max(ax1, bx1);
        int y1 = max(ay1, by1);
        int x2 = min(ax2, bx2);
        int y2 = min(ay2, by2);
        
        // cout << ((x2 - x1) * (y2 - y1));
        int output = ((ay2 - ay1) * (ax2 - ax1) - (x2 - x1) * (y2 - y1));
        cout << output;
    }

    cout << '\n';

    //First check if any portion is fully covered
    // int tarpArea = (abs(ay2 - ay1) * abs(ax2 - ax1));
    // if (bx2 >= ax2 && bx1 <= ax1 && by2 >= ay2 && by1 <= ay1) {
    //     tarpArea = 0;
    // }
    // else if (by2 >= ay2 && by1 <= ay2 && (bx1 <= ax1 || bx2 >= ax2)) {
    //     if (bx2 <= ax2) {
    //         //left
    //         tarpArea = (abs(ay2 - ay1) * abs(ax2 - bx2));
    //     }
    //     else {
    //         tarpArea = (abs(ay2 - ay1) * abs(bx1 - ax1));
    //     }
    // } else if (bx2 >= ax2 && bx1 <= ax1 && (by1 <= ay1 || by2 >= ay2)) {
    //     if (by1 <= ay1) {
    //         //bottom
    //         tarpArea = (abs(ay2 - by2) * abs(ax2 - ax1));
    //     }
    //     else {
    //         tarpArea = (abs(ay1 - by1) * abs(ax2 - bx1));
    //     }
    // }

    // cout << tarpArea << '\n';
}