#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef __int128 ll;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define pb push_back
#define all(x) begin(x), end(x)

#define read(a) int (a); cin >> (a)
#define read2(a, b) read(a); read(b)

#define endl '\n'
#define f first
#define s second

vll z(2200, -1);

int calculate(ll n) {
	if (z[n - 1] == -1) {
		z[n - 1] = calculate(n - 1);
	}
	if (z[n - 3] == -1) {
		z[n - 3] = calculate(n - 3);
	}
	return z[n] = (z[n - 1] + z[n - 3]) % 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	z[0] = 0, z[1] = 0, z[2] = 1;

	cout << calculate(2021) << endl;
	cout << calculate(2022) << endl;
	cout << calculate(2023) << endl;
}