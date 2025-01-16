#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
                                        

void solve()
{
	int n;cin>>n;
	int ans=0;
	vector<string> v(n+2);
	for(int i = 1;i<=n;i++)
	{
		cin>>v[i]; 
		if(i!=1)
		{
			if(v[i][0]!=v[i-1][1])ans++;
		}
	} 
	cout<<ans<<endl;
}


signed main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
