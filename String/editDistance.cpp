// memo dp. dp[i][j] represents the minimum amount of operations required to make string s1 from i to n-1 and string s2 from j to m-1 equal.
// to calculate each state we will check, if s1[i] == s2[j] then we don't need to do any changes so we call further on i+1 and j+1
// if s[i]!=s[j] then we have three choices:  replace the ith character of s1 by jth character of s2 so both characters are now equal
// make a call on i+1,j+1 or delete the ith character from s1 but jth character still didn't find a match so we just make a call like
// i+1,j or insert jth character of s2 just before ith character in s1,this way jth character of s2 finds a match but ith character of s1
// didn't so we make a call like i,j+1, and we take the minimum from these 3 calls and add 1 to it and return it.

// base case: if we exhaust string s1 then to match remaining characters of s2 we will just insert those so we return the length remaining
// characters in s2. else if s2 rans out first then we must remove the remaining charcters of s1 to make it equal to s2 so we return the
// length of remaining characters of s1.

class Solution {
public:

	int rec(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {

		if (i == word1.size()) {
			return word2.size() - j;
		}
		if (j == word2.size()) {
			return word1.size() - i;
		}

		if (dp[i][j] != -1) return dp[i][j];

		if (word1[i] == word2[j]) {
			return dp[i][j] = rec(i + 1, j + 1, word1, word2, dp);
		} else {

			return dp[i][j] = 1 + min({rec(i + 1, j + 1, word1, word2, dp), rec(i + 1, j, word1, word2, dp), rec(i, j + 1, word1, word2, dp)});
		}
	}


	int minDistance(string word1, string word2) {

		int n = word1.size(), m = word2.size();

		vector<vector<int>> dp(n, vector<int>(m, -1));

		return rec(0, 0, word1, word2, dp);

	}
};

// t.c. = O(N*M)
// s.c. = O(N*M + O(min(N,M))(stack space))

// tabulation. just reverse the ordering of evalutation compared to memo and handle the base cases similarly.

class Solution {
public:




	int minDistance(string word1, string word2) {

		int n = word1.size(), m = word2.size();

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = n; i >= 0; i--) {
			for (int j = m; j >= 0; j--) {

				if (i == n) {
					dp[i][j] = m - j;
				}
				else if (j == m) {
					dp[i][j] = n - i;
				} else {

					if (word1[i] == word2[j]) {
						dp[i][j] = dp[i + 1][j + 1];
					} else {
						dp[i][j] = 1 + min({dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1]});
					}

				}

			}
		}

		return dp[0][0];


	}
};

// t.c. = O(N*M)
// s.c. = O(N*M)

// space optimised. we can eliminate the redundant dimension which is used to check only one state prior to the current state instead of storing
// all previous states we can store just 2 states current and after. after will store the values of prior state to calculate the curr state.
// then calculating the curr state we assign after the curr state.

class Solution {
public:




	int minDistance(string word1, string word2) {

		int n = word1.size(), m = word2.size();

		vector<int> curr(m + 1, 0);
		vector<int> after(m + 1, 0);

		for (int i = n; i >= 0; i--) {
			for (int j = m; j >= 0; j--) {

				if (i == n) {
					curr[j] = m - j;
				}
				else if (j == m) {
					curr[j] = n - i;
				} else {

					if (word1[i] == word2[j]) {
						curr[j] = after[j + 1];
					} else {
						curr[j] = 1 + min({after[j + 1], after[j], curr[j + 1]});
					}

				}

			}

			after = curr;
		}

		return after[0];


	}
};

// t.c. = O(N*M)
// s.c. = O(M)



