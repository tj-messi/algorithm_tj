#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
权值线段树
维护某种权值（通常是计数的桶），可以快速查询每次logn整个数组中第k小元素值。（他的进阶版本主席树可以查区间第k小） 
也是线段树，只不过维护的东西不一样 
*/

const int inf = 2e18;
const int N = 2e5+9;
int n=2e5; int t[N<<2];

void pushup(int o)
{
    t[o]=t[o<<1]+t[o<<1|1];
}

void insert(int val,int s=1,int e=n,int o=1)
{
    if(s == e){
        t[o]++;
        return ;
    }
    int mid=(s+e)>>1;
    if(val<=mid)insert(val,s,mid,o<<1);
    else insert(val,mid+1,e,o<<1|1);
    pushup(o);
}

int  querycnt(int l,int r,int s=1,int e=n,int o=1)
{
    if(l<=s&&r>=e)
    {
        return t[o];
    }
    int res=0;
    int mid=(s+e)>>1;
    if(l<=mid)res+=querycnt(l,r,s,mid,o<<1);
    if(mid+1<=r)res+=querycnt(l,r,mid+1,e,o<<1|1);
    return res;
}

int queryval(int k,int s = 1,int e = n,int o = 1){
    if(s == e) return s;
    int left = t[o << 1];
    int mid = s + e >> 1;
    if(k <= left) return queryval(k,s,mid,o << 1);
    else return queryval(k - left,mid + 1,e, o << 1 | 1);
}

void solve()
{
    int op;cin>>op;
    int l,r,x;
    if(op==1)
    {
        cin>>x;insert(x);
    }
    else if(op==2)
    {
        cin>>l>>r;
        cout<<querycnt(l,r)<<endl;
    }
    else
    {
        cin>>x;cout<<queryval(x)<<endl;
    }

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
