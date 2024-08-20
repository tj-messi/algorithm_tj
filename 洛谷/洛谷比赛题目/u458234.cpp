#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

//想法一：一定是移动到队列最末尾增加一段时间的t 

void solve()
{
	int inf=0x3f3f3f3f3f3f3f;
	int n,m;cin>>n>>m;
	vector<int> l(n);//记录种植的左节点 
	vector<int> potential_plus(n);//潜藏的收益 
	for(int i=0;i<=n-1;i++)cin>>l[i];
	sort(l.begin(),l.end());
	//for(int i=0;i<=l.size()-1;i++)cout<<l[i]<<" ";
	int ans=0;//目前的收益 
	for(int i=0;i<=l.size()-1;i++)
	{
		int l1=-inf,l2=-inf,r1=inf,r2=inf;
		if(i-1>=0)l1=l[i-1]+m-1;
		if(i-2>=0)l2=l[i-2]+m-1;
		if(i+1>=0)r1=l[i+1];
		if(i+2>=0)r2=l[i+2];
		ans+=max(0ll,(m-max(0ll,(l1-l[i]+1))-max(0ll,(l[i]+m-r1))));
		//cout<<ans<<" "<<max(0ll,(l1-l[i]+1))<<" "<<max(0ll,(l[i]+m-r1))<<endl;
		potential_plus[i]+=max(0ll,(min((l1-l[i]+1),l1-l2)));//左边的潜在收益
		potential_plus[i]+=max(0ll,(min(l[i]+m-r1,r2-r1)));//右边的潜在收益
		if(l1>=r1)potential_plus[i]-=2*(l1-r1+1);
		cout<<potential_plus[i]<<" "<<max(0ll,(min((l1-l[i]+1),l1-l2)))<<" "<<max(0ll,(min(l[i]+m-r1,r2-r1)))<<endl;
	}
	sort(potential_plus.begin(),potential_plus.end());
	
	//cout<<ans+potential_plus[n-1]+m<<endl; 
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
