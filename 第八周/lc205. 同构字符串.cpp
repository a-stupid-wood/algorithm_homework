class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<char, char> reflects;
        unordered_map<char, bool> flags;
        for (int i = 0; i < n; i++) {
            if (reflects.count(s[i]) == 0) {
                if (flags[t[i]]) return false;
                reflects[s[i]] = t[i];
                flags[t[i]] = true;
            } else if (reflects[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};