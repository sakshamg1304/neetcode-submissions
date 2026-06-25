#include<bits/stdc++.h>
class Solution {
public:
    int dp[1001][1001];
    int fun(string &t1,string &t2,int i,int j,int n1,int n2){
        
        if(i==n1 || j==n2){
            return 0;
        }
        if(dp[i][j]!=-1) 
            return dp[i][j];
        if(t1[i]==t2[j]){
            return dp[i][j]=1+fun(t1,t2,i+1,j+1,n1,n2);
        }
        else{
            int a=fun(t1,t2,i+1,j,n1,n2);
            int b=fun(t1,t2,i,j+1,n1,n2);
            return dp[i][j]=max(a,b);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n1=text1.length();
        int n2=text2.length();
        return fun(text1,text2,0,0,n1,n2);
    }
};