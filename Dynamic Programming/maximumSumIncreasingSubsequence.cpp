// declare a dp[n] with all 0. dp[i] stores the maximum sum we can get if the increasing subsequence is ending at the ith index.
// set maxi to 0. for each i from 0 to n - 1, set dp[i] to arr[i] and then iterate from j = i - 1 to 0 and for each iteration if arr[j]<arr[i]
// then we can add arr[i] after arr[j] in the subsequence as we want strictly increaising subsequence and if arr[j]<arr[i] then maximize dp[i]
// with dp[j] + arr[i] i.e. maximum sum we can get if increasing subsequence ends at jth index and if we add ith element after it so that's why
// dp[j] + arr[i].
// after the inner loop ends then dp[i] would have been computed so maximize the maxi with dp[i]. as the maximum sum increasing subsequence will end
// at some ith index so the ans will be stored in maxi.

class Solution {


public:
	int maxSumIS(int arr[], int n)
	{

		vector<int> dp(n + 1, 0);

		int maxi = 0;

		for (int i = 0; i < n; i++) {

			dp[i] = arr[i];

			for (int j = i - 1; j >= 0; j--) {

				if (arr[j] < arr[i]) {
					dp[i] = max(dp[i], dp[j] + arr[i]);
				}
			}

			maxi = max(maxi, dp[i]);
		}


		return maxi;

	}
};

// t.c. = O(N*N)
// s.c. = O(N)
