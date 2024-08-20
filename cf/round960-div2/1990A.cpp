#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define endl '\n' 
 
const int N = 55;
int a[N],cnt[N];
 
void solve()
{
	memset(cnt,0,sizeof cnt);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		if(count(a+1,a+1+n,i)%2==1)
		{
			cout<<"YES"<<endl;return;
		}
	}
	cout<<"NO"<<endl;
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
