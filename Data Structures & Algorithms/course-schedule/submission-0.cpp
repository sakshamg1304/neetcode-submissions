class Solution {
public:

    bool isCycle(int i, vector<vector<int>> &graph, vector<int> &vis, vector<int> &recPath) {
        vis[i]=true;
        recPath[i] = true;

        for(auto x: graph[i]) {
            if(!vis[x]) {
                if(isCycle(x,graph,vis,recPath))
                    return true;
            } else if(recPath[x]) {
                return true;
            }
        }

        recPath[i]=false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);

        for(int i=0;i<prerequisites.size();i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            graph[u].push_back(v);
        }
        vector<int> vis(n,false);
        vector<int> recPath(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(i,graph,vis,recPath))
                    return false;
            }
        }

        return true;
    }
};