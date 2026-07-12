class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
      
        vector<int> ans(t.size(),0);
        stack<pair<int,int>> s;
        for(int i=t.size()-1;i>=0;i--)
        {
            while(!s.empty() && s.top().first<=t[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                ans[i]=0;
            }
            else
                ans[i]=s.top().second-i;
            
            s.push({t[i],i});
        }
        
        return ans;
    }
};