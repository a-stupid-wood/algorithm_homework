class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int len = prerequisites.size();
        vector<vector<int>> graph(numCourses); //邻接表初始化
        vector<int> ans; //可能的答案
        queue<int>safeNode; //入度为0的点
        int rudu[numCourses]; //入度统计数组

        for (int i = 0; i < numCourses; i++) {
            rudu[i] = 0;
        }

        for (int i = 0; i < len; i++) {
            rudu[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (rudu[i] == 0) {
                safeNode.push(i);
            }
        }

        while (!safeNode.empty()) {
            int tem = safeNode.front();
            for (int i = 0; i < graph[tem].size(); i++) {
                rudu[graph[tem][i]]--;
                if (rudu[graph[tem][i]] == 0) {
                    safeNode.push(graph[tem][i]);
                }
            }
            safeNode.pop();
            ans.push_back(tem);
        }

        if (ans.size() != numCourses) return {};
        return ans;
    }
};