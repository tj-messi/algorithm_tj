#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define ull unsigned long long
#define endl '\n' 

int n, k;
const int N = 2e5+5;
vector<int> a(N + 1), b(N+ 1);
bool check(int mid,vector<array<int, 2>> ta) {
    vector<array<int, 2>> t1;
    for (int i = 1; i < ta.size(); i++) {
        if (ta[i][1] == 0 && ta[i][0] < mid) {
            t1.push_back(ta[i]);
        }
    }
	if (t1.size() >= n / 2) {
        return false;
    }
    for (int i = 1; i < ta.size(); i++) {
        if (ta[i][1] && ta[i][0] < mid) {
            t1.push_back(ta[i]);
        }
    }
    if (t1.size() >= n / 2) {
        int sum = 0;
        for (int i = n / 2 - 1; i < t1.size(); i++) {
            sum += mid - t1[i][0];
        }
        return sum <= k;
    } else {
        return true;
    }
}

void solve()
{

    cin >> n >> k;
	a.clear();b.clear();
    multiset<int> top;
    multiset<int, greater<>> but;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        top.insert(a[i]);
    }
    while (top.size() > but.size()) {
        but.insert(*top.begin());
        top.erase(top.begin());
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] == 1) {
            if (top.find(a[i]) != top.end()) {
                top.erase(top.find(a[i]));
            } else {
                but.erase(but.find(a[i]));
            }
            while (but.size() > top.size()) {
                top.insert(*but.begin());
                but.erase(but.begin());
            }
            while (top.size() > but.size()) {
                but.insert(*top.begin());
                top.erase(top.begin());
            }
            ans = max(ans, k + a[i] + *but.begin());

            but.insert(a[i]);
            while (top.size() && *but.begin() > *top.begin()) {
                top.insert(*but.begin());
                but.erase(but.begin());
            }
        }
    }
	vector<array<int, 2>> ta(1);
    for (int i = 1; i <= n; i++) {
        ta.push_back({a[i], b[i]});
    }
    sort(ta.begin() + 1, ta.end());
    int res = 0, fl = 0;
    for (int i = n; i; i--) {
        if (ta[i][1] == 0) {
            res = ta[i][0];
            ta.erase(ta.begin() + i);
            fl = 1;
            break;
        }
    }
    if (!fl) {
        cout << ans << "\n";
        return;
    }
    int l = 0, r = 1e10;
    
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid,ta)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    ans = max(ans, res + l);
    cout << ans << "\n";
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
