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