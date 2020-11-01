#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    
    int N, K, B;
    cin >> N >> K >> B;

    // Use vector because it defaults to 0
    vector<bool> status(N + 1);

    // Converts all broken lights to 1 in vector
    for (int i = 0; i < B; i++) {
        int broken;
        cin >> broken;

        status[broken] = 1;
    }

    // Calculates the Prefix Sum of the broken lights
    vector<int> prefix(N + 1);
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + status[i];
    }

    // Finds a range of K traffic lights with the minimum broken ones
    int broken = K;
    for (int i = K; i <= N; i++) {
        broken = min(broken, prefix[i] - prefix[i - K]);
    }

    cout << broken << '\n';
    return 0;
}