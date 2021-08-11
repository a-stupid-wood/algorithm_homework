class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m != n) {
            return false;
        }

        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for (auto c : s) {
            s_map[c]++;
        }

        for (auto c : t) {
            t_map[c]++;
        }

        for (auto [c, count] : s_map) {
            if (t_map[c] != count) {
                return false;
            }
        }

        return true;
    }
};