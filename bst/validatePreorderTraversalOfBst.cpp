// take a stack of int and push inf in it i.e. a imaginary node from which we took left turn and reached root.
// take root as the first element of arr.
// set idx to 1, curr = root,par = -inf.
// par is the imaginary node from which we took right and reached root.
// now while idx < N, in each iteration, if arr[idx] < curr then we have two choices if arr[idx] < par that means arr[idx] cannot be attached to
// left of curr as it will result into having a node on the right subtree of par which is less than it so we return false.
// else if arr[idx] > par then we can simply attach it to the left of curr so we will push curr in the stack indicating that it is now the node
// from which we took left turn and set curr to arr[idx] and increment idx by 1.
// else if arr[idx] > curr then while arr[idx] > st.top() so we cannot attach arr[idx] to curr->right as it will result into having a node on the
// left subtree of st.top() which is > than it so we will move curr to st.top() and pop  it, until arr[idx] becomes < st.top().
// after this we will be attaching arr[idx] to right of curr so the par will be now curr so set par to curr as we are taking right turn from curr.
// also set curr to arr[idx] and increment idx by 1.
// after the while loop is over then return true.

class Solution {
public:
    int canRepresentBST(int arr[], int N) {


        stack<int> st;

        st.push(INT_MAX);

        int root = arr[0];
        int idx = 1;
        int curr = root, par = INT_MIN;

        while (idx < N) {

            if (arr[idx] < curr) {

                if (arr[idx] < par) return false;
                st.push(curr);
                curr = arr[idx++];

            } else {

                while (arr[idx] > st.top()) {
                    curr = st.top();
                    st.pop();
                }

                par = curr;
                curr = arr[idx++];
            }
        }

        return true;



    }
};

// t.c. = O(2*N) = O(N)
// s.c. = O(N)
