class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) {
            return ans;
        }

        unordered_map<char, int> target;
        unordered_map<char, int> cur;

        for (auto c : p) {
            target[c]++;
        }

        int left = 0, right = 0;
        int validate = 0;
        while (right < s.size()) {
            char c = s[right];
            cur[c]++;

            if (target.count(c) && cur[c] == target[c]) {
                validate++;
            }
            right++;

            while (validate ==  target.size()) {
                if (right - left == p.size()) {
                    ans.push_back(left);
                }
                cur[s[left]]--;
                if (target.count(s[left]) && target[s[left]]>cur[s[left]]) {
                    validate--;
                }
                left++;
            }
        }
        return ans;
    }
};