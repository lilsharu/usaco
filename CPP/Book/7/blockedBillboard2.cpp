#include <bits/stdc++.h>

using namespace std;

int ax1, ax2, ay1, ay2;
int bx1, bx2, by1, by2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by1;

    //First check if any portion is fully covered
    int tarpArea = (abs(ay2 - ay1) * abs(ax2 - ax1));
    if (by2 >= ay2 && by1 <= ay2 && (bx1 <= ax1 || bx2 >= ax2)) {
        if (bx2 <= ax2) {
            //left
            tarpArea = (abs(ay2 - ay1) * abs(ax2 - bx2));
        }
        else {
            tarpArea = (abs(ay2 - ay1) * abs(bx1 - ax1));
        }
    } else if (bx2 >= ax2 && bx1 <= ax1 && (by1 <= ay1 || by2 >= ay2)) {
        if (by1 <= ay1) {
            //bottom
            tarpArea = (abs(ay2 - by2) * abs(ax2 - ax1));
        }
        else {
            tarpArea = (abs(ay1 - by1) * abs(ax2 - bx1));
        }
    }

    cout << tarpArea << '\n';
}