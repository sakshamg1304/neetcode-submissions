class Solution {
public:
    bool helper(vector<int>& nums, int sum, int idx, vector<vector<int>> &dp) {
       if(sum==0)
        return true;

        cout<<idx<<endl;

        if(idx>=nums.size() || sum<0){
            return false;
        } 
        if(dp[idx][sum]!=-1)
            return dp[idx][sum];
        // bool op1=helper(nums,sum-nums[idx],idx+1,dp);
        // bool op2=helper(nums,sum,idx+1,dp);
        return dp[idx][sum]= helper(nums,sum-nums[idx],idx+1,dp) || helper(nums,sum,idx+1,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums)
            sum+=x;
        
        if(sum%2)
            return false;
        int target=sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));

        return helper(nums,target,0,dp);

        
    }
};
