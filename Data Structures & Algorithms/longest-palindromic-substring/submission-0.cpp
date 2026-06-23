class Solution {
public:
    string longestPalindrome(string s) {
        string res="";

        // 2 options
        // either string can be of odd length and even legth
        // check for both options and take maximum

        
        for(int i=0; i< s.size() ; i++)
        {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i+1);
            string s = s1.size() > s2.size () ? s1 : s2;
            res = s.size() > res.size() ? s : res ;
        }
     
       return res; 
    }
       
        
        string palindrome(string s, int left, int right)
        {
            while(left>=0 && right <s.size() && s[left]==s[right])
            {
                left--;
                right++;
            }
            return s.substr(left+1, right-left-1);
        }
        
    
};