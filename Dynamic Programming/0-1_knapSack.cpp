// recursion + memo.
// we will call the rec. function by passing idx=0,W=W,val,wt,n,dp as arguments.
// dp[idx][W] stores the maximum value that we can have by choosing a subset of items optimally from idx to n-1 having capacity W .
// in each rec. call, if idx==n that means there are no items remaining to choose so we return 0.
// if dp[idx][W] != -1 then it is already calculated so we return dp[idx][W]
// else, set pick = 0, notpick = 0. but if wt[idx] is > W then we cannot put the current item in the bag so we will not pick it else if wt[idx]
// <= W then we can pick it and call rec on idx+1,W-wt[idx] because we took this item so capacity reduced by the weight of this item and the value
// this rec. will return in that add val[idx] because we are choosing this item so its value we have to consider.
// basically pick will store the maximum value we can get if we pick this item.
// we can skip this item as well so we will call on idx+1,W capacity will remain same as we are not putting this item in bag and so we don't val[idx]
// as well. basically nonpick will store the maximum value we can get if we don't pick this item.
// then we store max of pick,nonpick in dp[idx][W] and return it.

class Solution
{
public:

    int rec(int idx, int W, int val[], int wt[], int n, vector<vector<int>> &dp) {

        if (idx == n) {
            return 0;
        }

        if (dp[idx][W] != -1) return dp[idx][W];

        int pick = 0, notPick = 0;

        if (wt[idx] <= W) {
            pick = rec(idx + 1, W - wt[idx], val, wt, n, dp) + val[idx];
        }

        notPick = rec(idx + 1, W, val, wt, n, dp);

        return dp[idx][W] = max(pick, notPick);


    }

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {


        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        return rec(0, W, val, wt, n, dp);


    }
};

// t.c. = O(N*W)
// s.c. = O(N*W) + O(N)(stack space)

// iterative.
// declare a 2d dp array of size n+1,w+1 and initialized it to 0.
// just reverse the order of evalutaion as compared to recursion, like we were calling rec. from idx=0,W=W so now we will start from
// idx = n to 0 and w = 0 to W. and base cases will be similar, like whenever idx==n we will put dp[idx][w] = 0.
// else , we will set pick and notpick to 0 and check if wt[idx]<=w then pick it and recurrence will be same as recursion i.e. dp[idx+1][w-wt[idx]]
// +val[idx] and if we choose to notpick then dp[idx+1][w] and we will store max of pick,notpick in dp[idx][w].
// ans will be stored in dp[0][W]



class Solution
{
public:

    int knapSack(int W, int wt[], int val[], int n)
    {


        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int idx = n; idx >= 0; idx--) {

            for (int w = 0; w <= W; w++) {

                if (idx == n) {
                    dp[idx][w] = 0;
                } else {

                    int pick = 0, notPick = 0;

                    if (wt[idx] <= w) {
                        pick = dp[idx + 1][w - wt[idx]] + val[idx];
                    }

                    notPick = dp[idx + 1][w];

                    dp[idx][w] = max(pick, notPick);

                }
            }
        }

        return dp[0][W];


    }
};

// t.c. = O(N*W)
// s.c. = O(N*W)

// space optimisation.
// so in the iterative method we can see that for calculating the current state we just need the previous state so keeping all the redundant
// states before prev doesn't contribute anything to ans.
// so what we will do is we will take a curr and prev vector of size w+1 initialized to 0 curr will store the curr state using previously
// calculated state prev.
// everything else remains same , if we are doing dp[idx] it will change to curr and for dp[idx+1] it will change to prev.
// now after calculating curr we will make the curr as new prev for calculating next state.
// the last after calculation i.e. dp[0] will be store in prev so will return prev[w].


class Solution
{

public:
    int knapSack(int W, int wt[], int val[], int n)
    {


        vector<int> curr(W + 1, 0);
        vector<int> prev(W + 1, 0);

        for (int idx = n; idx >= 0; idx--) {

            for (int w = 0; w <= W; w++) {

                if (idx == n) {
                    curr[w] = 0;
                } else {

                    int pick = 0, notPick = 0;

                    if (wt[idx] <= w) {
                        pick = prev[w - wt[idx]] + val[idx];
                    }

                    notPick = prev[w];

                    curr[w] = max(pick, notPick);

                }
            }

            prev = curr;
        }

        return prev[W];


    }
};

// t.c. = O(N*W)
// s.c. = O(W)

