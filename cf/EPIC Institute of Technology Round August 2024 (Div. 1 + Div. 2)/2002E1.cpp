#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define MAXN 200005
#define MOD 1000000007


#include<iostream>
using namespace std;
#define maxn 300005
int N, Q;
int M(int a, int b)
{

    return a >= b ? a : b;
}
struct node
{
    int left;
    int right;
    int max;
};
struct node tree[maxn * 4];

void buildtree(int index, int left, int right)
{
    tree[index].left = left;
    tree[index].right = right;
    tree[index].max = 0;
    if (left == right)
    {
        return;
    }
    int mid = (left + right) >> 1;
    buildtree((index << 1) + 1, left, mid);
    buildtree((index << 1) + 2, mid + 1, right);
    return;

}

void insert(int index, int left, int right, int k)
{

    int mid = (tree[index].left + tree[index].right) >> 1;
    if (tree[index].left == tree[index].right)
    {
        tree[index].max = k;

        return;
    }
    if (right <= mid)
    {
        if (tree[index].max <= k)
            tree[index].max = k;
        insert((index << 1) + 1, left, right, k);
        return;
    }
    else
        if (left > mid)
        {
            if (tree[index].max <= k)
                tree[index].max = k;
            insert((index << 1) + 2, left, right, k);
            return;
        }
}

int query(int index, int left, int right)
{
    int mid = (tree[index].left + tree[index].right) >> 1;
    if (tree[index].left == tree[index].right)
    {
        return tree[index].max;
    }
    if (right <= mid)
    {
        return query((index << 1) + 1, left, right);
    }
    else
        if (left > mid)
        {
            return query((index << 1) + 2, left, right);
        }
        else
        {
            return M(query((index << 1) + 1, left, mid), query((index << 1) + 2, mid + 1, right));
        }
}

signed main()
{
    long long tt = 0;
    cin >> tt;
    for (long long ii = 0; ii < tt; ++ii)
    {
        long long n;
        cin >> n;
        vector<long long>a(n + 1), b(n + 1);
        unordered_map<long long, long long>last_index;
        vector<long long>gg_time(n + 1, 0);
        vector<long long>res;
        buildtree(0, 1, n + 1);
        for (long long i = 1; i <= n; ++i)
        {
            cin >> a[i] >> b[i];
        }
        long long val = 0;
        for (long long i = 1; i <= n; ++i)
        {
            if (last_index[b[i]] == 0)
            {
                gg_time[i] = a[i];
                last_index[b[i]] = i;
            }
            else
            {
                long long get = query(0, last_index[b[i]] + 1, i - 1);//tree.queryRange(last_index[b[i]] + 1, i - 1);//pre_sum[i - 1] - pre_sum[last_index[b[i]]];
                if (get >= a[i])
                    gg_time[i] = a[i];
                else
                {
                    gg_time[i] = gg_time[last_index[b[i]]] + a[i] - get;
                }
                last_index[b[i]] = i;
            }
            insert(0, i, i, gg_time[i]);
            val = max(val, gg_time[i]);
            res.push_back(val);
        }
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
