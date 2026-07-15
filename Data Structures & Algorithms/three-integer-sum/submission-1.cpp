class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp(3);
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (k == i || k == j) continue;

                    if (nums[i] + nums[j] + nums[k] == 0) {
                        bool valid = true;
                        for (auto& vec : out) {
                            int x = 0;
                            while (vec[x] != nums[i] && x < 3) x++;
                            if (!(x - 3)) continue;
                            int y = 0;
                            for (; y < 3; y++) {
                                if (y == x) continue;
                                if (vec[y] == nums[j]) break;
                            }
                            if (!(y - 3)) continue;
                            int z = 0;
                            for (; z < 3; z++) {
                                if (z == x || z == y) continue;
                                if (vec[z] == nums[k]) break;
                            }
                            if (!(z - 3)) continue;
                            else {
                                valid = false;
                                // cout << nums[i] << " " << nums[j] << " " << nums[k] << "  break  " << endl;
                                break;
                            }
                        }
                        if (!valid) continue;
                        // cout << nums[i] << " " << nums[j] << " " << nums[k] << "  pass  " << endl;
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[k];
                        out.push_back(temp);
                    }
                }
            }
        }
        return out;
    }
};
