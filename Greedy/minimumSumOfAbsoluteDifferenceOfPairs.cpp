// sort both the array and iterate loop from i=0 to n - 1 and add absolute of a[i]-b[i] in sum.

// intuiton: e.g.  2  5  9  15
//                 5  7  8  11
// say, a and b are sorted in increasing order.

// if a[i] < b[i] then if I try to pair a[i] with b[j] where j>i then the abs(a[i]-b[j])>abs(a[i]-b[i]),
//so it is better to pair up with b[i].
// if a[i]>b[i] then the abs(a[i]-b[j]) > abs(a[i]-b[i]) where j < i, so it is better to pair up with b[i].
//same conditions can be checked for b[i].
// so we will just sort it and pair up each a[i] with b[i].


class Solution {
public:

#define ll long long

    long long findMinSum(vector<int> &A, vector<int> &B, int N) {

        ll sum = 0;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        for (int i = 0; i < N; i++) {

            sum += abs(A[i] - B[i]);
        }

        return sum;
    }
};

// t.c. = O(NLogN) + O(N) = O(NLogN)
// s.c. = O(1)
