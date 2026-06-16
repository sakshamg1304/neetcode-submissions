class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        // Fix the first element as arr[i] 
        for(int i=0;i<n;i++) {
            int targetSum=-nums[i];

            int l=i+1, r=n-1;

            while(l<r) {
                int sum=nums[l]+nums[r];
                if(sum>targetSum)
                    r--;
                else if(sum<targetSum)
                    l++;
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    int val2=nums[l];
                    int val3=nums[r];
                    while(l<r && nums[l]==val2) l++;
                    while(l<r && nums[r]==val3) r--;
                }
            }

            while (i+1<n && nums[i+1]==nums[i]) 
                i++;
        }
        return ans;
    }
};