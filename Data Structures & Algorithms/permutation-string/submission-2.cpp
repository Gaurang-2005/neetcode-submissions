class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.length();
        unordered_map<char, int> desired{0};
        unordered_map<char, int> windowCnt{0};
        for (auto& i : s1) desired[i]++;
        for (int i = 0; i < s2.length() + 1 - windowSize; i++) {
            if (i == 0) { 
                for (int j = 0; j < windowSize; j++) {
                    windowCnt[s2[j]]++;
                }
            }
            else {
                windowCnt[s2[i-1]]--;
                windowCnt[s2[i + windowSize - 1]]++;
            }
            bool present = true;
            for (auto& [ch, cnt] : desired) {
                if (desired[ch] != windowCnt[ch]) present = false;
            }
            if (present) return true;
        }
        return false;
    }
};
