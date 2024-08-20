#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	ll m, k, h;
	cin >> m >> k >> h;

	if (m == k) {
		cout << min(m, h) << "\n";
		return;
	}

	if (h <= m) {
		cout << h << "\n";
		return;
	}

	ll L = m, R = h, res = h;
	while (L <= R) {
		ll mid = L + R >> 1;
		ll x = mid - m;
		if ((x / (m - k) + 1) * k + mid >= h) {
			res = mid;
			R = mid - 1;
		} else {
			L = mid + 1;
		}
	}

	cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
