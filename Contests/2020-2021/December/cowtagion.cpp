// #include <bits/stdc++.h>
// using namespace std;

// typedef vector<int> vi;
// typedef long long ll;

// #define pb push_back
// #define all(x) begin(x), end(x)

// #define endl '\n';

// int n, ps = 0;
// vi adj[100000];
// int dist[100000];

// void bfs(int start) {
//     memset(dist, -1, sizeof dist);
//     queue<int> q;
//     dist[start] = 0;
//     q.push(start);
    
//     while (!q.empty()) {
//         int v = q.front();
//         q.pop();
//         int sum = 0;
//         for (int e : adj[v]) {
//             if (dist[e] == -1) {
//                 dist[e] = dist[v] + 1;
//                 // ps += dist[e];
//                 q.push(e);
//                 sum++;
//             }
//         }
//         ps += (sum + (sum == 0 ? 0 : ceil(log2(sum))));
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n;

//     for (int i = 0; i < n - 1; i++) {
//         int a, b;
//         cin >> a >> b;
//         a--; b--;
//         adj[a].pb(b);
//         adj[b].pb(a);
//     }

//     // int getCows = ceil(log2(n));
    
//     bfs(0);
    
//     cout << ps << endl;
// }

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n';

int n, ps = 0;
vi adj[100000];
int dist[100000];

void bfs(int start) {
    memset(dist, -1, sizeof dist);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int e : adj[v]) {
            if (dist[e] == -1) {
                dist[e] = dist[v] + 1;
                ps += dist[e];
                q.push(e);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int getCows = ceil(log2(n));
    
    bfs(0);
    
    cout << getCows + ps << endl;
}