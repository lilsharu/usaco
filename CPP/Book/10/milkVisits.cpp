#include <bits/stdc++.h>

using namespace std;

int n, m;
string pos;

int curIndex = 0;

vector<int> adj[100000], sol[100000];
bool visited[100000];
bool ans[100000];

bool dfs(int start, int end) {
    visited[start] = true;
    if (start == end) {
        return true;
    }
    else if (adj[end].size() == 0) {
        return false;
    }
    for (int next : adj[start]) {
        if (!visited[next]) {
            if (dfs(next, end)) {
                sol[curIndex].push_back(start);
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    cin >> n >> m;
    cin >> pos;
    
    {
        int a, b;
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    for (int i = 0; i < m; i++) {
        int start, end;
        char c;
        cin >> start >> end >> c;
        start--; end--;

        ans[i] == false;

        if (start == end) ans[i] = c == pos.at(start);
        else if (pos.at(start) == c || pos.at(end) == c) ans[i] = true;
        else {
            dfs(start, end);
            for (int j : sol[curIndex]) {
                if (pos.at(j) == c) {
                    ans[i] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << (ans[i] ? '1' : '0');
    }

    return 0;
    
}