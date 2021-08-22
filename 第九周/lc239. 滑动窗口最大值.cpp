struct Number
{
    int value;
    int index;

    Number(int value,int index)
    {
        this->value = value;
        this->index = index;
    }

    bool operator<(const struct Number & right)const   //重载<运算符
    {
        return this->value > right.value;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<Number>s;
        for (int i = 0; i < k - 1; i++) s.insert(Number(nums[i], i));
        for (int i = k - 1; i < nums.size(); i++) {
            s.insert(Number(nums[i], i));
            while ((*s.begin()).index <= i - k) s.erase(s.begin());
            cout <<  endl;
            ans.push_back((*s.begin()).value);
        }
        return ans;
    }
};