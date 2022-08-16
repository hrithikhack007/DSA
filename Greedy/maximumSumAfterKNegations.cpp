// sort the array a in increasing order.
// set sum to 0 and mini to inf, idx to -1.
// iterate from i=0 to n - 1 and in each iteration, if k>0 and a[i]<0 then only negate a[i] as we don't want to convert positives into negatives.
// and minimize the mini with a[i] after this.
// if after the above iteration is over, and k%2 is 1 that means we have converted all the negative numbers into positive so the remaining
// negations we will apply it on  the smallest positive number.
// after this, again iterate from i=0 to n - 1 and calculate the sum.
// k%2 means k becomes 0 or k is even so it doesn't add any effect on the sum as we will just negate the same element k times which will have no
// change.

class Solution {
public:

#define ll long long

    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a + n);

        ll sum = 0;
        ll mini = LLONG_MAX, idx = -1;

        for (int i = 0; i < n; i++) {


            if (k > 0) {
                if (a[i] < 0) {
                    a[i] = -a[i];
                    k--;
                }
            }

            if (a[i] < mini) {
                mini = a[i];
                idx = i;
            }

        }


        if (k % 2 == 1) {
            a[idx] = -a[idx];
        }

        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        return sum;
    }
};

// t.c. = O(NLogN) + O(N) + O(N) = O(NLogN)
// s.c. = O(1)