  
# [Magic Parenthesis](https://cses.com/115/list )
  
## CSES BOI 2005
  
### Day 1
  
#### Problem B
  
The first observation should be to notice that each "Magic Parenthesis" acts like a regular closing bracket, but can also be considered multiple of them combined. The next thing to notice is that, if an opening parenthesis is not closed, it will carry on until the end of the line.
  
When counting parenthesis in code, an important technique is to do a "prefix sum" of sorts, where each opening parenthesis is a +1 and each closing parenthesis is a -1. If the total at the end of the line is 0, then you have closed everything. Now, with these together, the problem becomes simple.
  
If we treat each "Magic Parenthesis" as a regular parenthesis, we can reach the end of the line and see how many extra opening parenthesis we have that have not already been closed. This extra number can just be dedicated to the very last magic parenthesis, leaving all others with a value of 1. With that, we will have made sure that we closed all of the parentheses and have a net of zero.
  
Here is my implementation:
  
```cpp
#include <bits/stdc++.h>
using namespace std;
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int n, m;
    cin >> n >> m;
  
    // Get the Parenthesis String (because it has been divided
    // into multiple lines
    string s = "";
    while (s.size() < n) {
        string b;
        cin >> b;
        s += b;
    }
  
    // Create a "prefix sum" array, treating each "Magic Parenthesis"
    // As a regular closing parenthesis
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = (s[i] == '(' ? 1 : -1);
    }
  
    // Calculate the prefix sum
    int cval = 0;
    for (int i = 0; i < n; i++) {
        cval += pos[i];
        if (cval < 0) {
            break;
        }
    }
  
    // If we have reached a point where we close more parenthesis
    // than the total that has been opened, we can not deal with tha.
    // parenthesis string
    if (cval < 0) {
        cout << 0 << endl;
        return 0;
    }
  
    // Otherwise it works
    cout << 1 << endl;
    for (int i = 0; i < m - 1; i++) {
        cout << 1 << endl;
    }
    // and we need to find out how much extra to allocate to the final
    // magic parenthesis
    cout << 1 + cval << endl;
    return 0;
}
```  
  