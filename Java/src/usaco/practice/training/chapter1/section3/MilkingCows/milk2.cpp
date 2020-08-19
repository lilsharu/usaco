/*
ID: shourya7
TASK: milk2
LANG: C++
*/

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
interval v[5000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i].start >> v[i].end;
    }
    sort(v, v + n, interval_sorter);
    
    vector<interval> range;
    vector<interval> minRange;
    for (int i = 0; i < n; i++) {
        int cs = v[i].start;
        int ce = v[i].end;
        
        while (i < n && v[i + 1].start <= ce) {
            if (i + 1 == i) {
                i++;
                continue;
            }
            ce = max(ce, v[i + 1].end);
            i++;
        }

        interval c;
        c.start = cs, c.end = ce;
        range.push_back(c);
    }

    for (int i = 0; i < range.size() - 1; i++) {
        interval other;
        other.start = range.at(i).end;
        other.end = range.at(i + 1).start;
        minRange.push_back(other);
    }

    int maxMax = 0; 
    int noMax = 0;

    for (interval i : range) {
        maxMax = max(maxMax, i.end - i.start);
    }

    for (interval i : minRange) {
        noMax = max(noMax, i.end - i.start);
    }

    cout << maxMax << ' ' << noMax << '\n';
}
