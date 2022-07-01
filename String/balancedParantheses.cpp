// using stacks. if the curr character is open bracket then we simply push it into the stack, if it is the closing bracket then we will check if
// the stack is empty if it is then this closing can't be paired up with its opening bracket we return false, if it is not empty then we will
// check the top opening bracket is matching pair with the current closing bracket, if it is then we will pop out from the stack else we return
// false because then the parantheses won't be valid. in last we will check if the stack is empty if it is not that means some opening brackets
// didn't get the matching closing brackets to paired up with so the parantheses is not balanaced else true.

class Solution {
public:

	bool validPair(char open, char close) {

		return (  open == '[' && close == ']' ) || (open == '{' && close == '}') || (open == '(' && close == ')');
	}

	bool isValid(string s) {

		stack<char> st;


		for (auto ch : s) {

			if (ch == '[' || ch == '{' || ch == '(') {
				st.push(ch);
			} else {

				if (st.empty() || !validPair(st.top(), ch)) return false;
				st.pop();

			}
		}

		return st.empty();


	}
};

// t.c. = O(N)
// s.c. = O(N)