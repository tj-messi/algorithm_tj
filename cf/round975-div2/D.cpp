#include <iostream>  
#include <vector>  
#include <algorithm>  
  
using namespace std;  
  
int main() {  
    int t;  
    cin >> t;  
  
    while (t--) {  
        int n;  
        cin >> n;  
  
        vector<int> a(n);  
        for (int i = 0; i < n; ++i) {  
            cin >> a[i];  
        }  
  
        // 从左到右的最大允许时间  
        vector<int> max_right(n, n + 1);  
        for (int i = n - 1; i >= 0; --i) {  
            max_right[i] = min(max_right[i], a[i]);  
            if (i < n - 1) {  
                max_right[i] = min(max_right[i], max_right[i + 1] - 1);  
            }  
        }  
  
        // 从右到左的最大允许时间（反转后的）  
        vector<int> max_left(n, 0);  
        for (int i = 1; i < n; ++i) {  
            max_left[i] = max(max_left[i], max_left[i - 1] + 1);  
            max_left[i] = min(max_left[i], a[i - 1]); // 考虑从i-1到i的时间限制  
        }  
  
        int count = 0;  
        // 遍历每个城市作为起始城市  
        for (int start = 0; start < n; ++start) {  
            if (max_right[start] >= n && max_left[start] == 0) {  
                // 特殊情况：从第一个城市开始，不需要考虑左边的限制  
                count++;  
            } else if (max_left[start] <= start + 1 && max_right[start] >= n) {  
                // 一般情况：确保能从start城市出发满足左右两边的时间限制  
                count++;  
            }  
        }  
  
        cout << count << endl;  
    }  
  
    return 0;  
}
