#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int N = 2e5+5;
int a[N];

void solve()
{
	int ans=0;
	int max_single=1;
	int sum_double=0;
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]%2==1)max_single=max(max_single,a[i]);
		else sum_double++;
	}
	sort(a+1,a+1+n);
	if(sum_double==n||sum_double==0)
	{
		cout<<0<<endl;return;
	}
	
	if(a[n]==max_single)
	{
		cout<<sum_double<<endl;return;
	}
	else
	{
		int res=0;
		vector<int> v;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==0)
			{
				if(a[i]<max_single)
				{
					res++;max_single+=a[i];
				}
				else 
					v.push_back(a[i]);
			}
		}
		if(v.size()!=0)res+=(1+v.size());
		cout<<res<<endl;return;
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
