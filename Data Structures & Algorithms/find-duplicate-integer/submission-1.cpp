class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> temp(nums.size() - 1, 0);
        for (auto& i : nums) {
            if (temp[i]) return i;
            temp[i] = true;
        }
        return 0;
    }
};
