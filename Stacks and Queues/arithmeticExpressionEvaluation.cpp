// take two stacks, one for operands and another one for operators.
// by default push '?' in operators.
// utility functions:
// precedence of operators as follows:
//  '-','+' => 1
// '*','/' => 2
// '?' => -1
// '(' => 0

// isOperator: if character is '+' or '-' or '/' or '*' or '(' then true else false.

// calc:
// if there is only one operand then no need to calculate so return,
// else pop out the element and assign it into sec and again pop out and assign it to fir.
// now pop out the operator. after this perform the necessary operation and store the result into res.
// push the res in operands.


// in main function:

// loop from i=0 to n - 1, and for each i check if it is a operator, if it is then if it is a opening bracket then simply push it into the operators
// stack and continue, else while the precedence of the top operator is >= current operator then perform calculation as the operation with
// higher precedence should perform first.
// then push the opertor into the operators stack.

// else if the current character is a digit then it should be in operand, but first we have to form the number as it can have more than one digit.
// so set num to 0 and set j = i , now while j<n and expression[j] is a digit then keep forming the number and when the loop ends we have a operand
// so push it into the operands stack and jump i to j-1.

// else it is a closing bracket, so while we don't encounter the opening bracket till then perform the calculation.
// after this, pop out the opening bracket.

// after the parsing of expression is done then the topmost element in the operands stack will be the expression value.



#include <bits/stdc++.h>

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(');
}

int precedence(char ch) {

    if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '(') return 0;
    else return -1;
}

void calc(stack<int> &operands, stack<char> &operators) {

    if (operands.size() == 1) return;
    int sec = operands.top();
    operands.pop();
    int fir = operands.top();
    operands.pop();

    char op = operators.top();
    operators.pop();
    int res = 0;

    if (op == '+') res = fir + sec;
    else if (op == '-') res = fir - sec;
    else if (op == '*') res = fir * sec;
    else res = fir / sec;

    operands.push(res);
}

int evaluateArithmeticExpression(string &expression)
{

    stack<int> operands;
    stack<char> operators;

    operators.push('?');
    int n = expression.size();

    for (int i = 0; i < n; i++) {
        char ch = expression[i];

        if (isOperator(ch)) {
            if (ch == '(') {
                operators.push(ch);
                continue;
            }

            while (precedence(operators.top()) >= precedence(ch)) {
                calc(operands, operators);
            }


            operators.push(ch);

        } else if (ch >= '0' && ch <= '9') {
            int j = i;
            int num = 0;
            while (j < n && expression[j] >= '0' && expression[j] <= '9') {
                num = (num * 10 + (expression[j] - '0'));
                j++;
            }
            operands.push(num);
            i = j - 1;
        } else {

            while (operators.top() != '(') {

                calc(operands, operators);
            }

            operators.pop();
        }

    }

    return operands.top();

}

// t.c. = O(N)
// s.c. = O(N) or O(1) confusion?