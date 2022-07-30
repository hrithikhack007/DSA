// recursion + memo.
// if sum is odd then we cannot divide array into two subsets such that they will have equal sum so in this case we simply return false.
// now we just want to find a subset whose sum equals to half of sum because then the remaining sum will be rem = sum - half i.e. half as well
// so we can then say that we can select two subsets whose sums are equal. let's call half as targetsum.
// so we will call the rec. function by passing idx=0,targetSum = sum/2,nums,n and dp as arguments and in rec. call we will check if targetSum becomes
// 0 that means we have choosen a subset whose sum is equal to targetsum so we return true else if we reach the end of array then we cannot choose
// any element and satisfy the targetsum so retur false, else if dp[idx][targetSum]!=-1 means it is already computed then we can simply return it
// else we have two choices we can either take the idxth element in the subset or not but while picking we should first check if nums[idx]<=targetSum
// if it is then we can pick it and call on rec(idx+1,targetSum-nums[idx]) and whatever it returns store it in pick or we cannot pick it so we will
// call on rec(idx+1,targetSum) and store it in notPick and if either of them returns true that means we can choose subset which sums up to targetSum
// so store  (pick||notPick) in dp[idx][targetSum] and return it.


class Solution {
public:

    bool rec(int idx, int targetSum, vector<int> &nums, int n, vector<vector<int>> &dp) {

        if (targetSum == 0) {
            return true;
        }

        if (idx == n) {
            return false;
        }

        if (dp[idx][targetSum] != -1) return dp[idx][targetSum];

        bool pick = false, notPick = false;

        if (nums[idx] <= targetSum) {

            pick = rec(idx + 1, targetSum - nums[idx], nums, n, dp);
        }

        notPick = rec(idx + 1, targetSum, nums, n, dp);

        return dp[idx][targetSum] = (pick || notPick);
    }

    bool canPartition(vector<int>& nums) {


        int sum = accumulate(nums.begin(), nums.end(), 0);

        if ((sum & 1)) return false;

        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));

        return rec(0, sum / 2, nums, nums.size(), dp);

    }
};

// t.c. = O(N*(sum/2))
// s.c. = O(N*(sum/2)) + O(N)(stack space)


// iterative.

// just reverse the order of evaluation as compared to recursion like in recursion we were calling rec. function from idx=0 and targetSum = sum/2
// so in iterative we will start idx from n to 0 and targetSum from 0 to sum/2.
// base conditions and transitions will remain exactly the same.
// ans will be in dp[0][sum/2] i.e. can we choose a subset from index 0 to n - 1 that sums up to sum/2.

class Solution {
public:
    bool canPartition(vector<int>& nums) {


        int sum = accumulate(nums.begin(), nums.end(), 0);

        if ((sum & 1)) return false;

        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1));

        for (int idx = n; idx >= 0; idx--) {

            for (int targetSum = 0; targetSum <= sum / 2; targetSum++) {

                if (targetSum == 0) {
                    dp[idx][targetSum] = true;
                } else if (idx == n) {
                    dp[idx][targetSum] = false;
                } else {

                    bool pick = false, notPick = false;

                    if (nums[idx] <= targetSum) {
                        pick = dp[idx + 1][targetSum - nums[idx]];
                    }

                    notPick = dp[idx + 1][targetSum];

                    dp[idx][targetSum] = (pick || notPick);
                }
            }
        }

        return dp[0][sum / 2];

    }
};

// t.c. = O(N*(sum/2))
// s.c. = O(N*(sum/2))

// space optimized.
// we are just checking one row behind to calculate the current state so instead of storing all rows we can just use two rows i.e. curr and prev
// curr we will build using prev row and after building curr it will act as prev for the next state so we will assign curr to prev and continue
// in this way we can remove the redundant dimension of size N. the final ans i.e dp[0][sum/2] will now be in prev[sum/2] because after calculating
// the 0th row we assign it to prev.

class Solution {
public:
    bool canPartition(vector<int>& nums) {


        int sum = accumulate(nums.begin(), nums.end(), 0);

        if ((sum & 1)) return false;

        int n = nums.size();

        vector<bool> curr(sum / 2 + 1);
        vector<bool> prev(sum / 2 + 1);

        for (int idx = n; idx >= 0; idx--) {

            for (int targetSum = 0; targetSum <= sum / 2; targetSum++) {

                if (targetSum == 0) {
                    curr[targetSum] = true;
                } else if (idx == n) {
                    curr[targetSum] = false;
                } else {

                    bool pick = false, notPick = false;

                    if (nums[idx] <= targetSum) {
                        pick = prev[targetSum - nums[idx]];
                    }

                    notPick = prev[targetSum];

                    curr[targetSum] = (pick || notPick);
                }
            }

            prev = curr;
        }

        return prev[sum / 2];

    }
};

// t.c. = O(N*(sum/2))
// s.c. = O(sum/2)