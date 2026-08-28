class Solution {
    struct compare {
        bool operator()(vector<int> a, vector<int> b) {
            return sqrt((a[0])*(a[0]) + (a[1])*(a[1])) > sqrt((b[0])*(b[0]) + (b[1])*(b[1]));
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> q;
        for (auto& val : points) {
            q.push(val);
        }
        vector<vector<int>> out;
        while(k--) {
            out.push_back(q.top());
            q.pop();
        }
        return out;
    }
};
