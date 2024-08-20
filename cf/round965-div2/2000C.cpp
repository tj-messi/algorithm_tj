#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;  
  
#define int long long  
  
bool check(int mid, const vector<pair<int, bool>>& ta, int n, int k) {  
    int count = 0;  
    int sum = 0;  
    for (auto& p : ta) {  
        if (p.second == 0 && p.first < mid) {  
            // 不可选且小于mid的数不计入统计  
            continue;  
        }  
        if (p.first < mid) {  
            count++;  
            if (p.second) {  
                // 可选且小于mid的数需要计入总和  
                sum += mid - p.first;  
            }  
        }  
        if (count >= n / 2) {  
            // 如果已选择的可选数或不可选但小于mid的数超过一半，检查总和  
            return sum <= k;  
        }  
    }  
    // 没有达到一半的可选数或不可选但小于mid的数，默认通过  
    return true;  
}  
  
void solve() {  
    int n, k;  
    cin >> n >> k;  
    vector<int> a(n + 1), b(n + 1);  
    vector<pair<int, bool>> ta;  
  
    for (int i = 1; i <= n; i++) {  
        cin >> a[i];  
    }  
  
    for (int i = 1; i <= n; i++) {  
        cin >> b[i];  
        ta.push_back({a[i], b[i] == 1});  
    }  
  
    sort(ta.rbegin(), ta.rend());  // 按值从大到小排序  
  
    int ans = 0;  
    for (auto& p : ta) {  
        if (!p.second) {  
            // 找到第一个不可选的数，作为可能的答案  
            ans = p.first;  
            break;  
        }  
    }  
  
    if (ans == 0) {  
        // 如果没有不可选的数，则直接计算可选数的最大和  
        for (auto& p : ta) {  
            if (p.second && p.first <= k) {  
                ans = max(ans, p.first);  
            }  
        }  
        cout << ans << endl;  
        return;  
    }  
  
    int l = 0, r = 1e10;  
    while (l < r) {  
        int mid = (l + r + 1) >> 1;  
        if (check(mid, ta, n, k)) {  
            l = mid;  
        } else {  
            r = mid - 1;  
        }  
    }  
  
    ans = max(ans, l);  
    cout << ans << endl;  
}  
  
int main() {  
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
    int t;  
    cin >> t;  
    while (t--) {  
        solve();  
    }  
    return 0;  
}
