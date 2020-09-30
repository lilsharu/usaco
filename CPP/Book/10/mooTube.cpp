#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, weight;
    Edge(int dest, int w): to(dest), weight(w){}
};

int N, Q, k, v, total, temp = 0, visited[5000][5000];

vector<Edge> arr[5000];

void dfs(int start) {
    visited[temp][start] = true;
    for (Edge next : arr[start]) {
        if (!visited[temp][next.to] && next.weight >= k) {
            total++;
            dfs(next.to);
        } 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    cin >> N >> Q;

    int p, q, r;
    for (int i = 0; i < N - 1; i++) {
        cin >> p >> q >> r;

        p--, q--;

        arr[p].push_back(Edge(q, r));
        arr[q].push_back(Edge(p, r));
    }

    for (int i = 0; i < Q; i++) {
        cin >> k >> v;
        --v;
        total = 0;
        
        //Start DFS
        dfs(v);
        temp++; 

        cout << total << '\n';       
    }
    
    return 0;
}