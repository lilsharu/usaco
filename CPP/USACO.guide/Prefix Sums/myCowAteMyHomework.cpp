#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)

#define pb push_back
#define all(x) begin(x), end(x)

#define endl '\n';

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("homework");
    int n;
    cin >> n;

    vi scores(n + 1), sum(n + 1), mins(n + 1);
    vector<double> averages(n);

    FOR(i, 1, n + 1) {
        int temp; cin >> temp;
        scores[i] = temp;
        sum[i] = sum[i - 1] + temp;
    }

    int minima = INT_MAX;
    R0F(i, n + 1) {
        minima = min(minima, scores[i]);
        mins[i] = minima; 
    }

    double maxScore = ((double) sum[n]/n);
    FOR(i, 0, n - 1) {
        int sums = sum[n] - sum[i] - mins[i + 1];
        double score = (double) sums / (n - 1 - i);
        averages[i] = score;
        maxScore = max(score, maxScore);
    }

    vi maxIndex;
    F0R(i, n) {
        if (averages[i] == maxScore) maxIndex.pb(i + 1);
    }

    trav(a, maxIndex) {
        cout << a - 1 << endl;
    }

    return 0;
}