class Solution {
public:
    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void bfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (auto d : dir) {
                int r = d[0] + curr.first;
                int c = d[1] + curr.second;

                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c]=='1') {
                    q.push({r, c});
                    grid[r][c] = '0';
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]=='1') {
                    ans++;
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};