class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.length();
        unordered_map<char, int> desired{0};
        for (auto& i : s1) desired[i]++;
        for (int i = 0; i < s2.length() + 1 - windowSize; i++) {
            unordered_map<char, int> windowCnt{0};
            for (int j = i; j < i + windowSize; j++) {
                windowCnt[s2[j]]++;
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
