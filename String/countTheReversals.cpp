// using stack. first we will traverse the string  from left to right, if we find '{' we will simply push it into the stack. else if we find '}'
// then if the stack is empty that means no opening bracket can now paired up with this current closing bracket irrespective of what we find in
// the rhs, so we must reverse this closing bracket to opening bracket , we will do that and increment the counter, push this new opening
// bracket into the stack.else if stack is not empty we paired the current closing with the top opening bracket and popped it from stack.

// after doing the above process if the stack is empty that means all brackets were paired up we can simply return count.
// else some opening brackets would have been remain unpaired so we will now traverse from right to left.
// in each iteration, we will check if the current bracket is closing we simply push it into the stack,  else if it is the opening bracket
// and stack is empty that means there is no closing bracket on right side to paired up with it and no matter what we find on lhs it will
// still remain upaired so we must reverse this opening bracket to closing one we will do that and increment the counter and push it into the
// stack, else if stack is not empty then the closing paired is found and we pop out the top closing bracket.

// even after performing both the operations, stack is still not empty that means we can't balance the string we return -1 else we return
// count.

int countRev (string s)
{
	// your code here

	stack<char> st;

	int count = 0, n = s.size();

	for (int i = 0; i < n; i++) {

		if (s[i] == '{') {

			st.push(s[i]);

		} else {

			if (st.empty()) {
				count++;
				s[i] = '{';
				st.push(s[i]);
			} else {
				st.pop();
			}
		}


	}

	if (st.empty()) return count;

	while (!st.empty()) st.pop();

	for (int i = n - 1; i >= 0; i--) {

		if (s[i] == '}') st.push(s[i]);
		else {

			if (st.empty()) {
				count++;
				s[i] = '}';
				st.push(s[i]);
			} else {
				st.pop();
			}
		}



	}

	if (st.empty()) return count;
	return -1;

}

// t.c. = O(N)
// s.c. = O(N)


// without stack. as we know that there will only be one type of opening and closing brackets so instead of using stack we can maintain
// a counter say op to keep track of unmatched opening brackets similarly cl to keep track of unmatched closing brackets. while traversing
// from left to right we will increment op if we encounter the opening bracket and if we encounter closing bracket and op is 0 that means
// there is no opening bracket to paired up with this closing bracket so we will reverse it, increment the counter, and also increment the
// op else if op is not 0 then we decrement op.

// if in the end op is 0 we return count else now we traverse from right to left. when we encounter closing bracket we will increment the cl
// by 1 else if we encounter opening bracket and cl is 0 then we can't match this opening bracket with any closing bracket, so we reverse it
// , increment the counter ans also increment cl, else if cl is not 0 then we decrement cl.

// in  the end if cl is 0 then we return count else we return -1.

int countRev (string s)
{
	// your code here



	int count = 0, n = s.size();
	int op = 0, cl = 0 ;

	for (int i = 0; i < n; i++) {

		if (s[i] == '{') {

			op++;

		} else {

			if (!op) {
				count++;
				s[i] = '{';
				op++;
			} else {
				op--;
			}
		}


	}

	if (!op) return count;



	for (int i = n - 1; i >= 0; i--) {

		if (s[i] == '}') cl++;
		else {

			if (!cl) {
				count++;
				s[i] = '}';
				cl++;
			} else {
				cl--;
			}
		}



	}

	if (!cl) return count;
	return -1;

}


// t.c. = O(N)
// s.c. = O(1)

// optimized by eliminating second loop. after performing traversal from left to right and reversing unpaired closing brackets to opening
// brackets there will be only umpaired opening brackets will be remaining. if op == 0, that means all oepning brackers have been paired up.
// if op is > 0 that means there is some unpaired opening brackets remaining, so in this we have two cases if op is even or odd.
// if op is even then we can simply reverse op/2 brackets to closing brackets to paired up with remaining op/2 opening brackets. and
// simply return op/2 + count. but if op is odd then we can't make a balance parantheses anyway so return -1.

int countRev (string s)
{
	// your code here



	int count = 0, n = s.size();
	int op = 0, cl = 0 ;

	for (int i = 0; i < n; i++) {

		if (s[i] == '{') {

			op++;

		} else {

			if (!op) {
				count++;
				s[i] = '{';
				op++;
			} else {
				op--;
			}
		}


	}

	if ((op & 1)) return -1;
	else return (count + (op / 2));

}


// t.c. = O(N)
// s.c. = O(1)

