class UnionSet {
public:
    UnionSet(int _n): n(_n) {
        fa = vector<int>(_n, 0);
        for (int i = 0; i < _n; i++) fa[i] = i;
    }

    int find(int index) {
        if (fa[index] != index) fa[index] = find(fa[index]);
        return fa[index];
    }

    void merge(int index1, int index2) {
        int fa1 = find(index1);
        int fa2 = find(index2);
        if (fa1 == fa2) return;
        fa[fa1] = fa2;
        n--;
    }

    bool isConnected(int index1, int index2) {
        return fa[index1] == fa[index2];
    }

    int size() {
        return n;
    }

private:
    vector<int> fa;
    int n;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m > 0 ? grid[0].size() : 0;
        if (m == 0 || n == 0) return 0;

        vector<int> cnt(2, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cnt[grid[i][j] - '0']++;
            }
        }
        UnionSet us(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                for(int k = 0; k < 4; k++) {
                    int xx = i + dx[k], yy = j + dy[k];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                    if (grid[xx][yy] == '1') us.merge(i * n + j, xx * n + yy);
                }
            }
        }
        return us.size() - cnt[0];
    }

private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
};