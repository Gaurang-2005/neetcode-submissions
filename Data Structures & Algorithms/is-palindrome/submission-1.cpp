class Solution {
public:
    string small(string& s) {
        string out;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                out.push_back((s[i] - 'A') + 'a');
                continue;
            }
            if (!(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')) continue;
            out.push_back(s[i]);
        }

        return out;
    }
    bool isPalindrome(string s) {
        string flat = small(s);
        // cout << flat << endl;
        for (int i = 0; i < flat.length() / 2; i++) {
            if (flat[i] != flat[flat.length() - 1 - i]) {
                // cout << flat[i] << ' ' << flat[flat.length() - 1 - i];
                return false;
            }
        }
        return true;
    }
};
