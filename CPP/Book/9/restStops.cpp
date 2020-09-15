#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;

long long n, l, rf, rb;
int pos[1000000], c[1000000];
bool isMax[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    cin >> l >> n >> rf >> rb;

    for (int i = 0; i < n; i++) cin >> pos[i] >> c[i];

    int max = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (c[i] > max) {
            isMax[i] = 1;
            max = c[i];
        }
    }

    long long maxTastiness = 0, lastx = 0, tf = 0, tb = 0;

    for(int i = 0; i < n; i++) if(isMax[i]) {
		tb += (pos[i] - lastx) * rb;
		tf += (pos[i] - lastx) * rf;
		maxTastiness += (tf - tb) * c[i];
		tb = tf;
		lastx = pos[i];
	}

    // for (int i = 0; i < n; i++) {
    //     if (isMax[i]) {
    //         int position = pos[i];
    //         int movement = pos[i] - lastx;

    //         int secsToGo = movement * rf - movement * rb;

    //         maxTastiness += secsToGo * c[i];
    //         lastx = pos[i];
    //     }
    // }

    cout << maxTastiness << '\n';
}