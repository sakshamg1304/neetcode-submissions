class Solution {
    public int countSubstrings(String s) {
        
        int n=s.length();
        int[] ans={0};
        for(int i=0;i<n;i++) {
            palindrome(s,i,i,ans);
            palindrome(s,i,i+1,ans);
        }
        return ans[0];
    }

    public void palindrome(String s, int l, int r, int[] ans) {
        while(l>=0 && r<s.length() && s.charAt(l)==s.charAt(r)){
            l--;
            r++;
            ans[0]++;
        }
    }
}
