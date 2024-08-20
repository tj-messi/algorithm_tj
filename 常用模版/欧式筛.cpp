#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int N = 1e8+5;
int v[N];
int ola[6000010];
int cnt=0;

void prime(int n)
{
	v[0]=v[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=i;
			ola[++cnt]=i;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(ola[j]>n/i||ola[j]>v[i])break;
			v[i*ola[j]]=ola[j];
		}
	}
}

void solve()
{
	prime(10000);
	for(int i=1;i<=10;i++)
	{
		cout<<ola[i]<<" ";//按照顺序输出前10个素数 
	}
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
