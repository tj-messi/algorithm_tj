#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


void solve()
{
	int ans = 0;
	for(int i=1;i<=2024;i++)
	{
		int pow2=0,pow4=0;
		int i2=i,i4=i;
		
		while(i2)
		{
			pow2+=(i2%2);
			i2/=2;
		}
		
		while(i4)
		{
			pow4+=(i4%4);
			i4/=4;
		}
		
		if(pow2==pow4)ans++;	
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
