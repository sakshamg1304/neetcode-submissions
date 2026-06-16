class Solution {
public:
    void topoDfs(int idx,  vector<vector<int>> &graph,  vector<int> &vis, stack<int> &st) {
        vis[idx] = true;
        for(auto x:graph[idx]) {
            if(!vis[x]) {
                topoDfs(x, graph,vis, st);
            }
        }
        st.push(idx);
    }
    bool checkCycle(int i, vector<vector<int>> &graph, vector<int> &vis, vector<int> &recPath) {
        vis[i]=true;
        recPath[i] = true;

        for(auto x: graph[i]) {
            if(!vis[x]) {
                if(checkCycle(x,graph,vis,recPath))
                    return true;
            } else if(recPath[x]) {
                return true;
            }
        }

        recPath[i]=false;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);

        for(int i=0;i<prerequisites.size();i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            graph[u].push_back(v);
        }  
        vector<int> vis(n,false);  
        vector<int> recPath(n,false);

        // check cycle exists or not
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                if(checkCycle(i,graph,vis, recPath))
                    return {};
            }
        }
        stack<int> st;
        vis.assign(n,false);

        for(int i=0;i<n;i++) {
            if(!vis[i])
                topoDfs(i,graph,vis,st);
        }
        vector<int> ans;

        while(!st.empty()) {
            auto val = st.top();
            st.pop();
            ans.push_back(val);
        }
        return ans;
    }
};