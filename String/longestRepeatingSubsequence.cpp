// memoization. it is similar to lcs. dp[i][j] represents maximum length of the repeating subsequence we can achieve between string starting
// from i to n-1 and another string starting from j to n-1. we will start i and j from 0. at each call we will check if s[i]==s[j] and i!=j
// because we don't want the matching character to share same index in their respective indexing. if it is true then we will add + 1
// and make a call on i+1 and j+1 part of the string. else if is false then we will try to skip ith character or jth character whichever
// call will give maximum we will return that.

class Solution {
public:

	int rec(int i, int j, string &s, int n, vector<vector<int>> &dp) {

		if (i == n || j == n) return 0;

		if (dp[i][j] != -1) return dp[i][j];

		if (s[i] == s[j] && i != j) {
			return dp[i][j] = 1 + rec(i + 1, j + 1, s, n, dp);
		} else {
			return dp[i][j] = max(rec(i + 1, j, s, n, dp), rec(i, j + 1, s, n, dp));
		}
	}

	int LongestRepeatingSubsequence(string str) {
		// Code here
		int n = str.size();

		vector<vector<int>> dp(n, vector<int>(n, -1));

		return rec(0, 0, str, n, dp);
	}

};


// t.c. = O(N*N)
// s.c. = O(N*N)


// tabulation. just handle the base cases like memo version and reverse the order of evaluation compared to memo.

class Solution {
public:



	int LongestRepeatingSubsequence(string str) {
		// Code here
		int n = str.size();

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		//  return rec(0,0,str,n,dp);


		for (int i = n - 1; i >= 0; i--) {

			for (int j = n - 1; j >= 0; j--) {

				if (str[i] == str[j] && i != j) {
					dp[i][j] = 1 + dp[i + 1][j + 1];
				} else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
				}
			}

		}

		return dp[0][0];


	}



};

// t.c. = O(N*N)
// s.c. = O(N*N)

// space optimization. we will eliminate one dimension which is just used for checking the one previous state. instead we will take two
// arrays curr and next where curr will store the current state values and after will store the values prior to the current state so
// curr can use values of after array to calculate the current state. after calculation of each curr state we will assign it to after
// array.

class Solution {
public:



	int LongestRepeatingSubsequence(string str) {
		// Code here
		int n = str.size();

		vector<int> curr(n + 1, 0);
		vector<int> after(n + 1, 0);

		//  return rec(0,0,str,n,dp);


		for (int i = n - 1; i >= 0; i--) {

			for (int j = n - 1; j >= 0; j--) {

				if (str[i] == str[j] && i != j) {
					curr[j] = 1 + after[j + 1];
				} else {
					curr[j] = max(after[j], curr[j + 1]);
				}
			}

			after = curr;

		}

		return after[0];


	}



};

// t.c. = O(N*N)
// s.c. = O(N)

