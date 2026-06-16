class Solution {
public:
vector<vector<int>> dir{{-1,0},{0,1},{1,0}, {0,-1}}; 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n =grid.size();
        int m = grid[0].size();
        bool isOrangePresent = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) {
                    isOrangePresent = true;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        if(!isOrangePresent && q.size()==0){
            return 0;
        }

        int time = 0;

        while(!q.empty()) {
            int sz=q.size();
            bool flag=false;
            for(int z=0;z<sz;z++) {
                auto curr=q.front();
                q.pop();

                for(auto d:dir) {
                    int xx= d[0] + curr.first;
                    int yy = d[1] + curr.second;

                    if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy]==1){
                        q.push({xx,yy});
                        flag=true;
                        grid[xx][yy]=2;
                    }
                }
            }
            if(flag)
                time++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   return -1;
                }
            }
        }
        return time;
        
    }
};