class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int right = nums.size() - 1;

        while (right > start) {
            int mid = start + (right - start) / 2;

            if (nums[mid] > nums[right]) start = mid + 1;
            else right = mid;
        }

        int left = 0;
        right = nums.size() - 1;

        while (right >= left) {
            int mid = left + (right - left) / 2; 
            int midAct = (mid + start >= nums.size()) ? mid + start - nums.size() : mid + start; 
            cout << midAct << std::endl << "left: " << left << std::endl << "right: " << right << std::endl;
            if (nums[midAct] == target) return midAct;

            if (nums[midAct] > target) right = mid - 1;
            else left = mid + 1;
        }

        return -1;
    }
};
