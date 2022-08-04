// greedy/kadanes.
// set ans to -1,diff to 0.
// diff is basically the current diff between the number of zeroes and ones.
// ans will store the max of diff.
// now iterate characters of string s, in each iteration if ch is 1 then decrement diff by 1 else increment diff by 1. now maximize the ans with
// diff and check if diff is -1 if it is then set it again to 0 because now the number of 1's is more than no. of 0's in the current subtring that
// we have considered so neglect that substring because taking that will going to decrease our ans as it will give a -1 so better is to start with the
//new substring from next index.



class Solution {
public:
	int maxSubstring(string S)
	{

		int ans = -1;
		int diff = 0;

		for (auto ch : S) {

			if (ch == '1') diff--;
			else diff++;

			ans = max(ans, diff);

			if (diff == -1) diff = 0;


		}

		return ans;


	}
};

// t.c. = O(N)
// s.c. = O(1)


// dp.
// dp[i] will store the maximum difference of 0's and 1's if the substring ends at ith index.
// so first set dp[0] to 1 if s[0] is 1 else 0.
// also set ans to dp[0]. now in each iteration if s[i]=='0' then it will add 1 else it will add -1.
// so for i we have two choices , we can either continue the substring ending at i-1 or we can start a new subtring from i so we will take max of
// this two choices i.e. dp[i] = max(dp[i-1] + add, add).
// also maximize the ans with dp[i] because the optimal substring can be at any index i from 0 to n-1.

class Solution {
public:
	int maxSubstring(string S)
	{
		int n = S.size();


		vector<int> dp(n, 0);

		dp[0] = (S[0] == '0') ? 1 : -1;

		int ans = dp[0];

		for (int i = 1; i < n; i++) {

			int add = (S[i] == '1') ? -1 : 1;

			dp[i] = max(dp[i - 1] + add, add);
			ans = max(ans, dp[i]);

		}

		return ans;


	}
};

// t.c. = O(N)
// s.c. = O(N)

// space optimized.

class Solution {
public:
	int maxSubstring(string S)
	{
		int n = S.size();


		int prev = (S[0] == '0') ? 1 : -1;
		int ans = prev;

		for (int i = 1; i < n; i++) {

			int add = (S[i] == '1') ? -1 : 1;

			int curr = max(prev + add, add);
			ans = max(ans, curr);

			prev = curr;

		}

		return ans;


	}
};

// t.c. = O(N)
// s.c. = O(1)


