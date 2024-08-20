#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

const int N = 3e5+5;
int a[N],b[N];

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	bool flag1=true,flag2=true;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])flag1=false;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[n-i+1])flag2=false;
	}
	if(flag1||flag2)
		cout<<"Bob"<<endl;
	else
		cout<<"Alice"<<endl;
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
