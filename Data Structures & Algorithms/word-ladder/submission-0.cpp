class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s1;
        for(auto x: wordList) {
            s1.insert(x);
        }
        if(s1.find(endWord)==s1.end())
            return 0;

        set<string> visited;

        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int ans=1;
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto curr=q.front();
                q.pop();

                for(int i=0;i<curr.length();i++) {
                    if (curr == endWord)
                        return ans;
                    
                    string tmp=curr;
                    for(char ch='a';ch<='z';ch++) {
                        if (tmp[i] == ch)
                            continue;
                        
                        tmp[i]=ch;

                        if(s1.find(tmp)!=s1.end() && visited.find(tmp)==visited.end()) {
                            q.push(tmp);
                            visited.insert(tmp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};