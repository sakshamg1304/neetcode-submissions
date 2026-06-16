class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();  
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,false));
        for (int i = 0; i <m; i++)
        {
            if (board[0][i] == 'O')
            {
                q.push({0,i});
                vis[0][i]=true;
            }

            if (board[n-1][i] == 'O')
            {
                q.push({n-1,i});
                vis[n-1][i]=true;
            }
        }

        for (int i = 1; i < n-1; i++)
        {
            if (board[i][0] == 'O')
            {
                q.push({i,0});
                vis[i][0]=true;
            }
            if (board[i][m-1] == 'O')
            {
                q.push({i,m-1});
                vis[i][m-1]=true;
            }
        }

        vector<vector<int>> dir {{0,1}, {1,0}, {-1,0}, {0,-1}};
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            for(auto d:dir) {
                int xx = cur.first + d[0];
                int yy = cur.second + d[1];

                if(xx>=0 && xx<n && yy>=0 && yy<m && board[xx][yy]=='O' && !vis[xx][yy]) {
                    q.push({xx,yy});
                    vis[xx][yy]=true;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};