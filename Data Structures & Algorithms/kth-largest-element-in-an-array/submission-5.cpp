class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        while (--k) {
            nums.pop_back();
        }
        return nums.back();
    }
};
