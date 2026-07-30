class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 0;
        for (auto& i : piles) {
            k = max(k, i);
        }
        int out = k;
        int right = k;
        int left = 0;
        while (left <= right) {
            k = left + (right - left) / 2;
            if (k == 0) break;
            int count = 0;
            int i = 0;
            for (; i < piles.size(); i++) {
                count += (piles[i] + k - 1) / k;
                if (count > h) {
                    break;
                }
            }
            if (i == piles.size()) {
                out = k;
                right = k - 1;
            }
            else {
                left = k + 1;
            }
        }
        return out;
    }
};
