#include <iostream>
#include <set>

using namespace std;

int n, m, k;

int main() {
    cin >> n >> m >> k;
    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.insert(temp);
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        int size;
        cin >> size;
        int person = *a.upper_bound(size - k - 1);
        if (person > size - k && person < size + k) {
            a.erase(person);
            count++;
        }
    }

    cout << count;
}
