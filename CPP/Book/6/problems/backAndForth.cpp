#include <bits/stdc++.h>

using namespace std;

int possible_answers[2000], answer;

void friday(int b1milk, vector<int> b1, vector<int> b2) {
    for (int i = 0; i < b2.size(); i++) {
        int x = b2[i];
        possible_answers[b1milk + x] = 1;
    }
}

void thursday(int b1milk, vector<int> b1, vector<int> b2) {
    for (int i = 0; i < b1.size(); i++) {
        int x = b1[i];
        vector<int> newb2 = b2; newb2.push_back(x);
        vector<int> newb1 = b1; newb1.erase(newb1.begin() + i);
        friday(b1milk - x, newb1, newb2);
    }
}

void wednesday(int b1milk, vector<int> b1, vector<int> b2) {
    for (int i = 0; i < b2.size(); i++) {
        int x = b2[i];
        vector<int> newb1 = b1; newb1.push_back(x);
        vector<int> newb2 = b2; newb2.erase(newb2.begin() + i);
        thursday(b1milk + x, newb1, newb2);
    }
}

void tuesday(int b1milk, vector<int> b1, vector<int> b2) {
    for (int i = 0; i < b1.size(); i++) {
        int x = b1[i];
        vector<int> newb2 = b2; newb2.push_back(x);
        vector<int> newb1 = b1; newb1.erase(newb1.begin() + i);
        wednesday(b1milk - x, newb1, newb2);
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    vector<int> b1, b2;

    int temp;
    for (int i = 0; i < 10; i++) {
        cin >> temp;
        b1.push_back(temp);
    }
    for (int i = 0; i < 10; i++) {
        cin >> temp;
        b2.push_back(temp);
    }

    tuesday(1000, b1, b2);

    answer = 0;
    for (int i = 0; i < 2000; i++) {
        answer += possible_answers[i];
    }

    cout << answer << '\n';
}
