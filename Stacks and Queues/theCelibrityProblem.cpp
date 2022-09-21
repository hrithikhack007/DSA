// simulation.
// we will assume that 0th person is the vip, then start traversing from i=1 to n-1 and for each i we will check if vip knows the ith person
// or the ith person doesn't know vip then the assumed vip is not the real vip so we will vip to ith person.
// after finishing the first loop, we will have a predicted vip so now we will cross check if this is the real vip or not so again start traversing
// from i=0 to n - 1 and for each i check if it is not vip and if the ith person doesn't knows vip or the vip knows the ith person then return -1
// that is the assumed vip was wrong and there is no vip.
// after finishing the second loop, we are sure that the assumed vip is indeed the vip so return it.


class Solution
{
public:
    int celebrity(vector<vector<int> >& M, int n)
    {

        int vip = 0;

        for (int i = 1; i < n; i++) {

            if (M[vip][i] == 1 || M[i][vip] == 0) {
                vip = i;
            }
        }

        for (int i = 0; i < n; i++) {

            if (i != vip && (M[i][vip] == 0 || M[vip][i] == 1)) {
                return -1;
            }
        }

        return vip;


    }
};


// t.c. = O(N)
// s.c. = O(1)
