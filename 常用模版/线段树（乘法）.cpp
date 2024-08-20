#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
const int p = 998244353;
ll t[N << 2], mul[N << 2], add[N << 2], a[N];
int n, q;

ll mo(ll x){return (x % p + p) % p;}

/*
乘法线段树，赋值线段树
用每次logn的复杂度维护区间的修改和查询 
*/ 

void pushup(int o)
{
	t[o] = (t[o << 1] + t[o << 1 | 1]) % p;
}

void update(int s, int e, int o, ll k, ll x)
{
	t[o] = mo(mo(t[o] * k % p) + mo((e - s + 1) * x % p));
	mul[o] = mo(k * mul[o]);
	add[o] = mo(mo(k * add[o]) + x);
}

void pushdown(int s, int e, int o)
{
	
	int mid = (s + e) >> 1;
	update(s, mid, o << 1, mul[o], add[o]);
	update(mid + 1, e, o << 1 | 1, mul[o], add[o]);
	
	mul[o] = 1, add[o] = 0;
}

void buildTree(int s = 1, int e = n, int o = 1)
{
	mul[o] = 1;
	if(s == e) return t[o] = a[s], void();
	
	int mid = (s + e) >> 1;
	buildTree(s, mid, o << 1), buildTree(mid + 1, e, o << 1 | 1);
	
	pushup(o);
}

void modify(int l, int r, ll k, ll x, int s = 1, int e = n, int o = 1)
{
	if(l <= s && e <= r) return update(s, e, o, k, x), void();
	
	pushdown(s, e, o);
	
	int mid = (s + e) >> 1;
	if(mid >= l) modify(l, r, k, x, s, mid, o << 1);
	if(mid + 1 <= r) modify(l, r, k, x, mid + 1, e, o << 1 | 1);
	
	pushup(o);
}

ll query(int l, int r, int s = 1, int e = n, int o = 1)
{
	if(l <= s && e <= r) return t[o];
	
	ll res = 0;
	pushdown(s, e, o);
	int mid = (s + e) >> 1;
	if(mid >= l) res = mo(res + query(l, r, s, mid, o << 1));
	if(mid + 1 <=  r) res = mo(res + query(l, r, mid + 1, e, o << 1 | 1));
	return res;
}

void solve()
{
	cin >> n >> q;
	for(int i = 1 ; i <= n ; ++ i) cin >> a[i];
	buildTree();
	while(q--)
	{
		int op; cin >> op;
		if(op == 1)
		{
			int l, r; ll x; cin >> l >> r >> x;
			modify(l, r, 1, x);
		}
		else if(op == 2)
		{
			int l, r; ll x; cin >> l >> r >> x;
			modify(l, r, x, 0);
		}
		else if(op == 3)
		{
			int l, r; ll x; cin >> l >> r >> x;
			modify(l, r, 0, x);
		}
		else if(op == 4)
		{
			int l, r; cin >> l >> r;
			cout << query(l, r) << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}
