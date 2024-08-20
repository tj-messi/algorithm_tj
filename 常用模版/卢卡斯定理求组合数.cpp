#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

const int p = 1e9+7; 
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int C(int a,int b)
{
	int res=1;
	for(int i=1,j=a;i<=b;i++,j--)
	{
		res=(ll)res*j%p;
		res=(ll)res*ksm(i,p-2)%p;
	}
	return res;
}
int lucas(int a,int b)
{
	if(a<p&&b<p)return C(a,b);
	else return (ll)C(a%p,b%p)*lucas(a/p,b/p)%p;
}

void solve()
{
	//能够处理a，b<=1e18;p<=1e10之内；
	cout<<lucas(5,2);
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
