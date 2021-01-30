#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    string s;
    cin >> s;

    map<char, int> m;

    for (int i = 0; i < 26; i++) {
        m[s[i]] = i;
    }

    string a;

    cin >> a;

    vi x(a.size() + 1);

    x[0] = -1;
    for (int i = 1; i <= a.size(); i++) {
        x[i] = m[a[i - 1]];
    }

    int total = 0;

    for (int i = 0; i < x.size(); i++) {
        while (i + 1 < x.size() && x[i + 1] > x[i]) i++;
        total++;
    }

    cout << total << endl;
}