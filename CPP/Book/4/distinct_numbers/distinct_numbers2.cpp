#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2 * 100000;
int N;
int nums[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + N);
    
    int temp = nums[0];
    int count = 1;
    for (int i = 1; i < N; i++) { 
        int num = nums[i];
        if (num == temp) continue;
        else {
            temp = num;
            count++;
        }
    }

    cout << count;
    
}
