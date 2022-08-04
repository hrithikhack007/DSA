// declare dp[n] with all -1. call rec. by passing idx=0 as arguments and in each rec. call if idx>=nums.size()-1 that means we can reach last index
// so return 0.
// if dp[idx] != -1 that means it is already computed so return it. else, set mini to INT_MAX-1. now we have nums[idx] choices to jump from the
// the current idx so explore jumps from jump = 1 to nums[idx] and in each iteration,  call rec. by passing idx + jump i.e. move to idx + jump
// index and add 1 to jump there and now we will minimize the mini with rec(idx+jump) + 1 so from all the possible jumps from idx  we will choose that
// jump which gives the minimum jumps to reach the end index and return it.
// edge case: if nums[idx]=0  && idx != n-1 ,so we cannot reach last index from idx so we will set it to intmax - 1 because if we kept it intmax
// then let's say from some index we try to jump at idx then we have to add 1 to jump to idx i.e. 1 + dp[idx] so if dp[idx] = intmax then intmax+1
// will overflow, so we set dp[idx] to intmax-1 if we cannot reach last from idx so 1 + intmax - 1 = intmax no overflow.

class Solution {
public:

    int rec(int idx, vector<int> &nums, vector<int> &dp) {

        if (idx >= nums.size() - 1) return 0;

        if (dp[idx] != -1) return dp[idx];

        int mini = INT_MAX - 1;

        for (int jump = 1; jump <= nums[idx]; jump++) {

            mini = min(mini, rec(idx + jump, nums, dp) + 1);
        }

        return dp[idx] = mini;


    }

    int jump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n + 1, -1);


        return rec(0, nums, dp);


    }
};

// t.c. = O(N*N) = O(N^2)
// s.c. = O(N) + O(N)(stack space) = O(N)

// iterative.
// declare dp[n] with all -1. now reverse the order of evaluation as compare to recursion, i.e we called rec. from 0 so we will start idx from n-2 to
// 0 . set dp[n-1] to 0.
// loop from idx=n-2 to 0, and in each iteration set mini to intmax-1, explore the jumps from jump=1 to nums[idx], and in each jump if we can reach
// last index then set mini to 1 and break else, minimize the mini with dp[idx+jump] + 1.
// after exploring all jumps are over set dp[idx] to mini i.e. the minimum jumps required to reach end index from idx.


class Solution {
public:

    int jump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n + 1, -1);

        dp[n - 1] = 0;

        for (int idx = n - 2; idx >= 0; idx--) {

            int mini = INT_MAX - 1;

            for (int jump = 1; jump <= nums[idx]; jump++) {

                if (idx + jump >= n - 1) {
                    mini = 1;
                    break;
                }

                mini = min(mini, dp[idx + jump] + 1);
            }
            dp[idx] = mini;


        }


        return dp[0];


    }
};

// t.c. = O(N^2)
// s.c. = O(N)