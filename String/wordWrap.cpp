// dynamic programming tabulation. dp[i] represents minimum cost to arrange the words from 0 to i.
// crux of the problem is mcm. basicallt , we want to find the optimal partition where each partition represents the line.
// we will initialize dp[0] as (k-a[i])^2 , preLength as a[0]. where preLength will keep track of the length of the words with space
// encountered till i-1th index.

// for every i , case 1: this word lies in the single line seprated from previous i-1 words. so dp[i] = sq(k-a[i]))+dp[i-1]
// if i==n-1 then there will be no extra space so we just need the cost to arrange previous i-1 words i.e. dp[i] = dp[i-1]
// prelength += a[i] + 1 (add current word length with space)
// case 2: previous i-1 words and ith words lies in the same line if prelength <= k then dp[i] = min(dp[i],sq(k-preLength))
// if i==n-1 then return 0 as all words can come in one line then first line itself will be the last line and no extra spaces.
// after this try to extend the partition from j = i-1 to 1. keep a currLength initialized to a[i], for every j add that words length
// i.e. currLength += a[j]. now we are keeping last n-j words in one line j-1 previous words in separate lines ,so we will do
// dp[i] = min(d[i],dp[j-1] + sq(k-currLength)) if i==n-1 then j to n-1 words come in last line so no extra space therefor, dp[i] =
// min(dp[i],dp[j-1])

// in last the ans will be in dp[n-1]. edge case if n == 1, return 0

class Solution {
public:

	int sq(int a) {
		return a * a;
	}
	int solveWordWrap(vector<int>nums, int k)
	{

		int n = nums.size();

		if (n == 1) return 0;

		int dp[n];

		dp[0] = sq(k - nums[0]);

		int preLength = nums[0];

		for (int i = 1; i < n; i++) {

			dp[i] = ((i == n - 1) ? 0 : sq(k - nums[i])) + dp[i - 1];
			preLength += nums[i] + 1;

			if (preLength <= k) {
				if (i == n - 1) return 0;
				dp[i] = min(dp[i], sq(k - (preLength)));
			}


			int currLength = nums[i];


			for (int j = i - 1; j >= 1; j--) {

				currLength += nums[j] + 1;

				if (currLength <= k) {
					if (i == n - 1)
						dp[i] = min(dp[i], dp[j - 1]);
					else
						dp[i] = min(dp[i], sq(k - currLength) + dp[j - 1]);
				} else break;
			}


		}

		return dp[n - 1];


	}
};

// t.c. = O(N^2)
// s.c. = O(N)