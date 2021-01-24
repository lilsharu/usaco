#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back

#define f first
#define s second


int n, k;
vpi s;

vi t;

vector<set<int>> x;

bool isSorted() {
    for (int i = 1; i <= n; i++) {
        if (t[i] != i) {
            return false;
        }
    }

    return true;
}

void swap(int a, int b) {
    int temp = t[a];
    t[a] = t[b];
    t[b] = temp;

    x[t[a]].insert(b);
    x[t[b]].insert(a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    s.resize(k);
    t.resize(n + 1);
    x.resize(n + 1);

    for (int i = 0; i < k; i++) {
        cin >> s[i].f >> s[i].s;
    }

    for (int i = 1; i <= n; i++) {
        t[i] = i;
        x[i].insert(i);
    }

    int kpos = 0;

    swap(s[kpos].f, s[kpos].s);
    kpos = (kpos + 1) % k;

    while (!isSorted()) {
        swap(s[kpos].f, s[kpos].s);
        kpos = (kpos + 1) % k;
    }

    for (int i = 1; i <= n; i++) {
        cout << x[i].size() << endl;
    }

    return 0;
}