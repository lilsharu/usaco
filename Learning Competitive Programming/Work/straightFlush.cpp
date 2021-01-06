#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define FORN FOR(i, 0, n)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define ROFN ROF(i, 0, n)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'
#define f first
#define s second

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool works(vector<int>& a) {
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i + 1] - a[i] != 1) return false;
    }
    return true;
}

int main() {
    setIO();

    string values[5];
    cin >> values[0];
    cin >> values[1];
    cin >> values[2];
    cin >> values[3];
    cin >> values[4];    

    vector<int> a;
    vector<int> b;
    
    char pSuit = values[0][values[0].size() - 1];

    for (string x : values) { 
        char val = x[0];
        char suit = x[x.size() - 1];
        
        if (suit != pSuit) {
            cout << "NO" << endl;
            return 0;
        }

        int aval = 0, bval = 0;

        switch(val) {
            case '2':
                aval = 2;
                bval = 2;
                break;
            case '3':
                aval = 3;
                bval = 3;
                break;
            case '4':
                aval = 4;
                bval = 4;
                break;
            case '5':
                aval = 5;
                bval = 5;
                break;
            case '6':
                aval = 6;
                bval = 6;
                break;
            case '7':
                aval = 7;
                bval = 7;
                break;
            case '8':
                aval = 8;
                bval = 8;
                break;
            case '9':
                aval = 9;
                bval = 9;
                break;
            case '1':
                aval = 10;
                bval = 10;
                break;
            case 'J':
                aval = 11;
                bval = 11;
                break;
            case 'Q':
                aval = 12;
                bval = 12;
                break;
            case 'K':
                aval = 13;
                bval = 13;
                break;
            case 'A':
                aval = 1;
                bval = 14;
                break;
        }
        a.pb(aval);
        b.pb(bval);
    }
    sort(all(a));
    sort(all(b));
    cout << (works(a) || works(b) ? "YES" : "NO") << endl;
}