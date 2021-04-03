#include <bits/stdc++.h>
using namespace std;

struct combo {
    int a, b, c;
    combo(int aa, int bb, int cc) {
        int arr[3] = {aa, bb, cc};
        sort(arr, arr + 3);
        a = arr[0];
        b = arr[1];
        c = arr[2];
        if (a <= 0) {
            a = 0, b = 0, c = 0;
        }
    }
    combo() : combo(-1, -1, -1) {}
    combo(int aa) : combo(aa, -1, -1) {}
    combo(int aa, int bb) : combo(aa, bb, -1) {}

    bool operator<(const combo& o) const {
        return tuple<int, int, int>{a, b, c} <
               tuple<int, int, int>{o.a, o.b, o.c};
    }
    bool operator==(const combo& o) const {
        return a == o.a && b == o.b && c == o.c;
    }
};

set<combo> s;

void four(vector<int> v) {
    // Skip A
    {
        // Skip B
        {
            // Skip C
            {
                // A + B + C =
                // A + B, A + C, B + C
                if (!((v[0] + v[1] + v[2]) % 2)) {
                    // A + B + C = (v[0] + v[1] + v[2]) / 2
                    if (v[3] == (v[0] + v[1] + v[2]) / 2) {
                        int a = v[3] - v[2];
                        int b = v[3] - v[1];
                        int c = v[3] - v[0];
                        s.insert(combo(a, b, c));
                    }
                }
            }
            // Skip A + B
            {
                int c = v[0];
                int a = v[1] - c;  // A + C
                int b = v[2] - c;  // B + C
                if (v[3] == a + b + c) {
                    s.insert(combo(a, b, c));
                }
            }
            // Skip A + C
            {// C is Smaller
             {int c = v[0];
            int b = v[2] - c;
            int a = v[1] - b;
            if (v[3] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
        // A + B is Smaller
        {
            int c = v[1];
            int b = v[2] - c;
            int a = v[0] - b;
            if (v[3] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
    }
    // Skip B + C
    {// C is Smaller
     {int c = v[0];
    int a = v[2] - c;
    int b = v[1] - a;
    if (v[3] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
// A + B is Smaller
{
    int c = v[1];
    int a = v[2] - c;
    int b = v[0] - a;
    if (v[3] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
}
// Skip A + B + C
{
    // C is Smaller
    {
        int c = v[0];
        int a = v[2] - c;
        int b = v[3] - c;
        if (v[1] == a + b) {
            s.insert(combo(a, b, c));
        }
    }
    // A + B is Smaller
    {
        int c = v[1];
        int a = v[2] - c;
        int b = v[3] - c;
        if (v[0] == a + b) {
            s.insert(combo(a, b, c));
        }
    }
}
}
// Skip C
int b = v[0];
{                    // Skip A + B
 {int c = v[2] - b;  // B + C
int a = v[1] - c;    // A + C
if (v[3] == a + b + c) {
    s.insert(combo(a, b, c));
}
}
// Skip A + C
{
    int a = v[1] - b;
    int c = v[2] - b;
    if (v[3] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
// Skip B + C
{
    int a = v[1] - b;
    int c = v[2] - a;
    if (v[3] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
// Skip A + B + C
{
    int a = v[1] - b;
    int c = v[2] - a;
    if (v[3] == b + c) {
        s.insert(combo(a, b, c));
    }
}
}

// Skip A + B
{
    int b = v[0];
    int c = v[1];
    // Skip A + C
    {
        int a = v[3] - b - c;
        if (v[2] == b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip B + C
    {
        int a = v[2] - c;
        if (v[3] == a + b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip A + B + C
    {
        int a = v[2] - c;
        if (v[3] == b + c) {
            s.insert(combo(a, b, c));
        }
    }
}
// Skip A + C, B + C, or A + B + C
{
    // C is Smaller
    {
        int b = v[0];
        int c = v[1];
        int a = v[2] - b;
        if (v[3] == a + b + c || v[3] == b + c || v[3] == a + c) {
            s.insert(combo(a, b, c));
        }
    }
    // A + B is Smaller
    {
        int b = v[0];
        int c = v[2];
        int a = v[1] - b;
        if (v[3] == a + b + c || v[3] == b + c || v[3] == a + c) {
            s.insert(combo(a, b, c));
        }
    }
}
}
int a = v[0];
// Skip B
{ // Skip C
 {// Skip A + B
  {int c = v[1] - a;
int b = v[2] - c;
if (v[3] == a + b + c) {
    s.insert(combo(a, b, c));
}
}
// Skip A + C
{
    int b = v[1] - a;
    int c = v[2] - b;
    if (v[3] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
// Skip B + C || A + B + C
{
    int b = v[1] - a; // A + B
    int c = v[2] - a; // A + C
    if (v[3] == a + b + c || v[3] == b + c) {
        s.insert(combo(a, b, c));
    }
}
}
// Skip A + B
{
    int c = v[1];
    // Skip A + C
    {
        int b = v[2] - c;
        if (v[3] == a + b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip B + C
    {
        int b = v[3] - a - c;
        if (v[2] == a + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip A + B + C
    {
        int b = v[3] - c;
        if (v[2] == a + c) {
            s.insert(combo(a, b, c));
        }
    }
}
// Last Three
{
    // C is Smaller
    {
        int c = v[1];
        int b = v[2] - a;
        if (v[3] == a + b + c || v[3] == b + c || v[3] == a + c) {
            s.insert(combo(a, b, c));
        }
    }
    // A + B is Smaller
    {
        int b = v[1] - a;
        int c = v[2];
        if (v[3] == a + b + c || v[3] == b + c || v[3] == a + c) {
            s.insert(combo(a, b, c));
        }
    }
}
}
// Skip C
{
    int a = v[0];
    int b = v[1];
    // Skip A + B
    {
        // Skip A + C
        {
            int c = v[2] - b;
            if (v[3] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
        // Skip B + C
        {
            int c = v[2] - a;
            if (v[3] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
        // Skip A + B + C
        {
            int c = v[2] - a;
            if (v[3] == b + c) {
                s.insert(combo(a, b, c));
            }
        }
    }
    // Skip A + C || B + C && A + B + C
    if (v[2] == a + b) {
        s.insert(combo(a, b, v[3] - b));
        s.insert(combo(a, b, v[3] - a - b));
        s.insert(combo(a, b, v[3] - a));
    }
}
// Know A, B, C && C is Smaller
{
    int a = v[0], b = v[1], c = v[2];
    if (v[3] == a + b || v[3] == a + c || v[3] == b + c || v[3] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
// C is Larger
// Skip C
{
    int a = v[0];
    int b = v[1];
    if (v[2] == a + b) {
        // A + B + C
        {
            int c = v[3] - a - b;
            s.insert(combo(a, b, c));
        }
        // B + C
        {
            int c = v[3] - b;
            s.insert(combo(a, b, c));
        }
        // A + C
        {
            int c = v[3] - a;
            s.insert(combo(a, b, c));
        }
        // C
        {
            int c = v[3];
            s.insert(combo(a, b, c));
        }
    }
}
}

void five(vector<int> v) {
    // Skip A
    { // Skip B
     {// C is Smaller
      {int c = v[0];
    // v[1] = a + b
    // v[2] = a + c
    int a = v[2] - c;
    int b = v[3] - c;
    if (v[1] == a + b && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
// C is larger
{
    int c = v[1];
    // v[0] = a + b
    // v[2] = a + c
    int a = v[2] - c;
    int b = v[3] - c;
    if (v[0] == a + b && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
}
// Skip C
{
    int b = v[0];
    int a = v[1] - b;
    int c = v[2] - a;
    if (v[3] == b + c && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
// Skip A + B
{
    int b = v[0];
    int c = v[1];
    int a = v[2] - c;  // A + C
    if (v[3] == b + c && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
// Skip A + C
{// C is Smaller
 {int b = v[0];
int c = v[1];
int a = v[2] - b;  // A + B
if (v[3] == b + c && v[4] == a + b + c) {
    s.insert(combo(a, b, c));
}
}
// C is Larger
{
    int b = v[0];
    int c = v[2];
    int a = v[1] - b;  // A + B
    if (v[3] == b + c && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
}
// Skip B + C
{// C is Smaller
 {int b = v[0];
int c = v[1];
int a = v[2] - b;
if (v[3] == a + c && v[4] == a + b + c) {
    s.insert(combo(a, b, c));
}
}
// C is Larger
{
    int b = v[0];
    int c = v[2];
    int a = v[1] - b;
    if (v[3] == a + c && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
}
// Skip A + B + C
{
    // C is Smaller
    {
        int b = v[0];
        int c = v[1];
        int a = v[2] - b;
        if (v[3] == a + c && v[4] == b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // C is Larger
    {
        int b = v[0];
        int c = v[2];
        int a = v[1] - b;
        if (v[3] == a + c && v[4] == b + c) {
            s.insert(combo(a, b, c));
        }
    }
}
}

// Skip B
{
    int a = v[0];
    // Skip C
    {
        int b = v[1] - a;  // A + B
        int c = v[2] - a;  // A + C
        if (v[3] == b + c && v[4] == a + b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip A + B
    {
        int c = v[1];
        int b = v[3] - c;
        if (v[2] == a + c && v[4] == a + b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip A + C
    {// C is Smaller
     {int c = v[1];
    int b = v[2] - a;  // A + B
    if (v[3] == b + c && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
// C is larger
{
    int b = v[1] - a;  // A + B
    int c = v[2];
    if (v[3] == b + c && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
}
// Skip B + C
{// C is Smaller
 {int c = v[1];
int b = v[2] - a;  // A + B
if (v[3] == a + c && v[4] == a + b + c) {
    s.insert(combo(a, b, c));
}
}
// C is larger
{
    int b = v[1] - a;  // A + B
    int c = v[2];
    if (v[3] == a + c && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
}

// Skip A + B + C
{
    // C is Smaller
    {
        int c = v[1];
        int b = v[2] - a;  // A + B
        if (v[3] == a + c && v[4] == b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // C is larger
    {
        int b = v[1] - a;  // A + B
        int c = v[2];
        if (v[3] == a + c && v[4] == b + c) {
            s.insert(combo(a, b, c));
        }
    }
}
}
// Skip C
{
    int a = v[0];
    int b = v[1];
    // Skip A + B
    {
        int c = v[2] - a;  // A + C
        if (v[3] == b + c && v[4] == a + b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip A + C
    {
        int c = v[3] - b;
        if (v[2] == a + b && v[4] == a + b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip B + C
    {
        int c = v[3] - a;
        if (v[2] == a + b && v[4] == a + b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip A + B + C
    {
        int c = v[3] - a;
        if (v[2] == a + b && v[4] == b + c) {
            s.insert(combo(a, b, c));
        }
    }
}
// Skip A + B
{
    int a = v[0];
    int b = v[1];
    int c = v[2];
    // Skip A + C
    {
        if (v[3] == b + c && v[4] == a + b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip B + C
    {
        if (v[3] == a + c && v[4] == a + b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // Skip A + B + C
    {
        if (v[3] == a + c && v[4] == b + c) {
            s.insert(combo(a, b, c));
        }
    }
}

// Skip A + C
{
    int a = v[0];
    int b = v[1];
    // Skip B + C
    {// C is Smaller
     {int c = v[2];
    if (v[3] == a + b && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
// A + B is Smaller
{
    int c = v[3];
    if (v[2] == a + b && v[4] == a + b + c) {
        s.insert(combo(a, b, c));
    }
}
}
// Skip A + B + C
{
    // C is Smaller
    {
        int c = v[2];
        if (v[3] == a + b && v[4] == b + c) {
            s.insert(combo(a, b, c));
        }
    }
    // A + B is Smaller
    {
        int c = v[3];
        if (v[2] == a + b && v[4] == b + c) {
            s.insert(combo(a, b, c));
        }
    }
}
}

// Skip B + C && A + B + C
{
    int a = v[0];
    int b = v[1];
    // C is Smaller
    {
        int c = v[2];
        if (v[3] == a + b && v[4] == a + c) {
            s.insert(combo(a, b, c));
        }
    }
    // A + B is Smaller
    {
        int c = v[3];
        if (v[2] == a + b && v[4] == a + c) {
            s.insert(combo(a, b, c));
        }
    }
}
}

void six(vector<int> v) {
    {
        int a = v[0];
        int b = v[1];
        // Two C options
        {
            int c = v[2];  // v[3] = A + b

            // Skip A + B + c
            if (v[3] == a + b && v[4] == a + c && v[5] == b + c) {
                s.insert(combo(a, b, c));
            }

            // Skip B + C
            if (v[3] == a + b && v[4] == a + c && v[5] == a + b + c) {
                s.insert(combo(a, b, c));
            }

            // Skip A + C
            if (v[3] == a + b && v[4] == b + c && v[5] == a + b + c) {
                s.insert(combo(a, b, c));
            }

            // Skip A + B
            if (v[3] == a + c && v[4] == b + c && v[5] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
        {
            int c = v[3];  // v[2] == a + b

            // Skip A + B + c
            if (v[2] == a + b && v[4] == a + c && v[5] == b + c) {
                s.insert(combo(a, b, c));
            }

            // Skip B + C
            if (v[2] == a + b && v[4] == a + c && v[5] == a + b + c) {
                s.insert(combo(a, b, c));
            }

            // Skip A + C
            if (v[2] == a + b && v[4] == b + c && v[5] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
        // Skip C
        {
            int c = v[3] - a;
            if (v[2] == a + b && v[4] == b + c && v[5] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
    }

    // Skip B
    {
        // C is Smaller
        {
            int a = v[0];
            int c = v[1];
            int b = v[2] - a;
            if (v[3] == a + c && v[4] == b + c && v[5] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
        // C is Larger
        {
            int a = v[0];
            int c = v[2];
            int b = v[1] - a;
            if (v[3] == a + c && v[4] == b + c && v[5] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
    }

    // Skip A
    {
        // C is Smaller
        {
            int b = v[0];
            int c = v[1];
            int a = v[2] - b;
            if (v[3] == a + c && v[4] == b + c && v[5] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
        // A + B is Smaller
        {
            int b = v[0];
            int c = v[2];
            int a = v[1] - b;
            if (v[3] == a + c && v[4] == b + c && v[5] == a + b + c) {
                s.insert(combo(a, b, c));
            }
        }
    }

    // IDK ¯\_(ツ)_/¯
    {
        int a = v[0];
        int b = v[1];
        // C is Smaller
        {
            int c = v[2];
            if ((v[3] == a + c && v[4] == b + c && v[5] == a + b + c) ||
                (v[3] == a + b && v[4] == b + c && v[5] == a + b + c) ||
                (v[3] == a + b && v[4] == a + c && v[5] == a + b + c) ||
                (v[3] == a + b && v[4] == a + c && v[5] == b + c)) {
                s.insert(combo(a, b, c));
            }
        }
        // A + B is Smaller
        {
            int c = v[3];
            if ((v[2] == a + b && v[4] == b + c && v[5] == a + b + c) ||
                (v[2] == a + b && v[4] == a + c && v[5] == a + b + c) ||
                (v[2] == a + b && v[4] == a + c && v[5] == b + c)) {
                s.insert(combo(a, b, c));
            }
        }
    }
}

void seven(vector<int> v) {
    // 2 Posible Outcomes
    int a = v[0];
    int b = v[1];
    // Splits here
    {
        int c = v[2];
        if (v[3] == a + b && v[4] == a + c && v[5] == b + c &&
            v[6] == a + b + c)
            s.insert(combo(a, b, c));
    }
    {
        int c = v[3];
        if (v[2] == a + b && v[4] == a + c && v[5] == b + c &&
            v[6] == a + b + c)
            s.insert(combo(a, b, c));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        s.insert(combo(0, 0, 0));
        switch (n) {
            case 4:
                four(v);
                break;
            case 5:
                five(v);
                break;
            case 6:
                six(v);
                break;
            case 7:
                seven(v);
                break;
        }
        cout << s.size() - 1 << endl;
        s.clear();
    }
}