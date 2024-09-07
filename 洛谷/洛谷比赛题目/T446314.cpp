#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 



void solve()
{
	int n,m,k; 
	cin>>n>>m>>k;
	int count=0;
	if(k>=min(n,m))
	{
		count=min(n,m);
		k-=min(n,m);
	}
	else
	{
		count=k;
		k=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==j&&count)
			{
				cout<<'S';
				count--;
			}
			else if(k)
			{
				cout<<'S';
				k--;
			} 
			else cout<<'.';
		}
		cout<<endl;
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
