//
//  main.cpp
//  HomeWork
//
//  Created by 王凯彬 on 2021/6/20.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (carry == 0) {
                break;
            }
            int result = digits[i] + carry;
            digits[i] = result % 10;
            carry = result / 10;
        }
        while (carry > 0) {
            digits.insert(digits.begin(), carry % 10);
            carry = carry / 10;
        }
        return digits;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> digits = {1,2,3};
    Solution solution;
    vector<int> result = solution.plusOne(digits);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
    return 0;
}

