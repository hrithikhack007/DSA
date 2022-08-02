// recursion + memo.
// declare dp[n][k] with all -1. call rec by passing n=n,k=k,dp as arguments and in each rec. call base cases: if n == 1 then we have to check
// k floors one by one from the bottom to top floor so we return k, else if k == 0 that means there is no floor remaining to check so we cannot
// make any attempt so return 0.
// else, if dp[n][k]!=-1 return dp[n][k] as it is already computed. dp[n][k] stores the minimum attempts required in worst case to find the critical
// floor if we have n number of checks and k number of floors.
//else, we will try to drop the eggs from all the possible k floors so iterate from i=1 to k, and in each iteration we will drop the egg from ith
// floor and there are two possibilites either the egg  breaks or not breaks so if egg breaks then it will break for all the floors above the
// ith floor as well so we now need to check i - 1 floors (floors below the ith floor) with n - 1 eggs as one of the egg breaks at ith floor.
// and if the egg survives then it is sure that it will survive for all the floors below the ith floor so we need to check k - i floors(i.e. floors
// above the ith floor) with n eggs as the egg survived and whichever possibility returns maximum number of attempts we will take that because
// we don't know whether the egg will break at the ith floor or not so we would like to take the worst case that's why max(rec(n-1,i-1),rec(n,k-i))
// + 1 for the attempt at the ith floor and we will minimize the mini with this worst case.
// basically mini will be the best of worst case for k floors and n eggs. like we have let's say 5 floors and the worst cases for 5 floors are
// 6,4,3,8,7 so out of all these worst cases 3 is minimum so we will take that and it will be the ans for dp[n][k] and we will return it.



class Solution
{
public:

    int rec(int n, int k, vector<vector<int>> &dp) {

        if (n == 1) {
            return k;
        } else if (k == 0) {
            return 0;
        }

        if (dp[n][k] != -1) return dp[n][k];

        int mini = INT_MAX;


        for (int i = 1; i <= k; i++) {

            mini = min(mini, max(rec(n - 1, i - 1, dp), rec(n, k - i, dp)) + 1);

        }

        return dp[n][k] = mini;



    }

    int eggDrop(int n, int k)
    {

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return rec(n, k, dp);


    }
};

// t.c. = O(N*K*K) = O(N*(K^2))
// s.c. = O(N*K) + O(max(N,K))(stack space).


// iterative.
// just reverse the order of evaluation as compared to recursion and rest of the base cases as well as transitions remains exactly the same.


class Solution
{
public:

    int eggDrop(int n, int k)
    {

        vector<vector<int>> dp(n + 1, vector<int>(k + 1));

        for (int eggs = 1; eggs <= n; eggs++) {

            for (int floors = 0; floors <= k; floors++) {

                if (eggs == 1) {
                    dp[eggs][floors] = floors;
                } else if (floors == 0) {
                    dp[eggs][floors] = 0;
                } else {

                    int mini = INT_MAX;
                    for (int i = 1; i <= floors; i++) {

                        mini = min(mini, max(dp[eggs - 1][i - 1], dp[eggs][floors - i]) + 1);

                    }

                    dp[eggs][floors] = mini;

                }
            }
        }


        return dp[n][k];


    }
};


// t.c. = O(N*(k^2))
// s.c. = O(N*K)

// space optimized.
// we are just using prev state/row to calculate the new row so instead of taking all rows we can take two rows prev and curr in which we can
// calculate curr using prev and after calculation of curr we can make it prev for the calculation of next state/row.


class Solution
{
public:

    int eggDrop(int n, int k)
    {

        vector<int> curr(k + 1), prev(k + 1);

        for (int eggs = 1; eggs <= n; eggs++) {

            for (int floors = 0; floors <= k; floors++) {

                if (eggs == 1) {
                    curr[floors] = floors;
                } else if (floors == 0) {
                    curr[floors] = 0;
                } else {

                    int mini = INT_MAX;
                    for (int i = 1; i <= floors; i++) {

                        mini = min(mini, max(prev[i - 1], curr[floors - i]) + 1);

                    }

                    curr[floors] = mini;

                }
            }

            prev = curr;
        }


        return prev[k];


    }
};

// t.c. = O(N*(K^2))
// s.c. = O(2*K) = O(K)


