class Solution {
public:

    string encode(vector<string>& strs) {
        string out = "";
        for (auto& i : strs) {
            out += i;
            out += "~";
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> out;
        int vectI = 0;
        string word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '~') {
                out.push_back(word);
                word = "";
                continue;
            }
            word += s[i];
        }
        if (word.length() > 0) out.push_back(word);

        return out;
    }
};
