class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mood;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mood[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mood.find(key) == mood.end() || !mood.at(key).size()) return "";
        int left = 0;
        int right = mood.at(key).size() - 1;
        int ans = left;
        bool up = false;
        while (left <= right) {
            auto mid = left + (right - left) / 2;

            if (mood.at(key)[mid].first == timestamp) return mood.at(key)[mid].second;

            if (mood.at(key)[mid].first < timestamp) {
                ans = mid;
                up = true;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return up?mood.at(key)[ans].second:"";
    }
};
