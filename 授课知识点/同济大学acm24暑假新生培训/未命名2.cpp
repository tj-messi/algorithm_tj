class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.size();
        if(k==1)return len;
        if(len<k)return 0;
        int cnt[26] = {0};
        for(int i=0;i<len;i++)
        {
            cnt[s[i]-'a']++;
        }
        int i = 0;
        while (i < len && cnt[s[i]-'a'] >= k) ++i;
        if (i == len) return len;
        int left = longestSubstring(s.substr(0, i), k);
        while (i < len && cnt[s[i]-'a'] < k) ++i;
        int right = longestSubstring(s.substr(i), k);
        return max(left, right);
    }
};
