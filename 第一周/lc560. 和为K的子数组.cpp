//
//  main.cpp
//  HomeWork
//
//  Created by 王凯彬 on 2021/6/20.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int count = 0;
        map<int, int> prefixSums;
        prefixSums[0] = 1;
        int prefixSum = 0;
        for (int i = 0; i < len; i++) {
            prefixSum += nums[i];
            if (prefixSums[prefixSum - k]) {
                count += prefixSums[prefixSum - k];
            }
            if (prefixSums[prefixSum]) {
                prefixSums[prefixSum] += 1;
            }else {
                prefixSums[prefixSum] = 1;
            }
        }
        return count;
    }
};


int main(int argc, const char * argv[]) {

    Solution solution;
    vector<int>nums = {1,1,1};
    cout << solution.subarraySum(nums, 2) << endl;

    return 0;
}

