// first take a stack of operands.
// then traverse each tokens array and for each token, if it is an operator then pop out two operands and perform the corresponding operation
// and push the res in operands.
// else push the token in the operands stack by converting it into int.
// the final result will be in the top of operands stack.

// how to check if the token is operator or not? operators are always of size 1 so if token.size() == 1 now single digit can also be of size
// 1 so if the given token is not a digit i.e. !(token[0]>='0' && token[0]<='9') then that means it is an opertor.


class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<long> operands;

        for (auto token : tokens) {

            if (token.size() == 1 && !(token[0] >= '0' && token[0] <= '9')) {

                long sec = operands.top();
                operands.pop();
                long fir = operands.top();
                operands.pop();
                long res = 0;

                if (token[0] == '+') {
                    res = fir + sec;
                } else if (token[0] == '-') {
                    res = fir - sec;
                } else if (token[0] == '*') {
                    res = fir * sec;
                } else {
                    res = fir / sec;
                }

                operands.push(res);

            } else {

                operands.push(stoi(token));

            }
        }

        return operands.top();

    }
};


// t.c. = O(N)
// s.c. = O(N)