#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int n;

struct cow {
    int x, y;

    bool equals(cow a) {
        return x == a.x && y == a.y;
    }

    cow(int a, int b) {
        x = a;
        y = b;
    }

    cow() {

    }
};

bool cowSortY(cow a, cow b) {
    return a.y < b.y;
}

bool cowSortX(cow a, cow b) {
    return a.x < b.x;
}

int xmax = 0, ymax = 0, xmin = 40001, ymin = 40001;

int calcArea(int xmin, int ymin, int xmax, int ymax) {
    return (xmax - xmin) * (ymax - ymin);
}

int calcAreaWithRemoved(vector<cow> cows, cow e1, cow e2, cow e3) {
    int area = 40000 * 40000;
    int xmin = 40001, ymin = 40001, xmax = -1, ymax = -1;

    for (cow c : cows) {
        if (c.equals(e1) || c.equals(e2) || c.equals(e3)) continue;
        xmax = max(xmax, c.x);
        xmin = min(xmin, c.x);
        ymax = max(ymax, c.y);
        ymin = min(ymin, c.y);
    }

    return calcArea(xmin, ymin, xmax, ymax);
}

int checkArea3(vector<cow> c, cow e1, cow e2) {
    cow minX(40001, 40001);
    int minXVal = 40001;
    for (int i = 0; i < n; i++) {
        if (c[i].x < minXVal && !(c[i].equals(e1) || c[i].equals(e2))) {
            minX = c[i];
            minXVal = c[i].x;
        }
    }

    cow maxX(-1, -1);
    int maxXVal = -1;
    for (int i = 0; i < n; i++) {
        if (c[i].x > maxXVal && !(c[i].equals(e1) || c[i].equals(e2))) {
            maxX = c[i];
            maxXVal = c[i].x;
        }
    }
    
    cow minY(40001, 40001);
    int minYVal = 40001;
    for (int i = 0; i < n; i++) {
        if (c[i].y < minYVal && !(c[i].equals(e1) || c[i].equals(e2))) {
            minY = c[i];
            minYVal = c[i].y;
        }
    }

    cow maxY(-1, -1);
    int maxYVal = -1;
    for (int i = 0; i < n; i++) {
        if (c[i].y > maxYVal && !(c[i].equals(e1) || c[i].equals(e2))) {
            maxY = c[i];
            maxYVal = c[i].y;
        }
    }

    return min(calcAreaWithRemoved(c, e1, e2, minX), min(calcAreaWithRemoved(c, e1, e2, maxX), min(calcAreaWithRemoved(c, e1, e2, minY), calcAreaWithRemoved(c, e1, e2, maxY))));
}

int checkArea2(vector<cow> c, cow e1) {
    cow minX(40001, 40001);
    int minXVal = 40001;
    for (int i = 0; i < n; i++) {
        if (c[i].x < minXVal && !c[i].equals(e1)) {
            minX = c[i];
            minXVal = c[i].x;
        }
    }

    cow maxX(-1, -1);
    int maxXVal = -1;
    for (int i = 0; i < n; i++) {
        if (c[i].x > maxXVal && !c[i].equals(e1)) {
            maxX = c[i];
            maxXVal = c[i].x;
        }
    }
    
    cow minY(40001, 40001);
    int minYVal = 40001;
    for (int i = 0; i < n; i++) {
        if (c[i].y < minYVal && !c[i].equals(e1)) {
            minY = c[i];
            minYVal = c[i].y;
        }
    }

    cow maxY(-1, -1);
    int maxYVal = -1;
    for (int i = 0; i < n; i++) {
        if (c[i].y > maxYVal && !c[i].equals(e1)) {
            maxY = c[i];
            maxYVal = c[i].y;
        }
    }

    return min(checkArea3(c, e1, minX), min(checkArea3(c, e1, maxX), min(checkArea3(c, e1, minY), checkArea3(c, e1, maxY))));
}

int checkArea1(vector<cow> c) {
    cow minX = c[0];
    int minXVal = c[0].x;
    for (int i = 0; i < n; i++) {
        if (c[i].x < minXVal) {
            minX = c[i];
            minXVal = c[i].x;
        }
    }

    cow maxX = c[0];
    int maxXVal = c[0].x;
    for (int i = 0; i < n; i++) {
        if (c[i].x > maxXVal) {
            maxX = c[i];
            maxXVal = c[i].x;
        }
    }
    
    cow minY = c[0];
    int minYVal = c[0].y;
    for (int i = 0; i < n; i++) {
        if (c[i].y < minYVal) {
            minY = c[i];
            minYVal = c[i].y;
        }
    }

    cow maxY = c[0];
    int maxYVal = c[0].y;
    for (int i = 0; i < n; i++) {
        if (c[i].y > maxYVal) {
            maxY = c[i];
            maxYVal = c[i].y;
        }
    }

    return min(checkArea2(c, minX), min(checkArea2(c, maxX), min(checkArea2(c, minY), checkArea2(c, maxY))));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

    cin >> n;

    vector<cow> cows;

    for (int i = 0; i < n; i++) {
        cow c;
        cin >> c.x >> c.y;
        xmax = max(xmax, c.x);
        xmin = min(xmin, c.x);
        ymax = max(ymax, c.y);
        ymin = min(ymin, c.y);
        cows.pb(c);
    }

    cout << checkArea1(cows) << '\n';
}