  
# Bovine Genomics
  
## US Open 2017
  
### Gold
  
#### Problem 1
  
For this problem, I used Brute Force to get 7 / 10 with C++ and 8 / 10 with Java. To brute force, I found every combination of strings (shorter than the current minimum) and added them to a set. Then I took the same substring from all the of the plain cows and checked if they existed in the set. It did quite well for a Brute Force in gold.
  
Here is my C++ Solution (7 / 10):
  
```cpp
#include <bits/stdc++.h>
using namespace std;
  
typedef long long ll;
  
#define endl '\n'
  
void setIO(const string& name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
  
vector<string> spot;
vector<string> plan;
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("cownomics");
  
    int n, m;
    cin >> n >> m;
  
    spot.resize(n);
    plan.resize(n);
  
    for (int i = 0; i < n; i++) cin >> spot[i];
    for (int i = 0; i < n; i++) cin >> plan[i];
  
    int mingap = m;
    // Test Each substring
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < min(mingap, m - i); j++) {
            unordered_set<string> spst;
            for (string s : spot) {
                spst.insert(s.substr(i, j));
            }
            bool found = true;
            for (string s : plan) {
                if (spst.count(s.substr(i, j))) {
                    found = false;
                    break;
                }
            }
            if (found) {
                mingap = min(mingap, j);
                break;
            }
        }
    }
  
    cout << mingap << endl;
}
```  
  
Here is my Java Solution (8 / 10):
  
```java
import java.io.*;
import java.util.*;
  
public class BovineGenomics {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("cownomics.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cownomics.out")));
  
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
  
        String[] spot = new String[n];
        String[] plan = new String[n];
  
        for (int i = 0; i < n; i++) spot[i] = in.readLine();
        for (int i = 0; i < n; i++) plan[i] = in.readLine();
  
        int mingap = m;
  
        Set<String> spst = new TreeSet<>();
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < Math.min(mingap, m - i); j++) {
                spst.clear();
                for (String s : spot) {
                    spst.add(s.substring(i, i + j));
                }
                boolean found = true;
                for (String s : plan) {
                    if (spst.contains(s.substring(i, i + j))) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    mingap = Math.min(mingap, j);
                    break;
                }
            }
        }
  
        out.println(mingap);
        in.close();
        out.close();
    }
  
}
```  
  