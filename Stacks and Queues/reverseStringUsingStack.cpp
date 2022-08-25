// declare a stack st, traverse from i = 0 to len - 1 and in each iteration push the ith character in stack. after this, set i to 0,
// and while stack is not empty set s[i] to st.top() increment i by 1 and pop the top elenent.


char* reverse(char *S, int len)
{

    stack<char> st;

    for (int i = 0; i < len; i++) {
        st.push(S[i]);
    }

    int i = 0;

    while (!st.empty()) {
        S[i++] = st.top();
        st.pop();
    }

    return S;

}

// t.c. = O(N) + O(N) = O(N)
// s.c. = O(N)

