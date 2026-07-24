class Solution {
public:
    bool isValid(string s) {
        if (s.length()%2 == 1) return false;
        stack<char> store;

        for (auto&i : s) {
            if (i == '(' || i == '{' || i == '[') {
                store.push(i);
                continue;
            }
            if (store.empty()) return false;
            char t = store.top();
            if (t == '(' && i == ')' || t == '{' && i == '}' || t == '[' && i == ']') store.pop();
            else return false;
        }
        return store.empty();
    }
};
