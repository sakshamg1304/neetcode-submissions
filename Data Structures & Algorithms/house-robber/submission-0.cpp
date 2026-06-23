class Solution {
public:
    
    int rob(vector<int>& nums) 
    {
    
        if (nums.size()==0) 
        {
            return 0;
        }  
    
       else if (nums.size()==1) 
       {
        return nums[0];
       }
        
        //vector<int> dp;
        int sz=nums.size();
        int dp[sz];
        dp[0]=nums[0];
        dp[1]=max(nums[1],dp[0]);
        
        int i;
        for(i=2;i<nums.size();i++)
        {
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        
        return dp[sz-1];
        
        
    }
};