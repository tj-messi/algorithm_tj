#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 



void solve()
{
	int n,k;cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	//int nn=n;
	sort(a.begin() + 1, a.end());
	int mx=a[n];
	for(int i=1;i<=n;i++)
	{
		int temp=a[i]+ceil((1.0*mx-a[i])/(2*k))*(2*k);
		int temp_n=a[i]+(mx-a[i])/(2*k)*(2*k);
		if(temp>a[i])
		{
			a.push_back(temp);
		}
		if(temp!=temp_n&&temp_n>a[i])
		{
			a.push_back(temp_n);
		}
	}
	sort(a.begin() + 1, a.end());
	for(int i=n;i<=a.size()-1;i++)
	{
		int t=a[i-n+1];
		if(a[i]-t<k)
		{
			cout<<a[i]<<endl;
			return;
		}
	}
	cout<<-1<<endl;
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
