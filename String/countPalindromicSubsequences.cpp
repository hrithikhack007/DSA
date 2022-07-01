// tabulation dp. dp[i][j] represents total number of palindromic subsequences in a substring s0 to si.
// now if substring is of length 1 then dp[i][j] = 1,
// else if substring is of length 2: if both characters are equal then dp[i][j] = 3 else dp[i][j] = 2.
// else: if s[i]==s[j] then by appending these two characters in the start and end of all the palindromic subsequences between these two
// characters will again  generate palindromic subequences and + 1 for those two characters itself forming a palindromic subsequecnce with empty
// subsequence in between.

// therefore dp[i][j] = (dp[i+1][j-1] + 1)%mod.

// now number of palindromic subsequence we can get by removing jth character and number of plaindromic subequence we can get by removing
// ith character we will add that and subtract the extra count which which was considered in both the characters.
//       leaving jth character  leaving ith character   subtracting the middle part counted twice
// i.e. dp[i][j-1]       +      dp[i+1][j]         -    dp[i+1][j-1]

//  we will add the above value in dp[i][j] = (dp[i][j] + (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]) + mod)%mod.

// the answer will be stored in dp[0][n-1].

class Solution {
public:
	/*You are required to complete below method */
	long long int  countPS(string str)
	{
		//Your code here

		int n = str.size();
		long mod = 1e9 + 7;
		long dp[n][n];

		for (int g = 1; g <= n; g++) {

			for (int i = 0; i + g - 1 < n; i++) {

				int j = i + g - 1;

				dp[i][j] = 0;

				if (i == j) {
					dp[i][j] = 1;
				} else if (j - i == 1) {
					if (str[i] == str[j]) {
						dp[i][j] = 3;
					} else {
						dp[i][j] = 2;
					}
				} else {

					if (str[i] == str[j]) {
						dp[i][j] = (dp[i + 1][j - 1] + 1) % mod;
					}

					dp[i][j] = (dp[i][j] + (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]) + mod) % mod;

				}
			}
		}


		return dp[0][n - 1];

	}

};


// t.c. = O(N*N)
// s.c. = O(N*N)
