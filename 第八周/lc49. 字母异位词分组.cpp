class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mode_words;

        for (auto word : strs) {
            string mode = word;
            sort(mode.begin(), mode.end());
            mode_words[mode].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto [mode, words] : mode_words) {
            ans.push_back(words);
        }
        return ans;
    }
};