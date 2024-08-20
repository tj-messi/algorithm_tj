#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int inf=2e18;
const int N = 2e5+9;
int n,q;
int tmax[N<<2],tmin[N<<2],lz[N<<2],a[N];

void pushup(int o)
{
    tmin[o]=min(tmin[o<<1],tmin[o<<1|1]);
    tmax[o]=max(tmax[o<<1],tmax[o<<1|1]);
}
void pushdown(int s,int e,int o)
{
    if(!lz[o])return;
    int mid=(s+e)>>1;
    int ls=o<<1,rs=o<<1|1;
    lz[ls]+=lz[o];lz[rs]+=lz[o];
    tmax[ls]+=lz[o];tmin[ls]+=lz[o];
    tmax[rs]+=lz[o];tmin[rs]+=lz[o];
    lz[o]=0;
    return;
}

void buildTree(int s=1,int e=n,int o=1)
{
    if(s==e)
    {
        tmax[o]=tmin[o]=a[s];return;
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
        return tmax[o]+=x,tmin[o]+=x,lz[o]+=x,void(); 
    }
    pushdown(s,e,o);
    int mid=(s+e)>>1;
    if(mid>=l)add(l,r,x,s,mid,o<<1);
    if(mid+1<=r)add(l,r,x,mid+1,e,o<<1|1);
    pushup(o);
    return;
}

int querymax(int l,int r,int s=1,int e=n,int o=1)
{
    if(l<=s&&e<=r)
    {
        return tmax[o];
    }
    pushdown(s,e,o);
    int mid=(s+e)>>1;
    int res=-inf;
    if(mid>=l)res=max(res,querymax(l,r,s,mid,o<<1));
    if(mid+1<=r)res=max(res,querymax(l,r,mid+1,e,o<<1|1));
    return res;
}

int querymin(int l,int r,int s=1,int e=n,int o=1)
{
    if(l<=s&&e<=r)
    {
        return tmin[o];
    }
    pushdown(s,e,o);
    int mid=(s+e)>>1;
    int res=inf;
    if(mid>=l)res=min(res,querymin(l,r,s,mid,o<<1));
    if(mid+1<=r)res=min(res,querymin(l,r,mid+1,e,o<<1|1));
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
            cout<<querymax(l,r)<<" "<<querymin(l,r)<<endl;
        }
    }

    return 0;
}
