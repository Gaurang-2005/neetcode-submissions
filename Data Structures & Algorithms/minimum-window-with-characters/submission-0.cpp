class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        string out;
        unordered_map<char, int> targ{0};
        for (char i : t) targ[i]++;
        unordered_map<char, int> cnt{0};
        int left = 0;
        bool pres = false;
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i]]++;
            pres = true;
            for (auto j : t) {
                if (cnt[j] < targ[j]) {
                    pres = false;
                    break;
                }
            }
            if (pres) {
                if (out.length() > i - left + 1 || !out.length()) {
                    out = "";
                    out.append(s.begin() + left, s.begin() + i + 1);
                }
                while (cnt[s[left]] > targ[s[left]]) {
                    if (cnt[s[left]]) cnt[s[left]]--;
                    left++;
                    if (out.length() > i - left + 1 || !out.length()) {
                        out = "";
                        out.append(s.begin() + left, s.begin() + i + 1);
                    }
                    if (left >= i) break;
                }
            } 
        }
        return out;
    }
};
