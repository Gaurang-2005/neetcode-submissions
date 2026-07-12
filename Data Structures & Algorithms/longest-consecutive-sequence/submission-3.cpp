class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        std::map<int, int> store;
        for (auto& i : nums) store[i] = 1;
        int count = 0;
        int prev;
        bool init = false;
        int max = 1;
        for (const auto& [key, val] : store) {
            if (init && prev == key - 1) {
                count++;
                prev = key;
                if (count > max) max = count;
            }
            else {
                count = 1;
                prev = key;
                init = true;
            }
        }
        return max;
    }
};
