class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq{0};
        int left = 0;
        int maxcnt = 0;
        for (int i = 0; i < s.length(); i++) {
            int chng = 0;
            freq[s[i]]++;
            int maxi = 0;
            for (char j = 'A'; j < 'Z' + 1; j++) {
                chng += freq[j];
                maxi = max(maxi, freq[j]);
            }
            chng -= maxi;
            if (chng > k) {
                freq[s[left]]--;
                left++;
            }
            else maxcnt = max(maxcnt, i - left + 1);
        }
        return maxcnt;

            
    }
};
