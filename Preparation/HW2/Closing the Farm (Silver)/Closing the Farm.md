  
# Closing the Farm
  
## US Open 2016
  
### Silver
  
#### Problem 3
  
For the Silver version of this Problem, we can solve this quite easily. All we need to do is see if all the barns are in a single Connected Component after we remove a barn. To find this out, we just need to check if every remaining barn can be reached from a root node. If yes, then the barn is connected. Otherwise, it is not.
  
The first step is finding the root node. We can easily do this by selecting the last node to be removed, as we know that it will always be included in any graph of the farm.
  
From here, we can do BFS for each removed node to count if the number of barns in the component of the root is the number left in total.
  
```cpp
#include <bits/stdc++.h>
using namespace std;
  
typedef vector<int> vi;
  
#define pb push_back

void setIO(const string& name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
  
vi adj[3001];
int n, m;
vi c;
int root;
  
vi vis;
  
int bfs() {
    int tot = 0;
    queue<int> q;
    q.push(root);
    vis[root] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        tot++;
        for (int next : adj[cur]) {
            if (!vis[next]) {
                vis[next] = true;
                q.push(next);
            }
        }
    }
    return tot;
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("closing");
  
    cin >> n >> m;
  
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
  
    c.resize(n);
  
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
  
    root = c[n - 1];
    int exp = n;
  
    vis.resize(n);
  
    // BFS Each Removal and check size of component and compare to expected
    for (int i = 0; i < n; i++) {
        fill(all(vis), 0); 
        for (int j = 0; j < i; j++) {
            vis[c[j]] = true;
        }
  
        int x = bfs();
        cout << (x == exp ? "YES" : "NO") << endl;
        exp--;
    } 
}
```  
  