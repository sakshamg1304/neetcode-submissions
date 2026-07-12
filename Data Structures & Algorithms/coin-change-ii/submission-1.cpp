#include<bits/stdc++.h>
class Solution {
public:
    int dp[301][5001];
    int helper(vector<int>& coins,int amount, int idx) {
        if(amount==0) {
            return 1;
        }
        if(idx<=-1 || amount<0) {
            return 0;
        }

        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }

        int op1 = helper(coins,amount-coins[idx],idx);
        
        int op2 = helper(coins,amount,idx-1);

        return dp[idx][amount] = op1+op2;
        
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return helper(coins,amount,coins.size()-1);
    }
};