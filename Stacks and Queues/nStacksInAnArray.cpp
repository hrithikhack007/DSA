// we will initialize a vector of stack of size N and set space = S.
// now in push operation if space is 0 then we cannot push the element so return false, else decrement space by 1 as we will pushing x
// in mth stack and return true.
// in pop operation, if mth stack is empty so return -1, else increment space by 1 as we are popping one element from mth stack so first
// store the top element of mth stack and pop it out then return that element.




#include<bits/stdc++.h>

class NStack
{
public:
    vector<stack<int>> multiStack;
    int space;

    // Initialize your data structure.
    NStack(int N, int S)
    {
        multiStack.resize(N);
        space = S;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (space == 0) return false;
        space--;
        multiStack[m - 1].push(x);
        return true;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (multiStack[m - 1].empty()) return -1;
        space++;
        int ele = multiStack[m - 1].top();
        multiStack[m - 1].pop();
        return ele;
    }
};

// t.c. = O(1) per operation
// s.c. = O(1) per operation. O(S + N) overall as S elements at max can be stored in total and N slots of vector while initializing.