#include <iostream>
#include <unordered_set>

using namespace std;

int N;
unordered_set<int> nums;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        nums.insert(temp);
    }


    cout << nums.size();
}
