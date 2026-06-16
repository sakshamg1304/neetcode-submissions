class Solution {
public:
    vector<vector<int>> dir{{0,1},{0,-1}, {1,0}, {-1,0}};
    int bfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 0;
        int count=0;

        while(!q.empty()) {
            count++;
            auto curr = q.front();
            q.pop();

            for(auto d:dir) {
                int r = curr.first + d[0];
                int c = curr.second + d[1];

                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]) {
                    grid[r][c] = 0;
                    q.push({r,c});
                }
            }
        }
        return count;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]) {
                    ans=max(ans,bfs(i,j,grid));
                }
            } 
        }
        return ans;

    }
};