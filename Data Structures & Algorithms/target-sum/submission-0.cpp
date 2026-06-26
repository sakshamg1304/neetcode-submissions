class Solution {
public:
    int helper(vector<int>& nums, vector<vector<int>> &dp, int target, int idx, int currSum) {
        if(idx==nums.size() && currSum==target) {
            return 1;
        }
        if(idx>=nums.size()) {
            return 0;
        }

        if(dp[idx][currSum+1000]!=INT_MIN)
            return dp[idx][currSum+1000];
        
        //add currentNumber
        int op1=helper(nums,dp,target,idx+1,currSum+nums[idx]);
        //subtract currentNumber
        int op2=helper(nums,dp,target,idx+1,currSum-nums[idx]);

        dp[idx][currSum+1000]=op1+op2;
        return dp[idx][currSum+1000];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+2,vector<int>(2005,INT_MIN));
        return helper(nums,dp,target,0,0);
    }
};