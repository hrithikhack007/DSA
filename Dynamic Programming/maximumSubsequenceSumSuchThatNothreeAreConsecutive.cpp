// base cases: if n == 1 return a[0] or n == 2 return a[0] + a[1].
// declare dp[n][2]. dp[i][0] represents maximum valid subsequence sum we can get if we don't choose the ith element and dp[i][1]
// represents maximum valid subsequence sum we can get if we choose the ith element.
// set some base cases like for 1st element dp[1][1] = a[0] , for 2nd element dp[2][0] = a[0] and dp[2][1] = a[0] + a[1].
// now iterate from i=3 to n, and in each iteration, set dp[i][0] to max(dp[i-1][0],dp[i-1][1])
// now for dp[i][1] we have two choices,first of all we are choosing the ith element so we cannot choose i-1 and i-2 th element
// because then it will be 3 consecutive  elements. so first choice is to choose the i-1th element and don't choose the i-2th
// element so we will skip dp[i-2] and directly take max(dp[i-3][0],dp[i-3][1]) and add a[i-2] i.e. the value of prev element
// and next choice is to skip the prev element and take the i-2th element so we will take max(dp[i-2][0],dp[i-2][1]) and we will
// take max of both choices and add a[i-1] i.e. current element in it and assign it to dp[i][1].
// final ans will be max(dp[n][0],dp[n][1]).


int maxSum(vector<int> &a, int n)
{

    if (n == 1) {
        return a[0];
    } else if (n == 2) {
        return a[0] + a[1];
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[1][1] = a[0], dp[2][0] = a[0], dp[2][1] = a[0] + a[1];

    for (int i = 3; i <= n; i++) {

        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

        dp[i][1] = max(max(dp[i - 3][0], dp[i - 3][1]) + a[i - 2], max(dp[i - 2][0], dp[i - 2][1])) + a[i - 1];

    }

    return max(dp[n][0], dp[n][1]);
}

// t.c. = O(N)
// s.c. = O(2*N) = O(N)

// instead of taking two dimensions we can do it in one dimension by simply storing maximum valid subsequence sum we can get till ith element
// either by choosing or not choosing ith element. and in transitions, the choices will remain same so we will take notPick and Pick variables
// to store the choices value and choose maximum from them and store it in dp[i].

int maxSum(vector<int> &a, int n)
{

    if (n == 1) {
        return a[0];
    } else if (n == 2) {
        return a[0] + a[1];
    }

    vector<int> dp(n + 1, 0);

    dp[1] = a[0], dp[2] = a[0] + a[1];

    for (int i = 3; i <= n; i++) {

        int notPick = dp[i - 1];

        int pick = max(dp[i - 3] + a[i - 2], dp[i - 2]) + a[i - 1];

        dp[i] = max(notPick, pick);

    }

    return dp[n];
}

// t.c. = O(N)
// s.c. = O(N)

// space optimized.
// we were just using 3 prev states to calculate current state so instead of storing all states we can keep track of last three states and
// calculate the current state with them and after calculation of current state we can make the secondPrev as thirdPrev , prev as secondPrev
// and current as prev to calculate next state.
// final ans will be in prev.

int maxSum(vector<int> &a, int n)
{

    if (n == 1) {
        return a[0];
    } else if (n == 2) {
        return a[0] + a[1];
    }
    int prev = a[0] + a[1], sprev = a[0], tprev = 0;


    for (int i = 3; i <= n; i++) {

        int notPick = prev;

        int pick = max(tprev + a[i - 2], sprev) + a[i - 1];
        tprev = sprev;
        sprev = prev;
        prev = max(pick, notPick);

    }

    return prev;
}

// t.c. = O(N)
// s.c. = O(1)

