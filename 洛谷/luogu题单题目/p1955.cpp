#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ll long long
#define endl '\n' 
#define ri register int

#define maxn 100007
#define maxnt 1000000007
struct node{
    int a,b,e;
}a[maxn];
int ttttt,f[maxn*2],x[maxn*2],n,lsh[maxn*2],nn,wz[maxn*2];
bool flag;
void mak()
{
    for(register int i=1;i<=nn;i++)	f[i]=i;
}
int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}
bool comp(int a,int b)
{
    return a<b;
}
bool cmp(node a,node b)
{
    return a.e>b.e;
}
int er(int zz)
{
    int l=1,r=nn,m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(lsh[m]==zz) return m;
        if(zz>lsh[m]) l=m+1;
        else r=m-1;
    }
    return zz;
}
void solve()
{ 
	scanf("%d",&n);
        nn=0;
        flag=0;
        for(register int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].e);
            x[i*2-1]=a[i].a,x[i*2]=a[i].b;
        }
        sort(x+1,x+2*n+1,comp);
        for(register int i=1;i<=2*n;i++)
        {
            if(x[i]!=x[i-1])
            {
                lsh[++nn]=x[i];
//				wz[i]=nn;
            }
//			else wz[i]=wz[i-1];
        }
        mak();
        sort(a+1,a+n+1,cmp);
        for(register int i=1;i<=n;i++)
        {
            if(a[i].e)
            {
                int aaa=find(er(a[i].a)),bbb=find(er(a[i].b));
                if(aaa!=bbb) f[aaa]=bbb;
            }
            else
            {
                int aaa=find(er(a[i].a)),bbb=find(er(a[i].b));
                if(aaa==bbb)
                {
                    printf("NO\n");
                    flag=1;
                    break;
                }
            }
        }
        if(!flag) printf("YES\n");
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
