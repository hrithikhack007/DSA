// if n is odd then return false,
// else, declare a stack of char. iterate from i=0 to n - 1 and in each iteration, if it is a opening bracket then push it into the
// stack, else if stack is empty then there is no opening bracket on left side to pair up with the current closing bracket so return false
// else if opening bracket in top matches with the current closing bracket then we found a match so pop the opening bracket from stack
// else return false as the closing bracket is paired up with other opening bracket.
// after the for loop is over, if stack is empty then return true else false because if it is not empty then  that means some opening
// brackets couldn't match with closing brackets so it is invalid.


class Solution {
public:

    bool isOpen(char ch) {

        return (ch == '(' || ch == '{' || ch == '[');
    }

    bool match(char opening, char closing) {

        return ((opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']'));
    }

    bool isValid(string s) {


        int n = s.size();

        if ((n & 1)) return false;

        stack<char> st;

        for (int i = 0; i < n; i++) {

            if (isOpen(s[i])) {
                st.push(s[i]);
            } else {

                if (st.empty()) return false;

                if (match(st.top(), s[i])) {
                    st.pop();
                } else return false;
            }
        }

        return st.empty();

    }
};

// t.c. = O(N)
// s.c. = O(N)

// concised solution.
// if the ith character is the opening bracket then we will push the closing bracket of that type into the stack so when we encounter
// a closing bracket in the string we can simply check the top element and if it matches with the current closing bracket we can say
// that we have found a match for the currnet closing bracket. and if it is closing and stack is empty or top is not equal to current
// closing then return false.


class Solution {
public:



    bool isValid(string s) {


        int n = s.size();

        if ((n & 1)) return false;

        stack<char> st;

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop();
        }

        return st.empty();

    }
};

// t.c. = O(N)
// s.c. = O(N)