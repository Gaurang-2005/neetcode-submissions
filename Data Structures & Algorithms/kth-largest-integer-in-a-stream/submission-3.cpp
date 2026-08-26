class KthLargest {
    vector<int> store;
    int kth = -1000;
    int kn;
public:
    KthLargest(int k, vector<int>& nums) : kn(k) {
        if (!nums.size()) return;
        store = nums;
        sort(store.begin(), store.end(), std::greater<int>());
        if (store.size() >= kn) kth = store[k - 1];
    }
    
    int add(int val) {
        store.push_back(val);
        if (val < kth) return kth;
        sort(store.begin(), store.end(), std::greater<int>());
        if (store.size() >= kn) kth = store[kn - 1];
        return kth;
    }
};
