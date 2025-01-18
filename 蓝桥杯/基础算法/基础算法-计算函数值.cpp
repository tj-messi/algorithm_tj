#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

//¼òµ¥µÝ¹é 

int Sfun(int x)
{
	if(x==0)return 1;
	else if(x%2==0)return Sfun(x/2);
	else return Sfun(x-1)+1;
} 

void solve()
{
	int n;cin>>n;
	cout<<Sfun(n)<<endl;
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
