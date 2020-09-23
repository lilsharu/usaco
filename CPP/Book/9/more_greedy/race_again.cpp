#include <bits/stdc++.h>

using namespace std;

int k, n;

int solve() {
    int minspeed, distance = k;
    cin >> minspeed;

    int leftTravel = 0, rightTravel = 0;
    int time = 0;
    for (int speed = 1;; speed++) {
        leftTravel += speed;
        time++;
        if (leftTravel + rightTravel >= distance) return time;
        if (speed >= minspeed) {
            rightTravel += speed;
            time++;
            if (leftTravel + rightTravel >= distance) return time;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        cout << solve() << '\n';
    }    
}