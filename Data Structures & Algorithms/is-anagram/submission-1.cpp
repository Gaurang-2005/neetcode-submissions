class Solution {
public:
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
};
