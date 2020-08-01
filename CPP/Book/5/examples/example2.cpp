#include <bits/stdc++.h>

using namespace std;

struct bucket {
    int current;
    int capacity;
};

const int MAX_N = 100000;

int n;
bucket a[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        bucket in;
        cin >> in.current >> in.capacity;
        a[i] = in;
    }
    
    //GREAT JOB! SAME AS SOLUTION
    for (int i = 0; i < n - 1; i++) {
        int toPour = min(a[i + 1].capacity - a[i + 1].current, a[i].current);
        a[i].current -= toPour;
        a[i + 1].current += toPour;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i].current << ' ';
    }

    cout << '\n';
}
