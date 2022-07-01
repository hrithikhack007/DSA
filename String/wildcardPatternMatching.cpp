// memo dp. dp[i][j] represents if we can match the pattern starting from i to n-1 with wildcard starting from j to m-1. now to evalate
// each state , if p[i] == w[j] or w[j]=='?' that means we can match the ith character of p with jth character of j by simply replacing
// '?' with p[i] or if it is already equal and can call on i+1,j+1.
// if w[j]=='*' so we have three choices: match '*'  with just s[i] and call on i+1,j+1
//                                        don't match s[i] with '*' i.e. replace * with empty so we call on i,j+1.
//                                         we can match multiple characters ahead including s[i] with '*' so call i+1,j
// if the above two conditions are not true then simply return false.

// base/edge cases. if i==n && j==m that means we have matched all characters of s and w so return true.
// if i==n and w[j]=='*' so we will try to replace it with empty sequence and call on i,j+1 else we return false.
// if j==m that means remaining characters of s can't be matched so we return false.

class Solution {
public:

	bool rec(int i, int j, string &wild, string &pattern, int m, int n, vector<vector<int>> &dp) {


		if (i == n && j == m) {
			return true;

		}

		if (dp[i][j] != -1) return dp[i][j];

		if (i == n) {
			if (wild[j] == '*') {
				return dp[i][j] = rec(i, j + 1, wild, pattern, m, n, dp);
			} else {
				return dp[i][j] = false;
			}
		}

		if (j == m) {
			return dp[i][j] = false;
		}


		if (wild[j] == pattern[i] || wild[j] == '?') {
			return dp[i][j] = rec(i + 1, j + 1, wild, pattern, m, n, dp);
		}

		if (wild[j] == '*') {
			return dp[i][j] = (rec(i + 1, j + 1, wild, pattern, m, n, dp) ||
			                   rec(i + 1, j, wild, pattern, m, n, dp) ||
			                   rec(i, j + 1, wild, pattern, m, n, dp));
		}

		return dp[i][j] = false;
	}

	bool isMatch(string s, string p) {

		int n = s.size(), m = p.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

		return rec(0, 0, p, s, m, n, dp);

	}
};


// t.c. = O(N*M)
// s.c. = O(N*M) + O(M)(stack space)

// tabulation dp. just reverse the evaluation order and handle base cases similarly.

class Solution
{
public:

	bool isMatch(string s, string p)
	{

		int n = s.size(), m = p.size();
		vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));

		for (int i = n; i >= 0; i--)
		{

			for (int j = m; j >= 0; j--)
			{

				if (i == n && j == m)
				{
					dp[i][j] = true;
				}
				else if (i == n)
				{

					if (p[j] == '*')
					{
						dp[i][j] = dp[i][j + 1];
					}
					else
					{
						dp[i][j] = false;
					}
				}
				else if (j == m)
				{
					dp[i][j] = false;
				}
				else
				{

					if (p[j] == s[i] || p[j] == '?')
					{
						dp[i][j] = dp[i + 1][j + 1];
					}
					else if (p[j] == '*')
					{
						dp[i][j] = dp[i + 1][j + 1] || dp[i][j + 1] || dp[i + 1][j];
					}
					else
					{
						dp[i][j] = false;
					}
				}
			}
		}

		return dp[0][0];

	}
};


// t.c. = O(N*M)
// s.c. = O(N*M)


// space optimisation. eliminate thre redundant space which is storing all the after states but we need just 1 state after curr state
// to evaluate curr state so we will use two arr curr and after in which curr stores the current state and after stores one state
// after the curr state. after calculating curr state we will assign it to after so we can calculate next state with this curr value.

class Solution
{
public:

	bool isMatch(string s, string p)
	{

		int n = s.size(), m = p.size();
		vector<int> curr(m + 1, 0);
		vector<int> after(m + 1, 0);

		for (int i = n; i >= 0; i--)
		{

			for (int j = m; j >= 0; j--)
			{

				if (i == n && j == m)
				{
					curr[j] = true;
				}
				else if (i == n)
				{

					if (p[j] == '*')
					{
						curr[j] = curr[j + 1];
					}
					else
					{
						curr[j] = false;
					}
				}
				else if (j == m)
				{
					curr[j] = false;
				}
				else
				{

					if (p[j] == s[i] || p[j] == '?')
					{
						curr[j] = after[j + 1];
					}
					else if (p[j] == '*')
					{
						curr[j] = after[j + 1] || curr[j + 1] || after[j];
					}
					else
					{
						curr[j] = false;
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