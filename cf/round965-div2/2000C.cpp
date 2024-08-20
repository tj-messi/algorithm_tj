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
            // ����ѡ��С��mid����������ͳ��  
            continue;  
        }  
        if (p.first < mid) {  
            count++;  
            if (p.second) {  
                // ��ѡ��С��mid������Ҫ�����ܺ�  
                sum += mid - p.first;  
            }  
        }  
        if (count >= n / 2) {  
            // �����ѡ��Ŀ�ѡ���򲻿�ѡ��С��mid��������һ�룬����ܺ�  
            return sum <= k;  
        }  
    }  
    // û�дﵽһ��Ŀ�ѡ���򲻿�ѡ��С��mid������Ĭ��ͨ��  
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
  
    sort(ta.rbegin(), ta.rend());  // ��ֵ�Ӵ�С����  
  
    int ans = 0;  
    for (auto& p : ta) {  
        if (!p.second) {  
            // �ҵ���һ������ѡ��������Ϊ���ܵĴ�  
            ans = p.first;  
            break;  
        }  
    }  
  
    if (ans == 0) {  
        // ���û�в���ѡ��������ֱ�Ӽ����ѡ��������  
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
