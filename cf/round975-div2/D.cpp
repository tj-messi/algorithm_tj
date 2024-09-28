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
  
        // �����ҵ��������ʱ��  
        vector<int> max_right(n, n + 1);  
        for (int i = n - 1; i >= 0; --i) {  
            max_right[i] = min(max_right[i], a[i]);  
            if (i < n - 1) {  
                max_right[i] = min(max_right[i], max_right[i + 1] - 1);  
            }  
        }  
  
        // ���ҵ�����������ʱ�䣨��ת��ģ�  
        vector<int> max_left(n, 0);  
        for (int i = 1; i < n; ++i) {  
            max_left[i] = max(max_left[i], max_left[i - 1] + 1);  
            max_left[i] = min(max_left[i], a[i - 1]); // ���Ǵ�i-1��i��ʱ������  
        }  
  
        int count = 0;  
        // ����ÿ��������Ϊ��ʼ����  
        for (int start = 0; start < n; ++start) {  
            if (max_right[start] >= n && max_left[start] == 0) {  
                // ����������ӵ�һ�����п�ʼ������Ҫ������ߵ�����  
                count++;  
            } else if (max_left[start] <= start + 1 && max_right[start] >= n) {  
                // һ�������ȷ���ܴ�start���г��������������ߵ�ʱ������  
                count++;  
            }  
        }  
  
        cout << count << endl;  
    }  
  
    return 0;  
}
