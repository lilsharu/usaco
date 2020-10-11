#include <bits/stdc++.h>

using namespace std;

struct cow {
    int x, y, p, i;
    cow(int _x, int _y, int _p): x(_x), y(_y), p(_p){}
    cow() {
        
    }
};

bool connected(cow a, cow b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) <= a.p * a.p;
}

int n, current = 0;
cow cows[200];
vector<cow> coordinates[200];
bool visited[200][200];

int dfs(int node) {
    int connections = 1;
    visited[current][node] = true;
    for (cow next : coordinates[node]) {
        if (!visited[current][next.i]) {
            connections += dfs(next.i);
        }
    }
    return connections;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> n;

    int x, y, p;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> p;
        cows[i] = cow(x, y, p);
        cows[i].i = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (connected(cows[i], cows[j])) {
                coordinates[i].push_back(cows[j]);
            }
            visited[i][j] == true;
        }
    }

    int s = 0;

    for (int i = 0; i < n; i++) {
        s = max(s, dfs(i));
        current++;
    }
     
    cout << s << '\n';
}
