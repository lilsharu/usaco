#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

int n, pos[MAX_N];

struct cow {
    int pos;
    int id;

    bool operator < (const cow& a) const {
        return this->pos < a.pos;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
}
