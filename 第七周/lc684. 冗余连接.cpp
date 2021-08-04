class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        fa = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }

        for (auto &edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if (find(node1) != find(node2)) {
                fa[find(node1)] = find(node2);
            }else {
                return edge;
            }
        }
        return vector<int>{};
    }

    int find(int index) {
        if (fa[index] != index) fa[index] = find(fa[index]);
        return fa[index];
    }

private:
    vector<int> fa;
};