class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> num;
        for (auto& val : nums) {
            num.push(val);
        }
        while (--k) {
            num.pop();
        }
        return num.top();
    }
};
