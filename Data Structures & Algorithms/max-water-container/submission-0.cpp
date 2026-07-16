class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                if (heights[i] >= heights[j] && heights[j] * (j - i) > max) {
                    max = heights[j] * (j - i);
                }
                else if (heights[i] < heights[j] && heights[i] * (j - i) > max) {
                    max = heights[i] * (j - i);
                }
            }
        }
        return max;
    }
};
