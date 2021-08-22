class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return -1;

        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
        int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

        int ans = 0;

        while (!q.empty()) {
            ans++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == rows - 1 && y == cols - 1) return ans;

                for (int j = 0; j < 8; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};