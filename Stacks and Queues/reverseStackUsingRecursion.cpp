// In reverseStack function:
// if stack size is 0 then simply return,
// else, take the top of stack and store it in val and pop out it from stack and call reverseStack to reverse the remaining bottom part
// after the remaining bottom part is reverse we need to insert the current val at the bottom of that reversed stack so create a function
// insertAtBottom and pass stack and val in it.

// In insertAtBottom function:
// if st.size() is 0 then we need to push the val in the bottom so push the val in stack now and return.
// else, take the top of stack and store it in t and pop it out from stack then call the insertAtBottom again after returning from it we
// would have successfully inserted the value at the bottom so push the t again on the top.




#include<bits/stdc++.h>

void insertAtBottom(stack<int> &st, int val) {

    if (st.size() == 0) {
        st.push(val);
        return;
    }
    int t = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(t);
}

void reverseStack(stack<int> &stack) {

    if (stack.size() == 0) {
        return;
    }
    int val = stack.top();
    stack.pop();
    reverseStack(stack);

    insertAtBottom(stack, val);

}

// t.c. = O(N^2)
// s.c. = O(N) (recursive stack space).