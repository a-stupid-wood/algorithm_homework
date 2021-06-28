class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max_fre = 0;
        for (auto& num : nums) {
            mp[num]++;
            max_fre = max(max_fre, mp[num]);
        }
        mp.erase(mp.begin(), mp.end());
        int ans = nums.size();
        int left = 0, right = 0;
        while (right < nums.size()) {
            mp[nums[right]]++;
            while(mp[nums[right]] == max_fre) {
                ans = min(ans, right - left + 1);
                mp[nums[left++]]--;
            }
            right++;
        }
        return ans;
    }
};
