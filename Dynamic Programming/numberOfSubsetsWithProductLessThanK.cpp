// call rec. function by passing idx=0,res=1,arr,n,k as arguments and for each call if idx == n that means there is a subset which is having product
// <=k so return 1. else , we have two choices either to take this element in the product or not if we do not take it so just call on next index
// with res as it is i.e. rec(idx+1,res) else if we want to pick it up so first check if multiplying arr[idx] with res is not exceeding k and if it
// is true then call on rec(idx+1,arr[idx]*res) else simply add 0. return the result of not pick and pick.
// also we are counting the empty subset so subtract 1 before returning final ans.


class Solution {
public:

  int rec(int idx, long res, int arr[], int n, int k) {

    if (idx == n) {
      return 1;
    }

    return rec(idx + 1, res, arr, n, k) + (arr[idx] * (1LL) * res <= k ? rec(idx + 1, arr[idx] * (1LL) * res, arr, n, k) : 0);

  }


  int numOfSubsets(int arr[], int N, int K) {


    return rec(0, (long)1, arr, N, K) - 1;


  }
};

// t.c. = O(2^N)
// s.c. = O(N)(stack space)

// recursion + memo.

// declare dp[n][k] with all -1. dp[i][k] represents no. of valid subsets we can have if we consider array from index i to n - 1 if the product
// till now is k.
// so for each call if idx==n that means we have found a valid subset so return 1, else if dp[idx][res] !=-1 means it is already computed so return
// dp[idx][res], else we have two choices either to pick this element ot not pick but we can only pick if arr[idx]*res<=k so the ans returned by
// pick and not pick we add them , store them and return it.


class Solution {
public:

  int rec(int idx, long res, int arr[], int n, int k, vector<vector<int>> &dp) {

    if (idx == n) {
      return 1;
    }

    if (dp[idx][res] != -1) return dp[idx][res];

    return dp[idx][res] = rec(idx + 1, res, arr, n, k, dp) + (arr[idx] * (1LL) * res <= k ? rec(idx + 1, arr[idx] * (1LL) * res, arr, n, k, dp) : 0);

  }


  int numOfSubsets(int arr[], int N, int K) {

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));

    return rec(0, (long)1, arr, N, K, dp) - 1;


  }
};

// t.c. = O(N*K)
// s.c. = O(N*K) + O(N)(stack space).

// iterative.
// just reverse the order of evaluation compared t recursion.


class Solution {
public:


  int numOfSubsets(int arr[], int N, int K) {

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    for (int idx = N; idx >= 0; idx--) {

      for (int res = K; res >= 1; res--) {

        if (idx == N) {
          dp[idx][res] = 1;
        } else {

          int pick = 0, notPick = 0;

          pick = dp[idx + 1][res];

          if (arr[idx] * (1LL)*res <= K) {
            notPick = dp[idx + 1][arr[idx] * (1LL) * (res)];
          }

          dp[idx][res] = pick + notPick;
        }
      }

    }

    return dp[0][1] - 1;


  }
};

// t.c. = O(N*K)
// s.c. = O(N*K)

// space optimization.


class Solution {
public:


  int numOfSubsets(int arr[], int N, int K) {

    vector<int> curr(K + 1, 0), prev(K + 1, 0);

    for (int idx = N; idx >= 0; idx--) {

      for (int res = K; res >= 1; res--) {

        if (idx == N) {
          curr[res] = 1;
        } else {

          int pick = 0, notPick = 0;

          pick = prev[res];

          if (arr[idx] * (1LL)*res <= K) {
            notPick = prev[arr[idx] * (1LL) * (res)];
          }

          curr[res] = pick + notPick;
        }
      }

      prev = curr;

    }

    return prev[1] - 1;

  }
};

// t.c. = O(N*K)
// s.c. = O(K)

