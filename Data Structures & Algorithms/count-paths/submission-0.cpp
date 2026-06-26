class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return dfs(dp,m-1,n-1);
    }
    
    int dfs(vector<vector<int>>&dp,int row,int col){//n^2  n 
        if(row==0)return 1;
        if(col==0)return 1;
        if(dp[row][col]!=-1)return dp[row][col];        
        int val= dfs(dp,row-1,col)+dfs(dp,row,col-1);
        dp[row][col]=val;
        return val;
    }
};