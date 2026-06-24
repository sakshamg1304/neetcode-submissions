class Solution {
    public int countSubstrings(String s) {
        
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++) {
            ans+=palindrome(s,i,i);
            ans+=palindrome(s,i,i+1);
        }
        return ans;
    }

    public int palindrome(String s, int l, int r) {
        int cnt=0;
        while(l>=0 && r<s.length() && s.charAt(l)==s.charAt(r)){
            l--;
            r++;
            cnt++;
        }
        return cnt;
    }
}
