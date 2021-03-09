  
# Social Distancing
  
## US Open 2020
  
### Silver
  
#### Problem 1
  
To solve this problem, the first thing to notice is that, if gap <img src="https://latex.codecogs.com/gif.latex?x"/> is not possible, then all gaps <img src="https://latex.codecogs.com/gif.latex?g%20&gt;%20x"/> won't work either. With this observation in mind, we can classify a function to check if a value works as monotonic, which allows us to use the strategy of Binary Search on the Answer to Solve efficiently. We use a binary increment to find the heighest value that works, slowly decreasing the size of the jumps we are taking as we approach the limit of the answer.
  
To check if a gap is possible, we need to place each cow the closest it can be, which means a minimum of distance <img src="https://latex.codecogs.com/gif.latex?x"/>, or the start of the next patch of grass if <img src="https://latex.codecogs.com/gif.latex?x"/> is outside any graphs. So we can check if, after going through all the cows, or reaching the end of the path, if we have any cows remaining. If we do, then we can't have a gap that size. If we do not, then a gap that size works and we can look for gaps larger.
  
Here is my implementation:
  
```cpp
#include <bits/stdc++.h>
using namespace std;
  
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;
  
#define all(x) begin(x), end(x)
  
#define f first
#define s second
  
void setIO(const string& name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
  
int n, m;
vpl v;
  
bool test(ll gap) {
    ll start = v[0].f;
    int num = n - 1;
    ll ind = 0;
    while (ind < m && num) {
        while (ind < m && v[ind].s < start + gap) ind++;
        if (ind == m) break;
        start = max(start + gap, v[ind].f);
        num--;
    }
  
    return num <= 0;
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("socdist");
  
    cin >> n >> m;
    v.resize(m);
  
    for (int i = 0; i < m; i++) cin >> v[i].f >> v[i].s;
  
    sort(all(v));
  
    ll gap = 1;
    for (ll jump = 1e9; jump >= 1; jump >>= 1) {
        while (test(gap + jump)) gap += jump;
    }
  
    cout << gap << endl;
}
```  
  