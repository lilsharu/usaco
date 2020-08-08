#include <bits/stdc++.h>

#define pb cows.push_back

using namespace std;

struct cow {
    int start, duration;
    bool operator<(const cow& a) const {
        return start < a.start;
    }
};

int n;
vector<cow> cows;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cow c;
        cin >> c.start >> c.duration;
        pb(c);
    }

    sort(cows.begin(), cows.end());

    int time = 0;

    for (cow c : cows) {
        if (c.start > time) time = c.start + c.duration;
        else time += c.duration;
    }

    cout << time << '\n';
}
