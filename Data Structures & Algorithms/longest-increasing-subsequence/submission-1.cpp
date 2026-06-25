#include<bits/stdc++.h>
class Solution {
public:
    int dp[2505][2505];
    int helper(vector<int>& nums,int idx,int prev_idx) {
        int n = nums.size();
        if(idx==n)
            return 0;
        
        if(dp[idx][prev_idx+1]!=-1)
            return dp[idx][prev_idx+1];
        
        int op1=0,op2=0;
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            op1 = 1+helper(nums,idx+1,idx);
        }
        op2 = helper(nums,idx+1,prev_idx);

        return dp[idx][prev_idx+1]=max(op1,op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(nums,0,-1);
        
    }
};