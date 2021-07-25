//从底部往上推
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};


//从顶部往下推
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n + 1, 10001);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                dp[j + 1] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
            dp[0] = 10001;
        }
        int ans = 10001;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};