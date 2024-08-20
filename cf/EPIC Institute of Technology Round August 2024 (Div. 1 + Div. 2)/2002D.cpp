#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n'
  
void solve() {  
    int n, q;  
    cin >> n >> q;  
  
    // 创建树的邻接表  
    vector<vector<int>> tree(n + 1);  
    vector<int> parent(n + 1);  
    for (int i = 2; i <= n; i++) {  
        cin >> parent[i];  
        tree[parent[i]].push_back(i);  
    }  
  
    // 初始化排列和反向索引  
    vector<int> perm(n + 1);  
    map<int, int> invPerm;  
    for (int i = 1; i <= n; i++) {  
        cin >> perm[i];  
        invPerm[perm[i]] = i;  
    }  
  
    // 计算每个节点的子树大小  
    vector<int> subtreeSize(n + 1, 0);  
    function<void(int)> dfs = [&](int node) {  
        subtreeSize[node] = 1;  
        for (int child : tree[node]) {  
            dfs(child);  
            subtreeSize[node] += subtreeSize[child];  
        }  
    };  
    dfs(1);  
  
    // 检查函数  
    auto isValid = [&](int node) {  
        int idx = invPerm[node];  
        if (perm[idx - 1] == parent[node]) return 1;  
        if (idx - 1 - subtreeSize[node] >= 1 && perm[idx - 1 - subtreeSize[node]] == parent[node]) return 1;  
        return 0;  
    };  
  
    int cnt= 0;  
	vector<int> c (n+1);
    for (int i = 1; i <= n; i++) {
		c[i] = isValid(i);
		cnt += c[i];	
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		swap(perm[x], perm[y]), swap(invPerm[perm[x]], invPerm[perm[y]]);
		x = perm[x], y = perm[y];	
		cnt -= c[x];
		c[x] = isValid(x);
		cnt += c[x];
		
		cnt -= c[y];
		c[y] = isValid(y);
		cnt += c[y];
		for (auto v : tree[x]) {
			cnt -= c[v];
			c[v] = isValid(v);
			cnt += c[v];
		}
		for (auto v : tree[y]) {
			cnt -= c[v];
			c[v] = isValid(v);
			cnt += c[v];
		}

		cout << (cnt == n ? "YES" : "NO") << "\n";
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
