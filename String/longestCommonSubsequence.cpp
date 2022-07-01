// memo dp. we will pass i and j initialized to 0. at every state we will check if s[i]==s[j] if it is then we found 1 matching instance
// so we will add 1 and will evaluate lcs of string s1 and s2 from i+1 to n-1 and j+1 to m-1 respectively, else we will try to skip
// either ith character or jth character and whichever give the maximum length of common subsequence we will return that.

// base case: if i exceeds length of string s1 or j exceeds length of string s2 then lcs will be 0 so we return 0.

class Solution {
public:

	int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

		if (i == s.size() || j == t.size()) return 0;

		if (dp[i][j] != -1) return dp[i][j];

		if (s[i] == t[j]) {
			return dp[i][j] = 1 + rec(i + 1, j + 1, s, t, dp);
		} else {

			return dp[i][j] = max(rec(i + 1, j, s, t, dp), rec(i, j + 1, s, t, dp));
		}

	}

	int longestCommonSubsequence(string text1, string text2) {

		vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

		return rec(0, 0, text1, text2, dp);

	}
};

// t.c. = O(N*M)
// s.c. = O(N*M + max(N,M))

// tabulation. just reverse the order of evaluation and handle base case similarly.

class Solution {
public:



	int longestCommonSubsequence(string text1, string text2) {

		int n = text1.size(), m = text2.size();

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {

				if (text1[i] == text2[j]) {
					dp[i][j] = 1 + dp[i + 1][j + 1];
				} else {
					dp[i][j]  = max(dp[i + 1][j], dp[i][j + 1]);
				}

			}
		}

		return dp[0][0];

	}
};

// t.c. = O(N*M)
// s.c. = O(N*M)


// space optimized. we will eliminate the redudant dimension which is used to store the already calculated values but we just
// need values only one state prior of current so we will keep two arrays curr and after where curr will calculate the curr
// state values and after would store the already calculate values of just one state ahead of current and use this values
// to evaluate current after calculation of curr we will assign this curr to after so now the next state can be evaluated with this
// curr values.

class Solution {
public:



	int longestCommonSubsequence(string text1, string text2) {

		int n = text1.size(), m = text2.size();

		vector<int> curr(m + 1, 0);
		vector<int> after(m + 1, 0);

		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {

				if (text1[i] == text2[j]) {
					curr[j] = 1 + after[j + 1];
				} else {
					curr[j]  = max(after[j], curr[j + 1]);
				}

			}
			after = curr;
		}

		return after[0];

	}
};

// t.c. = O(N*M)
// s.c. = O(M)