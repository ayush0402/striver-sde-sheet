#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define rep(i,k,n)      for(ll i=k; i<n; i++)
#define all(x)          (x).begin(),(x).end()
#define pb              push_back
#define mp              make_pair
#define pf              push_front
#define endl            "\n"
#define debug(...)        __f (#__VA_ARGS__, __VA_ARGS__)

const ll M = 1e9 + 7;
// const ll M = 998244353;

// vector <ll> fact(200001);
// ll binPow(ll x, ll n, ll m) {ll res = 1; while (n) {if (n & 1) res = (res * x) % m; x = (x * x) % m; n >>= 1;} return res;}
// ll ModInv(ll i, ll m) {return binPow(i, m - 2, m);}
// ll ncr(int n, int r) {return (n >= r ? (fact[n] * ModInv(fact[r], M)) % M * ModInv(fact[n - r], M) % M : 0);}
// void factorial() {fact[0] = 1; rep(i, 1, 200001)fact[i] = (fact[i - 1] * i) % M;}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

/*
Debugging:
1. Make sure the approach is correct.
2. Check for edge cases from given inputs.
3. Don't return anything in excitement for finding an edge case before taking in the complete input.
4. Don't forget to clear any global containers before each test case.
5. Dry run the code with possible wrong test cases.
6. Pray!
*/

void solve() {
	vector <int> v = {27, 33, 61, 2, 3, 28, 59, 15, 19, 13, 7};
	sort(all(v));
	rep(i, 0, v.size()) {

	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t ;
	cin >> t;
	while (t--) {
		solve();
	}
}