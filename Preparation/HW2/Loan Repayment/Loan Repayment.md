  
# Loan Repayment
  
## January 2020
  
### Silver
  
#### Problem 2
  
The first observation is to notice the bounds of <img src="https://latex.codecogs.com/gif.latex?N"/>, which can be as large as <img src="https://latex.codecogs.com/gif.latex?10^{12}"/>. With N being this large, our algorithm can't be proportional to <img src="https://latex.codecogs.com/gif.latex?N"/>, so it must use something like <img src="https://latex.codecogs.com/gif.latex?&#x5C;log{N}"/> or <img src="https://latex.codecogs.com/gif.latex?&#x5C;sqrt{N}"/>. The following solution is something along the lines of <img src="https://latex.codecogs.com/gif.latex?&#x5C;sqrt{N}&#x5C;log{N}"/>.
  
The first step of this problem is quite simple: we will simply [Binary Search](https://usaco.guide/silver/binary-search?lang=cpp ) on a function for <img src="https://latex.codecogs.com/gif.latex?X"/>. The tricky part comes when trying to see if <img src="https://latex.codecogs.com/gif.latex?X"/> will work.
  
To find if any <img src="https://latex.codecogs.com/gif.latex?X"/> works requires a bit of math. A naive approach would be to keep calculating <img src="https://latex.codecogs.com/gif.latex?Y"/> until you have paid off <img src="https://latex.codecogs.com/gif.latex?N"/> or reached time <img src="https://latex.codecogs.com/gif.latex?K"/>, but that can become proportional <img src="https://latex.codecogs.com/gif.latex?N"/>, which we previously noticed would not work.
  
You must first notice the significance of the floor function; what this allows is to have a continuous portion where Farmer John will be paying back the same amount of money. Therefore, if we can find out how long each value of <img src="https://latex.codecogs.com/gif.latex?Y"/> needs to be paid for, we can significantly shorten the calculation time. To find that out, we can use the following proof.
  
<p align="center"><img src="https://latex.codecogs.com/gif.latex?&#x5C;text{Let%20}%20G%20=%20&#x5C;text{The%20Amount%20Already%20Given}%20&#x5C;&#x5C;
&#x5C;text{Let%20}%20N%20=%20&#x5C;text{The%20Total%20Amount%20Owed}%20&#x5C;&#x5C;
&#x5C;text{Let%20}%20X%20=%20&#x5C;text{A%20Constant%20Value}%20&#x5C;&#x5C;
&#x5C;text{Let%20}%20Y%20=%20&#x5C;left&#x5C;lfloor&#x5C;frac{N%20-%20G}{X}&#x5C;right&#x5C;rfloor"/></p>  
  
These are values that we were already given to us, but we need to find a few of our own values. Namely
  
<p align="center"><img src="https://latex.codecogs.com/gif.latex?G_{max}%20=%20&#x5C;text%20{The%20most%20that%20can%20be%20given%20until%20}%20Y%20&#x5C;text{changes}"/></p>  
  
To find <img src="https://latex.codecogs.com/gif.latex?G_{max}"/>, we can remove the floor from our equation, since finding the maximum <img src="https://latex.codecogs.com/gif.latex?G"/> by definition will be removing the floor (as there will be no remainder to truncate). If we solve for <img src="https://latex.codecogs.com/gif.latex?G_{max}"/> using our equation of Y, we can get that
  
<p align="center"><img src="https://latex.codecogs.com/gif.latex?G_{max}%20=%20N%20-%20XY"/></p>  
  
Now that we have solved for the maximum that can be given, we just need to calculate how many times we can give <img src="https://latex.codecogs.com/gif.latex?Y"/> before reaching the maximum, which is simply how far we are from the maximum right now divided by Y, or:
  
<p align="center"><img src="https://latex.codecogs.com/gif.latex?&#x5C;text{Let%20}%20T%20&#x5C;text%20{%20be%20the%20number%20of%20iterations}%20=%20&#x5C;left&#x5C;lfloor&#x5C;frac{G_{max}%20-%20G_{cur}}{Y}&#x5C;right&#x5C;rfloor%20+%201"/></p>  
  
Note: We need to add one to include the <img src="https://latex.codecogs.com/gif.latex?Y"/> currently.
  
Now, we can simply use <img src="https://latex.codecogs.com/gif.latex?T"/> to update all the values:
  
<p align="center"><img src="https://latex.codecogs.com/gif.latex?G%20=%20G_{cur}%20+%20YT&#x5C;&#x5C;
T_{total}%20=%20T_{total_0}%20+%20T"/></p>  
  
If our total <img src="https://latex.codecogs.com/gif.latex?T"/> when we have paid off the loan is more than <img src="https://latex.codecogs.com/gif.latex?K"/>, we know that <img src="https://latex.codecogs.com/gif.latex?X"/> is too large.
  
Here is my implementation of this solution:
  
```cpp
#include <bits/stdc++.h>
using namespace std;
  
typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
  
#define pb push_back
#define all(x) begin(x), end(x)
  
#define ffor(i,a,b) for (int i = (a); i < (b); ++i)
#define ff0r(i,a) ffor(i,0,a)
#define rrof(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rr0f(i,a) rrof(i,0,a)
#define trav(a,x) for (auto& a: x)
#define fforn ff0r(i, n)
  
#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)
  
#define endl '\n'
#define f first
#define s second
  
void setIO(const string& name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
  
bool work(ll n, ll k, ll m, ll x) {
    ll t = 0;
    ll g = 0;
  
    while (g < n && k) {
        ll y = (n - g) / x;
        // Check if we need to use m
        if (y <= m) {
            t += (n - g + m - 1) / m;
            return t <= k;
        }
  
        ll gmax = n - x * y;
        ll time = (gmax - g) / y + 1;
        g += y * time;
        t += time;
    }
  
    return t <= k;
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("loan");
  
    ll n, k, m;
  
    cin >> n >> k >> m;
  
    ll x = 1;
    for (int jump = 1e9; jump >= 1; jump >>= 1) {
        while (work(n, k, m, x + jump)) x += jump;
    }
  
    cout << x << endl;
}
```  
  