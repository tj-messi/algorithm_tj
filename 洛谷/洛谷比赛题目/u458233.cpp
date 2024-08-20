#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 


void solve()
{
	int n,m;cin>>n>>m;
	string a,b;cin>>a>>b;
	int renew=0;
	for(int i=0;i<=b.size()-1;i++)
	{
		if(b[i]=='#')renew++;
	}
	//renew/=25;
	int cnt=0;
	for(int i=0;i<=a.size()-1;i++)
	{
		if(a[i]=='#')
		{
			if((renew+(cnt-1)%26)+1>=26&&(cnt-1)%26+1!=0)
			{
				renew-=(26-((cnt-1)%26+1));
				cnt=1;
				a[i]='a';
			}
			else
			{
				a[i]=(++cnt-2)%26+1+'a';
			}
		}
	}
	cout<<a;
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
