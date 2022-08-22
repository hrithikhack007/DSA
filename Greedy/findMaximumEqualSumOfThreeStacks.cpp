// first take the sum of stack1,stack2 and stack3 in sum1,sum2 and sum3.
// then set i=0,j=0,k=0.
// now iterate till the sum1,sum2 and sum3 are not equal.
// in each iteration, pop out element from that stack whose sum is maximum because popping out element from smaller stack is going to
// reduce the sum more and won't become equal to greater sum but doing the former can reduce the greater sum which can become equal to
// smaller sum so subtract the top element from the maximum sum and increment the respective index.


class Solution {
public:
    int maxEqualSum(int N1, int N2, int N3, vector<int> &s1, vector<int> &s2, vector<int> &s3) {


        int sum1 = accumulate(s1.begin(), s1.end(), 0);
        int sum2 = accumulate(s2.begin(), s2.end(), 0);
        int sum3 = accumulate(s3.begin(), s3.end(), 0);

        int i = 0, j = 0, k = 0;

        while (!((sum1 == sum2) && (sum2 == sum3))) {

            if (sum1 >= sum2 && sum1 >= sum3) {

                sum1 -= s1[i++];
            } else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= s2[j++];
            } else {
                sum3 -= s3[k++];
            }

        }

        return sum1;



    }
};

// t.c. = O(3*N) = O(N)
// s.c. = O(1)