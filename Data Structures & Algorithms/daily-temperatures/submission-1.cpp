class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            bool pass = false;
            for (int j = i + 1; j < temperatures.size(); j++) {
                if (temperatures[i] >= temperatures[j]) result[i]++; 
                else {
                    cout<<"ran: "<<temperatures[j]<<endl;
                    result[i]++;
                    pass = true;
                    break;
                }
            }
            if (!pass) result[i] = 0;
        }
        return result;
    }
};
