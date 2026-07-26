class Solution {
public:
    int convert(string s) {
        cout << s << endl;
        int out = 0;
        bool neg = false;
        for (auto i : s) {
            if (i == '-') {
                neg = true;
                continue;
            }
            out *= 10;
            cout << i << ' ' << int(i - '0') << endl;
            out += int(i - '0');
        }
        if (neg) out *= -1;
        return out;
    }
    int evalRPN(vector<string>& tokens) {
        if (!tokens.size()) return 0;
        stack<int>operands;
        for (auto& i : tokens) {
            if (i[0] == '+' || i[0] == '-' && i.length() == 1|| i[0] == '*' || i[0] == '/') {
                int operandA;
                int operandB;
                operandB = operands.top();
                operands.pop();
                operandA = operands.top();
                operands.pop();
                switch (i[0]) {
                    case '+':
                        operands.push(operandA + operandB);
                        break;
                    case '-':
                        operands.push(operandA - operandB);
                        break;
                    case '*':
                        operands.push(operandA * operandB);
                        break;
                    case '/':
                        operands.push(operandA / operandB);
                        break;
                }
            }
            else operands.push(convert(i));
        }
        
        return operands.top();
    }
};
