#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 


void solve()
{
	int l, x, y;
    cin >> l >> x >> y;
    if (l * l >= (x - l) * (x - l) + y * y)
    {
        cout << "Yes\n" << l << '\n';
    }
    else if (l * l >= x * x + y * y)
    {
        cout << "Yes\n0\n";
    }
    else
    {
        cout << "No\n";
    }
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
