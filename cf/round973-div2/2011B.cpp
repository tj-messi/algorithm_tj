#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

const int N = 2e5+5;
int a[N];

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int diff=a[n-1];
	for(int i=1;i<n-1;i++)
	{
		if(i==n-1)continue;
		diff-=a[i];
	}
	cout<<a[n]-diff<<endl;
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
