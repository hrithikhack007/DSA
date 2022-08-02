// greedy more intuitive.
// take a max-heap. push all the elements of arr in heap.
// now until the size of heap is > 1 then pop the first guy and then pop out the second guy , if the difference between the first and second is
// >= k then we cannot pair first with anyone because the remaining elements will be smaller than second so the difference is gonna be >=k only
// so for now just push the second guy back into heap and continue, else if the difference is < k then just pair up first and second i.e. add them
// in the sum.

class Solution {
public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int k)
    {

        priority_queue<int> pq;

        for (int i = 0; i < N; i++) {
            pq.push(arr[i]);
        }

        int sum = 0;

        while (pq.size() > 1) {

            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            if (first - second >= k) {
                pq.push(second);
                continue;
            }

            sum += (first + second);

        }

        return sum;

    }
};

// t.c. = O(NLogN) + O(NLogN) = O(2*N(LogN)) = O(NlogN)
// s.c. = O(N)

// using dp.
// first sort the array in increasing order.
// declare dp[n] with all 0. dp[i] represents the maximum sum we can form by forming valid pairs using first i+1 elements.
// base case: N==1, we can't form any pair so return 0. if(arr[1]-arr[0]<k) then we can pair them up so dp[1] will be arr[0] + arr[1].
// now iterate from i=2 to N-1 and for each iteration, check if arr[i]-arr[i-1]<k if it is then we can show that pairing up arr[i] and arr[i-1]
// will always be optimal so pair them and the remaining part i.e. dp[i-2] add it with arr[i]+arr[i-1] and assign it to dp[i].
// else, if arr[i] cannot pair up with arr[i-1] then it can't form with any numbers lesser than a[i-1] so just assign dp[i-1] to dp[i].

// intuition: why pairing up arr[i] and arr[i-1] if their difference is less than k is optimal because let's say arr[i] is x so we are adding
// +x in the sum and let's say by adding +x we have to remove some element <=x say y from the remaining i-2 part so (x-y)>=0 so sum won't decrease.




class Solution {
public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int k)
    {

        if (N == 1) return 0;

        sort(arr, arr + N);

        vector<int> dp(N + 1, 0);

        if (arr[1] - arr[0] < k) {
            dp[1] = arr[0] + arr[1];
        }

        for (int i = 2; i < N; i++) {

            if (arr[i] - arr[i - 1] < k) {

                dp[i] = dp[i - 2] + (arr[i] + arr[i - 1]);
            } else dp[i] = dp[i - 1];
        }

        return dp[N - 1];



    }
};

// t.c. = O(NLogN + N) = O(NLogN)
// s.c. = O(N)

// space optimized.


class Solution {
public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int k)
    {

        if (N == 1) return 0;

        sort(arr, arr + N);

        int sprev = 0, prev = (arr[1] - arr[0] < k ? arr[0] + arr[1] : 0);

        for (int i = 2; i < N; i++) {

            int curr = 0;

            if (arr[i] - arr[i - 1] < k) {

                curr = sprev + (arr[i] + arr[i - 1]);
            } else curr = prev;

            sprev = prev;
            prev = curr;
        }

        return prev;



    }
};

// t.c. = O(NLogN + N) = O(NLogN)
// s.c. = O(1)


