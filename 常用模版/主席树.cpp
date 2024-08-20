#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

/*
可持久化线段树
就是借用动态开点,还有对点的复用,用logn每次的复杂度查询区间的第k大值和插入
每次开点的时候都进行一次判断是否可以利用原来的树 
*/

const int N = 2e5 + 3;
int n,m;
struct{
    int ls,rs,val;
}tree[N << 5];
int num[N],rt[N];//表示存入数的状态的起点
vector<int> X;
int idx;

int bin(int x){
    return lower_bound(X.begin(),X.end(),x) - X.begin() + 1;
}

void insert(int &o,int pre,int val,int s = 1,int e = n){
    o = ++idx;
    tree[o] = tree[pre];
    ++tree[o].val;
    int mid = (s + e) >> 1;
    if(s == e) return ;
    if(val <= mid) insert(tree[o].ls,tree[pre].ls,val,s,mid);
    else insert(tree[o].rs,tree[pre].rs,val,mid+1,e);
}

int queryVal(int l,int r,int k,int s = 1,int e = n){
    if(s == e) return s;
    int mid = (s + e) >> 1;
    int left = tree[tree[r].ls].val -  tree[tree[l].ls].val;
    if(k <= left) return queryVal(tree[l].ls,tree[r].ls,k,s,mid);
    else return queryVal(tree[l].rs,tree[r].rs,k - left,mid + 1,e);
}

void solve()
{
   cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        X.push_back(num[i]);
    }
    sort(X.begin(), X.end());
    for(int i = 1; i <= n; i++) insert(rt[i],rt[i-1],bin(num[i]));
    int k,l,r;
    for(int i = 1; i <= m; i++){
        cin >> l >> r >> k;
        cout << X[queryVal(rt[l-1],rt[r],k) - 1] << "\n";
    }
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
