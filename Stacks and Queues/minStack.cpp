// declare a main stack st and aux stack, a mini to store minimum element.
// set mini to INT_MAX.
// while pushing, if the new value is <= minimum then save the current minimum in auxillary stack aux and update mini to this
// val and push val to st.
// while popping, if st.top() == mini that means we are going to pop out the currne minimum so restore the previous minimum
// from auxillary stack aux and update minimum to aux.top() and pop it out.
// pop from st.
// for top return st.top()
// for getmin return mini;

// edge case: duplicate minimum elements, so if let's say new val is < min say prev mini was 5 and new val is 3 so we
// save 5 in aux and updated mini to 3 now let's we inserted 2 more times and we saw that it is already equal to mini so
// we didn't update the mini nor store the current mini in aux but let's say now we want to remove top i.e. 3 so st.top()==3
// so we resore prev mini i.e. 5 from aux and update mini to 5 but there were 2 more mini present in st so 5 is not the minimum.
// so we can see it fails in duplicate conditions if we update mini only when new val is > mini instead we should update the
// mini even when new val is equal to mini so after pushing multiple mini elements and while popping out one of them we restore
// the minimum element only instead of prev mini and when all the instance of mini element is removed from stack then only
// it will restore the prev mini and update the mini to prev mini.

class MinStack
{
public:

    stack<int> st, aux;
    int mini;

    MinStack()
    {

        mini = INT_MAX;
    }

    void push(int val)
    {

        if (val <= mini)
        {
            aux.push(mini);
            mini = val;
        }
        st.push(val);
    }

    void pop()
    {

        if (st.top() == mini)
        {
            mini = aux.top();
            aux.pop();
        }

        st.pop();
    }

    int top()
    {

        return st.top();
    }

    int getMin()
    {

        return mini;
    }
};

// t.c. = O(1) for all operations
// s.c. = O(N) auxillary stack.


// space optimized solution.
// declare a stack and a mini variable.
// set mini to INT_MAX
// take long mini. to avoid overflows.
// while pushing, push the difference between the value and the current mini, if st.top() is <= 0 i.e. the new val is less
// than or equal to current mini, so update mini to val.
// while popping out, check if st.top()<= mini if it is then that means the top element is current minium because when we
// pushed into stack we would have subtracted prev minimum from it that's why it becomes <=0 for e.g. if current mini was 5
// and new val was 3 then while pushing we would have pushed 3 - 5 = -2 so that's why if top is <=0 it is current mini and we
// have to first restore the prev mini with the differnece  of current and prev mini i.e. on top and current mini so
// prev mini = current mini + top(diff) = current mini - (-diff) because top is <=0. e.g. 3 - (-2) = 3 + 2 = 5.
// so after this we will simply pop from stack.
// for top, if we st.top()<=0 then it is current mini else if top is >0 then add mini to it and return. as we have saved
// val - mini while pushing so to restore the val just add mini in it so it will be val - mini + mini = val and return it.
// in getmin, simply return mini.


class MinStack
{
public:

    stack<long> st;
    long mini;

    MinStack()
    {

        mini = INT_MAX;
    }

    void push(int val)
    {
        st.push(val - mini);

        if (st.top() <= 0) mini = val;


    }

    void pop()
    {

        if (st.top() <= 0) mini = (mini - st.top());

        st.pop();

    }

    int top()
    {

        if (st.top() <= 0) {
            return mini;
        }
        return st.top() + mini;
    }

    int getMin()
    {

        return mini;
    }
};

// t.c. = O(1) for all operations
// s.c. = O(1)