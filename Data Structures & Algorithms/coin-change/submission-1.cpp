#include <cstring>
class Solution {
public:
    int dp[13][10001];
    int helper(int idx,int amount,vector<int>&coins) {
        if(amount==0 || idx==coins.size()) {
            return amount==0 ? 0 : INT_MAX-1;
        }

        if(dp[idx][amount]!=-1)
            return dp[idx][amount];
        
        if(coins[idx]>amount) {
            dp[idx][amount]=0+helper(idx+1,amount,coins);
        }
        else {
            int op1=1+helper(idx,amount-coins[idx],coins);
            int op2=0+helper(idx+1,amount,coins);
            dp[idx][amount]=min(op1,op2);
        }
        return dp[idx][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = helper(0,amount,coins);
        return ans!=INT_MAX-1 ? ans : -1;
    }
};