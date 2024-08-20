#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int N = 2e5+5;
int a[N];int c[N];

void solve()
{
	int n,m;cin>>n>>m;
	vector<int> v;
	map<int,int> mp;
	for(int i=1;i<=n;i++)cin>>a[i]; 
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];v.push_back(a[i]);
		mp[a[i]]=c[i];
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int lu=-1,lv,ans=0;
	for(auto[u,v] :mp)
	{
		if(mp.count(u-1))
		{
			lu=u-1,lv=mp[u-1];
			int X=m-min(m/lu,lv)*lu;
			int U=min(m/lu,lv);
			int V=v;
			
			V-=min(X/u,v);
			X=X-min(X/u,v)*u;
			X=max(0ll,X-min(U,V));
			ans=max(ans,m-X);
		}
		ans=max(ans,min(v,m/u)*u);
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
