#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 


string s ;
long long ans ;
int n ;
const int maxn = 2e5+10 ;
long long h[maxn] , p[maxn] , sum[maxn] , q[maxn] ;
const long long mod = 1e9+7 ;
long long quick_mod(long long x,long long mi){
	long long ret = 1 ; 
	while(mi){
		if(mi&1)ret=ret*x%mod ;
		mi>>= 1 ;
		x = x*x%mod ;
	}
	return ret ;
}
void solve(){
	cin >> s ; n = s.size() ;
	for(long long i = 1 ; i < n ; i++)ans+=i ;
	//cout<<ans<<endl ;
	p[0] = q[0] = 1 ; long long re = quick_mod(2ll,mod-2) ;
	//cout<<n<<endl ;
	for(int i = 1 ; i <= n ; i++)p[i] = p[i-1]*2%mod ;
	for(int i = 1 ; i <= n ; i++)q[i] = q[i-1]*re%mod ;
	//cout<<n<<endl ;
	for(int i = 1 ; i <= n ; i++)sum[i] = (sum[i-1]+p[i]*(s[i-1]-'0'))%mod ;
	//cout<<n<<endl ;
	for(int i = 1 ; i < n ; i++)
	{
		long long h = sum[i] ;
		bool ok = true ;
		for(int j = i+1 ; j <= n ; j+=i)
		{
			int l = j , r = j+i-1 , tmp ;
			if(r>n)
				r = n , h = sum[r-l+1] ;
			tmp = (sum[r] - sum[l-1] + mod ) % mod ;
			if(tmp!=h*p[j-1]%mod){
				ok = false ;
				break ;
			}
		}
		if(ok)ans-=i ;
	}
	cout<<ans<<endl ;
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
