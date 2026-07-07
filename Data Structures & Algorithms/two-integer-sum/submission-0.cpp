class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out(2);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    out[0] = i;
                    out[1] = j;
                    return out;
                }
            }
        }        
    }
};
