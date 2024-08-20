#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

const int N = 2e5+5;
int p[N];
int q[N];

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	cout<<p[n]<<" ";q[1]=p[n];
	for(int i=1;i<=n-1;i++)
	{
		cout<<p[i]<<" ";
		q[i+1]=p[i];
	}
	cout<<endl;
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
