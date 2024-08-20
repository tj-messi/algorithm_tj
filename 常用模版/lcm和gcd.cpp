#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);	
} 

int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}

void solve()
{
	cout<<gcd(12,8)<<endl;
	cout<<lcm(2,3)<<endl;
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
