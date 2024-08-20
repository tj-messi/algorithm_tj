#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

void solve() 
{

    int n, s, v, x;
    cin >> n >> s >> v >> x;

    int L = 0, R = 1e12, ans = 0;

    auto check = [&](int mid) -> bool {
    	int res = 0, g = v, d = x;
    	for (int i = 1; i <= n; i++) {
    		res += g;
    		if (res > mid) {
    			if (d > 0) {
    				d--;
    				g += s;
    				res = g;
    			} else return false;
    		}
    		if (res > mid) return false;
    	}
    	return true;
    };

    while (L <= R) {
    	int mid = L + R >> 1;
    	if (check(mid)) {
    		ans = mid;
    		R = mid - 1;
    	} else {
    		L = mid + 1;
    	}
    }

    cout << ans << endl;

}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	//cin>>t;
	t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
