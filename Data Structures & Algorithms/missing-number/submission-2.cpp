class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int accum = 0;
        for (int i = 0; i < nums.size(); i++) {
            accum = accum ^ i ^ nums[i];
        }
        return accum ^ nums.size();
    }
};
