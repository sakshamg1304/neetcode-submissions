class Solution {
public:
    bool isPalindrome(string s) {
        string s1,s2;
        int i;
        for(i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
                s1+=tolower(s[i]);
            if(isdigit(s[i]))
                s1+=s[i];
        }
        
        for(i=s1.size()-1;i>=0;i--)
        {
            s2+=s1[i];
        }
    
        if(s1==s2)
            return true;
    
        return false;
        
    }
};