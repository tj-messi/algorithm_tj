#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

const int N = 105;
int a[N]; 
void solve()
{
	int n;cin>>n;
	int sum1=0;
	int sum2=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			sum1=max(sum1,a[i]);
		}
		else
			sum2=max(sum2,a[i]);
	}
	cout<<max(sum1+n/2,sum2+n/2+(n%2==0 ? 0 : 1))<<endl;
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
