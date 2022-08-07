// dp[i][0] represents the longest alternating subsequence ending at ith index such that ith element was > than previous element in the
// subsequence like 2->5, 5->10 .
// dp[i][1] represents the longest alternating subsequence ending at ith index such that ith element was < than previous element in the
// subsequence like 5->2,10->5.
// so set maxi to 0, and start the loop from i=0 to n - 1 and in each iteration set dp[i][0] and dp[i][1] to 1.
// now for each i iterate from j=i-1 to 0 and in each iteration check if nums[j]>nums[i] if it is then we can append the ith element after
// nums[j] to form a subsequence of type 1 so maximize dp[i][1] with dp[j][0] + 1. dp[j][0] because we are forming the type 1 subsequence at
// ith index then we should consider the type 0 subsequence at the jth index to keep the subsequence alternating.
// similarly, if nums[j]<nums[i] then we want to form subsequence of type 0 at the ith index by appending it after jth element so we have to
// consider type 1 subsequence at jth element and maximize dp[i][0] with dp[j][1] + 1.
// after the innter loop ends we will maximize the maxi with max of dp[i][0],dp[i][1] because the longest alternating subsequence can be of
// type 0 or type 1 so we will take max of it and that subsequence can end at any index i so maxi will store the final ans.


class Solution {
public:
	int AlternatingaMaxLength(vector<int>&nums) {

		int n = nums.size();

		vector<vector<int>> dp(n + 1, vector<int>(2));
		int maxi = 0;

		for (int i = 0; i < n; i++) {

			dp[i][0] = dp[i][1] = 1;

			for (int j = i - 1; j >= 0; j--) {

				if (nums[j] > nums[i]) {
					dp[i][1] = max(dp[i][1], dp[j][0] + 1);
				} else if (nums[j] < nums[i]) {
					dp[i][0] = max(dp[i][0], dp[j][1] + 1);
				}

			}

			maxi = max({maxi, dp[i][0], dp[i][1]});

		}

		return maxi;

	}

};

// t.c. = O(N*N) = O(N^2)
// s.c. = O(2*N) = O(N)

// optimized.
// dp[i][0] represents longest alternating subsequence I can form in the subarray of 0,i where last element will be > than the previous element
// in the subsequence.
// dp[i][1] represents longest alternating subsequence I can form in the subarray of 0,i where last element will be < than the previous element
// in the subsequence.
// note: here we are not specifically want to end the sequence at ith index we want the longest in the whole subarray till i and the subsequence
// may or may not be ending at ith index.
// for e.g. 1,4,2,10,9,9,10,6 here dp[5][0] will be 4 because the longest alternating subsequence of type 0 in subarray 0,5 is 1,4,2,10 even
// though it is not ending at 5th index. similarly we can store of type 1 subsequence.
// set dp[0][0] and dp[0][1] to 1.
// iterate from i=1 to n - 1, and in each iteration, check if nums[i] > nums[i-1] if it is then we will form a type 0 subsequence at ith index
// so we have to check type 1 subsequence at index i-1 i.e. the las in subarray 0,i-1 such that last element was < than its previous element
// so we will set dp[i][0] = dp[i-1][1] + 1. and set dp[i][1] to dp[i-1][1] because we cannot form type 1 subsequence at ith index so take
// the prev maximum of type 1 at ith index.
// similarly if nums[i]<nums[i-1] then just do similar transitions like the first case,
// and edge case: if nums[i]==nums[i-1] then we cannot make both type 0 and type 1 subsequence at the ith index so set dp[i][1] to its
// previous maximum i.e. dp[i-1][1] and also dp[i][0] = dp[i-1][0].
// final ans will be max of dp[n-1][1],dp[n-1][0].

class Solution {
public:
	int AlternatingaMaxLength(vector<int>&nums) {

		int n = nums.size();

		vector<vector<int>> dp(n + 1, vector<int>(2));

		dp[0][0] = dp[0][1] = 1;


		for (int i = 1; i < n; i++) {


			if (nums[i] > nums[i - 1]) {

				dp[i][0] = dp[i - 1][1] + 1;
				dp[i][1] = dp[i - 1][1];
			} else if (nums[i] < nums[i - 1]) {
				dp[i][1] = dp[i - 1][0] + 1;
				dp[i][0] = dp[i - 1][0];
			} else {

				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][1];
			}

		}

		return max(dp[n - 1][1], dp[n - 1][0]);

	}

};

// t.c. = O(N)
// s.c. = O(2*N) = O(N)

// space optimized.

class Solution {
public:
	int AlternatingaMaxLength(vector<int>&nums) {

		int n = nums.size();

		int t0 = 1, t1 = 1;


		for (int i = 1; i < n; i++) {


			if (nums[i] > nums[i - 1]) {

				t0 = t1 + 1;
			} else if (nums[i] < nums[i - 1]) {
				t1 = t0 + 1;
			}

		}

		return max(t0, t1);

	}

};

// t.c. = O(N)
// s.c. = O(1)


