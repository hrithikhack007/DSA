// variation of maximum sum subarray. here dp[i] represents the minimum subarray sum we can get if the subarray ends at index i.
// in transition just to minimum and rest all remains same.

class Solution {
public:
  int smallestSumSubarray(vector<int>& a) {
    //Code here
    int n = a.size();

    vector<int> dp(n);

    dp[0] = a[0];

    int mini = dp[0];

    for (int i = 1; i < n; i++) {

      dp[i] = min(dp[i - 1] + a[i], a[i]);
      mini = min(mini, dp[i]);
    }

    return mini;


  }
};

// t.c. = O(N)
// s.c. = O(N)

// space optimized.


class Solution {
public:
  int smallestSumSubarray(vector<int>& a) {
    //Code here
    int n = a.size();


    int prev = a[0];

    int mini = prev;

    for (int i = 1; i < n; i++) {

      int curr = min(prev + a[i], a[i]);
      mini = min(mini, curr);
      prev = curr;
    }

    return mini;


  }
};

// t.c. = O(N)
// s.c. = O(1)


