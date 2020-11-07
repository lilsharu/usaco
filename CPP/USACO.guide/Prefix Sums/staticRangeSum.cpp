#include <iostream>
#include<vector>

using namespace std;

int N, Q;

int main() {
    cin >> N >> Q;

    vector<int> prefix(N + 1);

    for (int i = 1; i < N; i++) {
        int a; cin >> a;
        prefix[i] = prefix[i - 1] + a;
    }

    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << endl;
    }
}