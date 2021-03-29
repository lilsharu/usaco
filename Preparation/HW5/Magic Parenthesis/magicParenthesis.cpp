#include <bits/stdc++.h>
using namespace std;

void setIO(const string& name) {
    freopen((name + ".IN").c_str(), "r", stdin);
    freopen((name + ".OUT").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // setIO("LISP");
    int n, m;
    cin >> n >> m;
    string s = "";
    while (s.size() < n) {
        string b;
        cin >> b;
        s += b;
    }

    vector<int> pos(n);

    for (int i = 0; i < n; i++) {
        pos[i] = (s[i] == '(' ? 1 : -1);
    }

    vector<int> val(m, 1);
    int cval = 0;
    // bool work = true;
    for (int i = 0; i < n; i++) {
        cval += pos[i];
        if (cval < 0) {
            break;
        }
    }

    if (cval < 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << 1 << endl;
    for (int i = 0; i < m - 1; i++) {
        cout << 1 << endl;
    }
    cout << 1 + cval << endl;
    return 0;
}