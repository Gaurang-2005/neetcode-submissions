class MinStack {
    vector<int> store;
    int pos = -1;
    int min = 0;
    int origin = -1;
public:
    MinStack() {}
    
    void push(int val) {
        pos++;
        if (pos + 1 > store.size()) store.push_back(val);
        else store[pos] = val;
        if (val < store[min]) min = pos;
    }
    
    void pop() {
        if (pos == -1) return;
        pos--;
    }
    
    int top() {
        if (pos == -1) throw invalid_argument("empty!");
        return store[pos];
    }
    
    int getMin() {
        if (pos == -1) throw invalid_argument("empty!");
        if (min > pos) {
            min = 0;
            for (int i = 1; i <= pos; i++) {
                if (store[min] > store[i]) min = i;
            }
        }

        return store[min];
    }
};
