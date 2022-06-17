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

bool isPossible(vector<ll>& x, ll mid, ll cows) {
	ll cnt = 1;
	ll last = x[0];
	rep(i, 1, x.size()) {
		if (x[i] - last >= mid) {
			cnt++;
			last = x[i];
		}
	}
	if (cnt >= cows) {
		return true;
	}
	return false;
}

void solve() {
	ll n, c; cin >> n >> c;
	vector <ll> x(n);
	rep(i, 0, n)cin >> x[i];
	sort(all(x));
	ll res = -1;
	ll lo = 1; ll hi = 1e9;
	ll mid = lo - (lo - hi) / 2;
	while (lo <= hi) {
		mid = lo - (lo - hi) / 2;
		if (isPossible(x, mid, c)) {
			res = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << res << endl;
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
