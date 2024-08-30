#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define int long long
#define ull unsigned long long
#define endl '\n' 

const int N = 1e5+5;
int arr[N];

void solve()
{
	int n, a, b;
    cin >> n >> a >> b;
    int c = __gcd(a, b);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        arr[i] %= c;
    }
    sort(arr+1, arr+1+n);
    int max_v= arr[n];
    ll res = max_v - arr[1];
    for (int i = 1; i < n; ++i)
    {
        res = min(res, (ll)arr[i] + c - arr[i + 1]);
    }
    cout << res << endl;
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
