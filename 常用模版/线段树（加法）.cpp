#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

/*
线段树：
用nlogn的方法进行初始预操作，用每次logn的复杂度维护一个区间的性质（加法，乘法，异或，最值）
如果没有区间之间的传递性就无法使用线段树 
*/

const int N = 2e5+9;
int n,q;
int t[N<<2],lz[N<<2],a[N];

void pushup(int o)
{
     t[o]=t[o<<1]+t[o<<1|1];
}
void pushdown(int s,int e,int o)
{
    if(!lz[o])return;
    int mid=(s+e)>>1;
    int ls=o<<1,rs=o<<1|1;
    t[ls]+=(mid-s+1)*lz[o],lz[ls]+=lz[o];
     t[rs]+=(e-mid)*lz[o],lz[rs]+=lz[o];
    lz[o]=0;
    return;
}

void buildTree(int s=1,int e=n,int o=1)
{
    if(s==e)
    {
        t[o]=a[s];return;
    }
    int mid=(s+e)>>1;
    buildTree(s,mid,o<<1);buildTree(mid+1,e,o<<1|1);
    pushup(o);
    return;
}
 

void add(int l,int r,int x,int s=1,int e=n,int o=1)
{
    if(l<=s&&e<=r)
    {
        return t[o]+=(e-s+1)*x,lz[o]+=x,void(); 
    }
    pushdown(s,e,o);
    int mid=(s+e)>>1;
    if(mid>=l)add(l,r,x,s,mid,o<<1);
    if(mid+1<=r)add(l,r,x,mid+1,e,o<<1|1);
    pushup(o);
    return;
}

int query(int l,int r,int s=1,int e=n,int o=1)
{
    if(l<=s&&e<=r)
    {
        return t[o];
    }
    pushdown(s,e,o);
    int mid=(s+e)>>1;
    int res=0;
    if(mid>=l)res+=query(l,r,s,mid,o<<1);
    if(mid+1<=r)res+=query(l,r,mid+1,e,o<<1|1);
    return res;
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    buildTree();
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int l,r,x;cin>>l>>r>>x;
            add(l,r,x);
        }
        else
        {
            int l,r;cin>>l>>r;
            cout<<query(l,r)<<endl;
        }
    }

    return 0;
}
