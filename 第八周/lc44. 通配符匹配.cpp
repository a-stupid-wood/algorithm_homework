class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        s = " " + s;
        p = " " + p;

        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j] == '*') {
                f[0][j] = f[0][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j] == '?') {
                    f[i][j] = f[i - 1][j - 1];
                }else if (p[j] == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1];
                }else {
                    f[i][j] = f[i - 1][j - 1] && s[i] == p[j];
                }
            }
        }
        return f[n][m];
    }
};
