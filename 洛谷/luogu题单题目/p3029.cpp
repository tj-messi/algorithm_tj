#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int N = 5e4+5;
struct node
{
	int x,id;	
};
node a[N];
vector<node> v;//¿Î…¢ªØ π”√ 
int n;
map<int,int> mp,mp1;

bool cmp(node n1,node n2)
{
	return n1.x<n2.x;
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].id;
	for(int i=1;i<=n;i++)
	{
		v.push_back(a[i]);
		mp[a[i].id]++;mp1[a[i].id]++;
	}
	sort(v.begin(),v.end(),cmp);
	//cout<<l<<" "<<r;
	int l=0;int r=v.size()-1;
	while(1)
	{
		if(mp[v[l].id]>1)
		{
			mp[v[l].id]--;
			l++;
		}
		else
			break;
	}
	while(1)
	{
		if(mp[v[r].id]>1)
		{
			mp[v[r].id]--;
			r--;
		}
		else 
			break;
	}
	int l1=0;int r1=v.size()-1;
	while(1)
	{
		if(mp1[v[r1].id]>1)
		{
			mp1[v[r1].id]--;
			r1--;
		}
		else 
			break;
	}	
	while(1)
	{
		if(mp1[v[l1].id]>1)
		{
			mp1[v[l1].id]--;
			l1++;
		}
		else
			break;
	}
	cout<<min(v[r].x-v[l].x,v[r1].x-v[l1].x);
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
