class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 1, right = 500 * weights.size();
        int ans = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(weights, days, mid)) {
                right = mid - 1;
                ans = mid;
            }else {
                left = mid + 1;
            }
        }
        return ans;
    }

    bool check(vector<int> &weights, int days, int limit) {
        int cnt = 1, cur = 0;
        for (auto &weight : weights) {
            if (limit < weight) return false;
            if (cur + weight > limit) {
                cnt++;
                cur = 0;
            }
            cur += weight;
        }
        return cnt <= days;
    }
};