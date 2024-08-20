#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ll long long
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<ll> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	ll ans = 0, now = 0;

	for (int i = 2; i <= n; i++) {
		
		if (arr[i] < arr[i - 1]) {
			ll y = 0;
			if (arr[i] == 1) {
				cout << "-1\n";
				return;
			}
			for (ll tmp = arr[i]; tmp < arr[i - 1]; tmp *= tmp) {
 	 	 	 	y += 1;
 	 	 	}
 	 	 	now += y;
		} else {
			ll y = 0;
			if (arr[i - 1] != 1) {
				for (ll tmp = arr[i - 1]; tmp <= arr[i]; tmp *= tmp) {
	          		y += 1;
		        }
		        y -= 1;
		        now = max(0LL, now - y);
			}
		}
		ans += now;
	}

	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	//t=1;
	while(t--)
	{
		solve();
	}
	return 0;
} 
