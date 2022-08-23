// calculate the middle of the stack.
// take a temporary stack temp, now iterate from i = 0 to mid - 2 and in each iteration push the top of s in temp and pop the top from s.
// after this loop, pop the topmost element from s which will be the middle element of stack.
// now while temp is not empty push the topmost element in s and pop from temp.



class Solution
{
public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int mid = ceil((sizeOfStack + 1) / 2.0);

        stack<int> temp;

        for (int i = 0; i < mid - 1; i++) {
            temp.push(s.top());
            s.pop();
        }

        s.pop();

        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }

    }
};

// t.c. = O(N/2) + O(N/2) = O(N)
// s.c. = O(N/2) = O(N)

// using recursion.
// we will call the rec. function by passing mid = mid,s and in rec. call we check if mid == 1 that means we have reached the middle
// guy so kindly remove it and return, else simply store the current top in the variable t and pop it out from stack and then call on
// rec by passing (mid-1,s) and after returning from the call we would've removed the middle element so kindly push the t back into the
// stack.


class Solution
{
public:

    void rec(int mid, stack<int> &s) {

        if (mid == 1) {
            s.pop();
            return;
        }

        int t = s.top();
        s.pop();
        rec(mid - 1, s);
        s.push(t);
    }

    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int mid = ceil((sizeOfStack + 1) / 2.0);

        rec(mid, s);


    }
};

// t.c. = O(N/2) = O(N)
// s.c. = O(N/2) (stack sapce)

