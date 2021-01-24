#include <bits/stdc++.h>

using namespace std;

const int MAX_IN_ONE_D = 2000;

int n, s[MAX_IN_ONE_D][MAX_IN_ONE_D];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int x = 1000, y = 1000, time = 0, minx = MAX_IN_ONE_D + 1;

    cin >> n;
    for (int i = 0; i < n; i++) {
        char direction;
        int distance;

        cin >> direction >> distance;

        for (int i = 0; i < distance; i++) {
            int status = s[x][y];

            if (status != 0) {
                minx = min(time - status, minx);
            }

            time++;
            s[x][y] = time;

            direction == 'N' ? y++ : (direction == 'E' ? x++ :(direction == 'S' ? y-- : x--));
        } 
    }
    cout << (minx == MAX_IN_ONE_D + 1 ? -1 : minx + 1);
}
