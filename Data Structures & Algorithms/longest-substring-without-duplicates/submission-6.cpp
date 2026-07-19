class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count{0};
        int maxcnt = 0;
        int cnt = 0;
        for (int j = 0; j < s.length(); j++) {
            cnt = 0;
            count.clear();
            for (int i = j; i < s.length(); i++) {
                if (!count[s[i]]) {
                    cnt++;
                    count[s[i]]++;
                }
                else {
                    maxcnt = max(maxcnt, cnt);
                    count.clear();
                    count[s[i]]++;
                    cnt = 1;
                }
            }
            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;
    }
};
