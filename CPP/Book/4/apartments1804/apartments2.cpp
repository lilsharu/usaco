#include <iostream>
#include <set>
 
using namespace std;
 
const int MAX = 200000;

int n, m, k;
 
int a[MAX];
int b[MAX];
 
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i] = temp;
    }

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        b[i] = temp;
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; i < n; j++) {
            if (b[j] == -1) continue;
            if (b[j] <= a[i] - 5 && b[j] >= a[i] + 5) {
                b[j] = -1;
                count++;
                break;
            }  
        } 
    }
    cout << count;
}
