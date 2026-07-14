class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> out(2);
        for (int i = 0; i < numbers.size(); i++) {
            out[0] = i + 1;
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[j] == numbers[i]) continue;
                if (numbers[j] + numbers[i] == target) {
                    out[1] = j + 1;
                    return out;
                }
            }
        }
    }
};
