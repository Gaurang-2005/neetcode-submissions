class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;

        for (int i = 0; i < heights.size(); i++) {
            int min = INT_MAX;
            for (int j = i; j < heights.size(); j++) {
                if (min > heights[j]) min = heights[j];
                if (max < (j - i + 1) * min) {
                    max = (j - i + 1) * min;
                }
            }
        }
        
        return max;
    }
};
