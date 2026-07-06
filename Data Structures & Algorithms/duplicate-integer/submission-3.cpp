class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> duplicate;

        for (auto& i: nums) {
            if (duplicate[i] >= 1) return true;
            else duplicate[i]++;
        }
        return false;
    }
};