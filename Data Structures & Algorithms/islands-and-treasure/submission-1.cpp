class Solution {
public:
    vector<vector<int>> dir {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

       
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            for(auto &x:dir) {
                int xx = curr.first + x[0];
                int yy = curr.second + x[1];

                if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy]==2147483647){
                    q.push({xx,yy});
                    grid[xx][yy] = grid[curr.first][curr.second] + 1;
                   
                }
            }
        }


    }
};
