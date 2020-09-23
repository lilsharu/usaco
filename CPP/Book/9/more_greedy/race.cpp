#include <bits/stdc++.h>

using namespace std;

long long n, k;

long long calcSum(long long current, long long max, long long pos) {
    return (current + max) * (current - max + 1) / 2;
}

bool canIncrease(long long current, long long max, long long pos) {
     return current + 1 <= max || calcSum(current + 1, max, pos) <= k - pos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    cin >> n >> k;

    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;

        long long pos = 1;
        long long speed = 1;
        long long seconds = 1;

        while (canIncrease(speed, x, pos)) {
            speed++;
            pos += speed;
            seconds++;
        }

        long long travel = calcSum(speed, x, pos);
        if (travel == k - pos) {
            seconds += speed - x + 1;
        } else if (travel < k) {
            int difference = k - travel;
            for (int i = speed; i >= 1; i--) {
                if (difference % i == 0) {
                    seconds += difference / i;
                    break;
                }
            }
            seconds += speed - x + 1;
        }

        cout << seconds << '\n';
    }
}