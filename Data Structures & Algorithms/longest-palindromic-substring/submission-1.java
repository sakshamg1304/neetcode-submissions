class Solution {
    public String longestPalindrome(String s) {
        
        // 2 options
        // either string can be of odd length and even legth
        // check for both options and take maximum
        int n=s.length();
        String res = "";
        for(int i=0;i<n;i++) {
            String s1 = palindromeString(s,i,i);
            String s2 = palindromeString(s,i,i+1);

            String finalString = s1.length()> s2.length() ? s1 : s2; 

            res= res.length() > finalString.length() ? res : finalString;
        }
        return res;


    }

    public String palindromeString(String s, int left, int right) {
        while(left>=0 && right<s.length() && s.charAt(left)==s.charAt(right)){
            left--;
            right++;
        }
        return s.substring(left+1,right);
    }
}
