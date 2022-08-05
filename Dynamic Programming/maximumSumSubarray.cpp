// dp[i] represent the maximum sum I can get if I end the subarray at ith index.
// set dp[0] = 0, maxi to dp[0].
// start from i = 1 to n - 1, and in each iteration we have two choices either to continue the previous subarray or start the new subarray
// from the ith index. we will choose that choice which gives maximum so dp[i] = max(dp[i-1]+arr[i],arr[i]).
// also we will maximize the maxi with dp[i] because the maximum sum subarray can end at any index i so maxi will store the final ans.



class Solution {
public:
#define ll long long
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n) {


        vector<ll> dp(n);

        dp[0] = arr[0];

        ll maxi = dp[0];

        for (int i = 1; i < n; i++) {

            dp[i] = max<ll>(dp[i - 1] + arr[i], arr[i]);
            maxi = max(maxi, dp[i]);

        }

        return maxi;




    }
};

// t.c. = O(N)
// s.c. = O(N)

// space optimized.


class Solution {
public:
#define ll long long
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n) {

        ll prev = arr[0];

        ll maxi = prev;

        for (int i = 1; i < n; i++) {

            ll curr = max<ll>(prev + arr[i], arr[i]);
            maxi = max(maxi, curr);
            prev = curr;

        }

        return maxi;




    }
};

// t.c. = O(N)
// s.c. = O(1)

// greedy.
// set sum to 0, maxsum to -inf.
// iterate from i=0 to n-1 and in each iteration, add arr[i] in sum, maximize the maxSum with sum and if sum becomes -ve then reset
// sum to 0.

// intuition: if the sum becomes -ve then there is no meaning in carrying that sum as it is going to only  decrease the sum so we
// reset sum to 0. for e.g. let's say sum becomes -5 and we still keep it then we add 10,20 in sum so sum is now 25 so if we would have
// neglect that -ve sum and start fresh from 10 we would have get 30 which is > 25.

// note:deep proof: if we found sum to be -ve then the prev subarray sum before becoming -ve would obviosuly contain some non-negative
// sum so we cannot make sum non-negative again even if we remove some elements from that subarray if we are adding the current element
// because of which sum is becoming -ve, think about it if we remove some starting portion of subarray which will be +ve then the sum is
// going to decrease further and let's say you even remove -ve elements after that but +ve sum - -ve sum was must be >=0 so even if we
// remove -ve the remaining sum will be <= 0 so if the current element can make the prev subarray sum to be -ve then it can also make any
// suffix of that subarray to be -ve because in prev subarray before -ve element the sum will always be >= to that -ve guy.


class Solution {
public:
#define ll long long
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n) {

        ll sum = 0, maxSum = LLONG_MIN;


        for (int i = 0; i < n; i++) {

            sum += arr[i];

            maxSum = max(maxSum, sum);

            if (sum < 0) sum = 0;
        }

        return maxSum;




    }
};

// t.c. = O(N)
// s.c. = O(1)
