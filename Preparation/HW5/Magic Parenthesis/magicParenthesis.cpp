#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define ffor(i, a, b) for (int i = (a); i < (b); ++i)
#define ff0r(i, a) ffor(i, 0, a)
#define rrof(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define rr0f(i, a) rrof(i, 0, a)
#define trav(a, x) for (auto& a : x)
#define fforn ff0r(i, n)

#define read(a) \
    int(a);     \
    cin >> (a)
#define read2(a, b) \
    read(a);        \
    read(b)

#define endl '\n'
#define f first
#define s second

void setIO(const string& name) {
    freopen((name + ".IN").c_str(), "r", stdin);
    freopen((name + ".OUT").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("LISP");
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vi pos(n);

    for (int i = 0; i < n; i++) {
        pos[i] = (s[i] == '(' ? 1 : s[i] == ')' ? -1 : 0);
    }

    vi val;
    int cval = 0;
    bool work = true;
    for (int i = 0; i < n; i++) {
        if (pos[i] == 0) {
            int sum = cval;
            int addClose = 0;
            int addOpen = 0;
            while (i < n && !pos[i]) {
                if (pos[i] == 1)
                    addOpen++;
                else if (addOpen)
                    addOpen--;
                else
                    addClose++;
                i++;
            }
            i--;
            if (cval <= 0 || addClose >= cval) {
                work = false;
                break;
            } else {
                val.pb(cval - addClose);
                cval = addOpen;
            }
        } else {
            cval += pos[i];
            if (cval < 0) {
                work = false;
                break;
            }
        }
    }

    if (!work) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        cout << val[i] << endl;
    }
}