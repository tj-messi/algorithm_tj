#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int N = 2e5+5;
int a[N];

void solve()
{
	int n,m;cin>>n>>m;
	vector<int> v;
	map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];v.push_back(a[i]);
		if(mp[a[i]]==0)mp[a[i]]=1;
		else mp[a[i]]++;
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int ans=0;
	for(int i=0;i<=v.size()-1;i++)
	{
		if(v[i]+1==v[i+1])
		{
			int temp=0;
			for(int j=0;j<=mp[v[i]];j++)
			{
				if(j*v[i]<=m&&((m-j*v[i])/v[i+1]<=mp[v[i+1]]))
				{
					temp=max(temp,(j*v[i]+(m-j*v[i])/v[i+1]*v[i+1]));
				}
				else if(j*v[i]<=m&&((m-j*v[i])/v[i+1]>mp[v[i+1]]))
				{
					temp=max(temp,(j*v[i]+mp[v[i+1]]*v[i+1]));
				}
			}
			ans=max(ans,temp);
		}
		else
		{
			int temp;
			if(v[i]*mp[v[i]]<=m)temp=v[i]*mp[v[i]];
			else temp=m/v[i]*v[i];
			ans=max(ans,temp);
		}
	}
	cout<<ans<<endl;
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
