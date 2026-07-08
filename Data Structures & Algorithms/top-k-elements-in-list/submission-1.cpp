class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> out;
        unordered_map<int, int> count{0};
        vector<int> temp;

        for (int i = 0; i < nums.size(); i++) {
            if (!count[nums[i]]) temp.push_back(nums[i]);
            count[nums[i]]++;
        }

        for (int i = 0; i < temp.size() && out.size() < k; i++) {
            int max = temp[i];
            for (int j = 0; j < temp.size(); j++) {
                if (count[max] < count[temp[j]]) max = temp[j];
            }
            count[max] = -1;
            out.push_back(max);
        }
        return out;
    }
};
