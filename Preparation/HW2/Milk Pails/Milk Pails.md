  
# Milk Pails
  
## February 2016
  
### Silver
  
#### Problem 3
  
The first thing we can notice on this problem is the very low bounds. We are given a total of 4 variables, three of which have a maximum of <img src="https://latex.codecogs.com/gif.latex?100"/>, and one which has a maximum of <img src="https://latex.codecogs.com/gif.latex?200"/>. With this in mind, we can see that, even if we brute force every combination, we should still be able to pass without a timeout error, giving us a maximum of <img src="https://latex.codecogs.com/gif.latex?2&#x5C;cdot10^8"/> operations.
  
However, if you look at the problem more closely, one of these values <img src="https://latex.codecogs.com/gif.latex?&#x5C;left(M&#x5C;right)"/> is fixed and the other is just a constraint, so trying every possible combination of the remaining two values <img src="https://latex.codecogs.com/gif.latex?&#x5C;left(X,%20Y&#x5C;right)"/> should run in more than enough time <img src="https://latex.codecogs.com/gif.latex?&#x5C;left(10^4&#x5C;right)"/>.
  
Starting with no milk in either container, we can either fill each container, empty each container, or pour the contents of one container to another. If we try out every combination of those (skipping duplicates and cases which are above the maximum time alloted), we can store the minimum difference until now and update it when we can improve it.
  
Here is my implementation of this solution:
  
```cpp
#include <bits/stdc++.h>
using namespace std;
  
void setIO(const string& name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
  
bool vis[101][101]; // X vs Y
  
struct val{
    int k, x, y; 
    val() {}
    val(int ka, int xa, int ya) : k(ka), x(xa), y(ya) {};
};
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pails.in", "r", stdin);
  
    int x, y, k, m;
    cin >> x >> y >> k >> m;
  
    queue<val> q;
    q.push(val(0, 0, 0));
  
    int mg = m;
  
    while (!q.empty()) {
        val cur = q.front();
        q.pop();
        if (cur.k > k || vis[cur.x][cur.y]) continue;
        vis[cur.x][cur.y] = true;
  
        mg = min(mg, abs(m - cur.x - cur.y));
  
        // Fill X
        q.push(val(cur.k + 1, x, cur.y));
  
        // Fill Y
        q.push(val(cur.k + 1, cur.x, y));
  
        // Empty X
        q.push(val(cur.k + 1, 0, cur.y));
  
        // Empty Y
        q.push(val(cur.k + 1, cur.x, 0));
  
        // Empty X into Y
        int mvmt = min(y - cur.y, cur.x);
        q.push(val(cur.k + 1, cur.x - mvmt, cur.y + mvmt));
  
        // Empty Y into X
        mvmt = min(x - cur.x, cur.y);
        q.push(val(cur.k + 1, cur.x + mvmt, cur.y - mvmt));
    }
  
    cout << mg << endl;
}
```  
  