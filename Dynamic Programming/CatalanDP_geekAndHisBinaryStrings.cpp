// visualize binary string as opening and closing brackets, so we have to find number of ways to form valid parantheses where number of closing
// brackets should never exceed opening brackets.
// for calculating nth state what we can do is try to fix the opening and closing pair and we just have to decide in how many ways we can put
// valid brackets inside those fixed pairs and how many we can put outside the fixed pairs so the length of the string is 2*n.
// for e.g. if we have n = 3 then, we have to form 3*2 = 6 length valid parantheses.
// so let's fix a pair of opening and closing bracket () now we remain with 6 - 2 = 4 brackets so we can put all the 4 brackets inside the fixed
// pair and put 0 brackets outside of it like (4) but 4 brackets mean we are talking about n = 2  so in how many ways we can form 2*2 length valid
// string and valid ways to form 2*0 length string i.e. (dp[2])*dp[0] so this is one of the choices we have, and another choice is to put
// 2 brackets inside and 2 brackets outside i.e. (dp[1])*dp[1] and another choice is (dp[0])*dp[2] i.e. put 0 brackets inside and 4 brackets outside
// i.e. dp[2] so dp[3] = dp[0]*dp[2] + dp[1]*dp[1] + dp[2]*dp[0]
// so dp[n] = dp[0]*dp[n-1] + dp[1]*dp[n-2] + dp[2]*dp[n-3] + ..... + dp[n-2]*dp[1] + dp[n-1]*dp[0]


class Solution {

public:

#define ll long long
	ll mod = (ll)(1e9 + 7);

	int prefixStrings(int N)
	{

		vector<int> dp(N + 1);

		dp[0] = dp[1] = 1;

		for (int i = 2; i <= N; i++) {

			dp[i] = 0;

			for (int j = 0; j <= N - 1; j++) {

				dp[i] = (dp[i] % mod + ((dp[j] % mod) * (dp[i - j - 1] % mod))) % mod % mod;
			}
		}

		return dp[N];


	}

};

// /t.c. = O(N*N) = O(n^2)
// s.c. = O(N)