class Solution {
public:
    int trap(vector<int>& height) {
        int maximum = 0;
        for (int i = 0; i < height.size();) {
            if (height[i]) {
                int area = 0;
                int max2 = height[i + 1];
                int max2idx = i + 1;
                bool broke = false;
                int j = i + 1;
                for (; j < height.size(); j++) {
                    if (height[i] > height[j]) {
                        area += height[i] - height[j];
                        max2 = max(max2, height[j]);
                        if (max2 == height[j]) max2idx = j;
                    }
                    else {
                        max2 = height[j];
                        max2idx = j;
                        broke = true;
                        break;
                    }
                }
                if (!broke) {
                    if (max2idx == height.size() - 1) {                    
                        area = 0;
                        j = max2idx - 1;
                        for (; j > i; j--) {
                            if (height[i] > height[j]) {
                                area += height[max2idx] - height[j];
                            }
                            else {
                                break;
                            }
                        }
                        return maximum + area;
                    }
                    i++;
                }
                else {
                    if (max2 >= height[i]) {
                        cout << area << endl;
                        maximum += area;
                        i = j;
                    }
                    else {
                        area -= (height[i] - max2) * (j - i - 2);
                        cout << area << endl;
                        maximum += area;
                        i = j;
                    }
                }
            }
            else i++;
        }
        return maximum;
    }
};
