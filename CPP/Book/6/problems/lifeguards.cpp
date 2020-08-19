#include <bits/stdc++.h>

using namespace std;

struct interval {
    int start;
    int end;
};

bool interval_sorter(interval const& a, interval const&b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    else {
        return a.end < b.end;
    }
}

int n;
interval v[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i].start >> v[i].end;
    }
    sort(v, v + n, interval_sorter);
    
    int result = 0;

    for (int i = 0; i < n; i++) {
        vector<interval> range;
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            int cs = v[k].start;
            int ce = v[k].end;
            while (k < n && v[k + 1].start <= ce) {
                if (k + 1 == i) {
                    k++;
                    continue;
                }
                ce = max(ce, v[k + 1].end);
                k++;
            }
            interval c;
            c.start = cs, c.end = ce;
            range.push_back(c);
        }
        int sum = 0;
        for (interval v : range) {
            sum += (v.end - v.start);
        }
        result = max(result, sum);
    }

    cout << result << '\n';
}
