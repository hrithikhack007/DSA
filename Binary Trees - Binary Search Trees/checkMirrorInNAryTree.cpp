// declare an unordered map of int,vector<int> t1 , where key will be a node and value is vector<int> that is children of
// node.
// we will create tree 1 with edges in A, iterate from i=0 to 2*e-1 and in each iteraiton push A[i+1] in t1[A[i]] i.e.
// A[i] is the parent of A[i+1].
// now, while traversing edges of second tree, we want children of a node in tree 2 to be in reverse order that of t1 node.
// so let's say the first children of 1 is 4 in t2 so in t1 4 should be the last child of node 1, we can easily check if by
// doing t1[B[i]].back()!=B[i+1] i.e. the last child of B[i] in t1 if it is not equal to the B[i+1] i.e. first child of B[i]
// in t2 then return false, else pop the last child of B[i] from t1 as the next child of B[i] in t2 we will consider it at
// first and last in t1.
// if no mismatch found then return true.



class Solution {
public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here

        unordered_map<int, vector<int>> t1;

        for (int i = 0; i < 2 * e; i += 2) {

            t1[A[i]].push_back(A[i + 1]);
        }

        for (int i = 0; i < 2 * e; i += 2) {

            if (t1[B[i]].back() != B[i + 1]) return false;
            t1[B[i]].pop_back();
        }

        return true;

    }
};

// t.c. = O(E) = O(N)
// s.c. = O(N+E) = O(N)