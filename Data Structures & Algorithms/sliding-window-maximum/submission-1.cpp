class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        vector<int> maxi;
        maxi.push_back(0);
        for (int i = 0; i < k; i++) {
            if (nums[maxi[0]] <= nums[i]) maxi[0] = i;
        }
        vector<int> out;
        out.push_back(nums[maxi[0]]);
        left++;
        for (int i = k; i < nums.size(); i++) {
            if (maxi[left - 1] != left - 1) {
                if (nums[i] < nums[maxi[left - 1]]) {
                    maxi.push_back(maxi[left - 1]);
                    out.push_back(nums[maxi[left - 1]]);
                    cout << out[left] << endl;
                }
                else {
                    maxi.push_back(i);
                    out.push_back(nums[i]);
                }
            }
            else {
                maxi.push_back(left);
                for (int j = left; j < left + k; j++) {
                    if (nums[maxi[left]] <= nums[j]) maxi[left] = j;
                }
                out.push_back(nums[maxi[left]]);
            }
            left++;
        }
        return out;
    }
};
