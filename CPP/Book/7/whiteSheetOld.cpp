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

    bool bL, bR, tR, tL;

    if (contains(x1, y1, x3, y4, x4, y4)) bL = true;
    if (contains(x1, y2, x3, y4, x4, y4)) tL = true;
    if (contains(x2, y1, x3, y4, x4, y4)) bR = true;
    if (contains(x2, y2, x3, y4, x4, y4)) tR = true;

    if (bL && bR && tR && tL) {
        cout << "YES" << '\n';
    }

    if (contains(x1, y1, x5, y5, x6, y6)) bL = true;
    if (contains(x1, y2, x5, y5, x6, y6)) tL = true;
    if (contains(x2, y1, x5, y5, x6, y6)) bR = true;
    if (contains(x2, y2, x5, y5, x6, y6)) tR = true;

    string output = "YES";
    if (bL && bR && tR && tL) {
        if (x3 <= x1 && x4 >= x2 && y3 <= y2 && y4 >= y2) {
            if (!((y6 >= y4 && y5 <= y1) || y3 <= y1)) {
                output = "NO";
            } 
        } else if (x3 <= x1 && x4 >= x1) {

        }
    }

    cout << output << '\n';
}