class Solution {
public:
    int trainWays(int num) {
        if(num==1)
        {
            return 1;
        }
        if(num==0)
        {
            return 1;
        }
        int dp[3]={1,1,0};
        for (int i=1;i<num;i++)
        {
            dp[2]=(dp[0]+dp[1])%1000000007;
            dp[0]=dp[1];
            dp[1]=dp[2];
        }
        return dp[2];
    }
};
