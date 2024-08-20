#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 

//费马小定理：对于任意一个质数p，一定存在(1/a)=a的(p-2)次方 
//乘法逆元也就是方便的除一个数 
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

int inv(int a)
{
	return ksm(a,p-2);
}

void solve()
{
	cout<<6*inv(2)%p;
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
