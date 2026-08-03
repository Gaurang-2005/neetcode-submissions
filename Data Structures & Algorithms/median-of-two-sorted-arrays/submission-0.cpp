class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int med = (nums1.size() + nums2.size()) / 2 + 1;
        int i = 0;
        int j = 0;
        vector<int> out;
        while (i < nums1.size() && j < nums2.size() && i + j < med) {
            if (nums1[i] >= nums2[j]) {
                out.push_back(nums2[j]);
                j++;
            }
            else {
                out.push_back(nums1[i]);
                i++;
            }
        }
        while (j < nums2.size() && i + j < med) {
            out.push_back(nums2[j]);
            j++;
        }       
        while (i < nums1.size() && i + j < med) {
            out.push_back(nums1[i]);
            i++;
        }
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            return float(out.back() + out[out.size() - 2]) / 2;
        } 
        return out.back();
    }
};
