class Solution {
public:
    int missingNumber(vector<int>& nums) {
        size_t accum = 0;
        size_t accum2 = nums.size();
        accum2 = (accum2 + 1) * accum2 / 2;
        bool zero = false;
        for (int i = 0; i < nums.size(); i++) {
            accum += nums[i];
        }
        return accum2 - accum;
    }
};
