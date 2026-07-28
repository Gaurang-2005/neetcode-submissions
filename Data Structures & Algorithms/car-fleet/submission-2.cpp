class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleet = 0;
        float time = -1;
        map<int, int> mapping;
        for (int i = 0; i < position.size(); i++) mapping[position[i]] = speed[i];
        for (auto it = mapping.rbegin(); it != mapping.rend(); ++it) {
            if ((target - it -> first) / float(it -> second) <= time) {
                continue;
            } 
            else {
                fleet++;
                time = (target - it -> first) / float(it -> second);
            }
        }
        return fleet;
    }
};