class Solution {
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> first{0};
        unordered_map<char, int> second{0};
        for (int i = 0; i < s.length(); i++) {
            first[s[i]]++;
            second[t[i]]++;
        }
        cout << first.size() << endl;
        cout << second.size();
        if (first.size() != second.size()) return false;

        for (char& i : s) {
            if (first[i] != second[i]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> out;
        vector<bool> check(strs.size());
        int i = 0;

        while (i < strs.size()) {
            if (check[i]) {
                i++;
                continue;
            }
            vector<string> words;

            words.push_back(strs[i]);
            check[i] = 1;

            for (int j = i + 1; j < strs.size(); j++) {
                if (check[j]) continue;
                if (isAnagram(strs[i], strs[j])) {
                    words.push_back(strs[j]);
                    check[j] = 1;
                }
            }
            out.push_back(words);
        }
        return out;
    }
};
