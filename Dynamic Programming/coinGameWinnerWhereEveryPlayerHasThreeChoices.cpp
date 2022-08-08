// dp[i] represents 0 if player X wins and 1 if player Y wins this is because let's say player X wins at some n then while returning we
// should return opposite of result for x because the call would have been made by Y so if player X wins for some n then it will return
// loss indicating that player Y loses and vice-versa.

// so while returning final ans also we should return opposite result.
// now at each rec. call a player has 3 choices if n>=a then he can collect a coins and call on rec(n-a), if n>=b then he can collect
// b coins and call on rec(n-b) and can collect 1 coin by calling on rec(n-1).
// so if a player can win in any of this three choices then we can say that this player can win at a given n so we will return false indicating
// that the other player loss or true.


bool rec(int n, int a, int b, vector<int> &dp) {

    if (n == 0) return true;

    if (dp[n] != -1) return dp[n];

    bool ans1 = false, ans2 = false, ans3 = false;

    if (n >= a) {
        ans1 = rec(n - a, a, b, dp);
    }
    if (n >= b) ans2 = rec(n - b, a, b, dp);

    ans3 = rec(n - 1, a, b, dp);

    return dp[n] = !(ans1 || ans2 || ans3);

}

int coinGameWinner(int n, int a, int b)
{

    vector<int> dp(n + 1, -1);

    return !rec(n, a, b, dp);


}

// t.c. = O(N)
// s.c. = O(N) + O(N)(stack space).


// iterative. just reverse the order of evaluation as compared to recursion.

int coinGameWinner(int n, int a, int b)
{

    vector<int> dp(n + 1, -1);

    for (int i = 0; i <= n; i++) {

        if (i == 0) dp[i] = true;
        else {

            if (dp[n] != -1) return dp[n];

            bool ans1 = false, ans2 = false, ans3 = false;

            if (i >= a) {
                ans1 = dp[i - a];
            }
            if (i >= b) ans2 = dp[i - b];

            ans3 = dp[i - 1];

            dp[i] = !(ans1 || ans2 || ans3);


        }
    }

    return !dp[n];


}

// t.c. = O(N)
// s.c. = O(N)

