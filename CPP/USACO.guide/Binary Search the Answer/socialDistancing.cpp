#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;

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

#define endl '\n';

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

/*
 * Farmer John is worried for the health of his cows after an outbreak of the
 * highly contagious bovine disease COWVID-19.
 *
 * In order to limit transmission of the disease, Farmer John's N cows (2≤N≤105)
 * have decided to practice "social distancing" and spread themselves out across
 * the farm. The farm is shaped like a 1D number line, with M mutually-disjoint
 * intervals (1≤M≤105) in which there is grass for grazing. The cows want to
 * locate themselves at distinct integer points, each covered in grass, so as to
 * maximize the value of D, where D represents the distance between the closest
 * pair of cows. Please help the cows determine the largest possible value of D.
 */

int main() {
}