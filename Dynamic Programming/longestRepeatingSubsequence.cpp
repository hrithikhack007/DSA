// recursion + memo.
// call rec. by passing i=0,j=0,str and dp as arguments, in each rec. call if i==n || j==n return 0.
// basically i will keep track of index of sequence A and j will keep track of index of sequence B. our goal is to form longest repeating subseqence
// i.e. sequence A and B should be same and as long as possible and if one character in origina str is used by both the sequence then the index
// of that character in their individual string should be different for e.g. let's say sequence A and sequence B both are using a character 'a' of
// index 3 in the original str and the index of this 'a' in sequence A and B should be different i.e. if sequence A used this in index 3 then sequence
// B cannot use this at 3rd index it should be different than 3. By keeping this condition in mind we have to calculate ans.
// if dp[i][j] != -1 return dp[i][i], else if str[i] == str[j] and i!=j then only we can consider this ith character in both sequence so we will
// call on rec(i+1,j+1) and add 1 as ith and jth character matches i.e. 1 + rec(i+1,j+1), store it and return it.
// else, keep we have two choices, keep i as it is and call on rec(i,j+1) or keep j as it is and call on rec(i+1,j) and whichever returns maximum store
// in and return.


// intuition: why we are checking i!=j and making sure that the character will appearing in the same index of sequence A and B, ok let's say we have
// found 2 matches and in sequence A and B two characters are there and we incremented i or j by some value until they found a match let's say they
// matched by i == j so now in both sequence we have two characters already and if we took the current matched character then the current character
// will be used in both sequence and that too for the same index i.e. 2nd and 0th and 1st is already done. that is why we should check i!=j.



class Solution {
public:

	int rec(int i, int j, string &str, vector<vector<int>> &dp) {

		if (i == str.size() || j == str.size()) {

			return 0;

		}

		if (dp[i][j] != -1) return dp[i][j];

		if (str[i] == str[j] && i != j) {
			return dp[i][j] = 1 + rec(i + 1, j + 1, str, dp);
		} else {

			return dp[i][j] = max(rec(i, j + 1, str, dp), rec(i + 1, j, str, dp));
		}
	}

	int LongestRepeatingSubsequence(string str) {

		int n = str.size();

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

		return rec(0, 0, str, dp);



	}

};

// t.c. = O(N*N)
// s.c. = O(N*N) + O(N)(stack space).


// iterative.
// reverse the order of evaluation as compared to recursion i.e. we were calling i and j from 0 so now in iterative we will start i  and j from
// n to 0 . and rest of the base conditions and transition will remain exactly the same. the final ans will be in dp[0][0].
// dp[i][j] stores the longest repeating subsequence in string str from 0 to i such that we have considered first i+1 characters of str in sequence
// A and first j+1 characters in sequence B. so final ans will be dp[0][0].

class Solution {
public:

	int LongestRepeatingSubsequence(string str) {

		int n = str.size();

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		for (int i = n; i >= 0; i--) {

			for (int j = n; j >= 0; j--) {

				if (i == n || j == n) {
					dp[i][j] = 0;
				} else {

					if (str[i] == str[j] && i != j) {
						dp[i][j] = 1 + dp[i + 1][j + 1];
					} else {
						dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
					}
				}
			}
		}

		return dp[0][0];

	}

};

// t.c. = O(N*N)
// s.c. = O(N*N)

// space optimized.
// we were just requiring prev state to calculate the current state so instead of storing all the rows we can just keep two rows i.e. curr and prev
// so we will use prev to calculate the curr and after calculation of curr we can simply use it as a new prev for next state so we assig curr to prev
// ans is dp[0][0] os after calculating the 0th row it will be assign to prev so ans will be prev[0].


class Solution {
public:

	int LongestRepeatingSubsequence(string str) {

		int n = str.size();



		vector<int> curr(n + 1, 0), prev(n + 1, 0);

		for (int i = n; i >= 0; i--) {

			for (int j = n; j >= 0; j--) {

				if (i == n || j == n) {
					curr[j] = 0;
				} else {

					if (str[i] == str[j] && i != j) {
						curr[j] = 1 + prev[j + 1];
					} else {
						curr[j] = max(prev[j], curr[j + 1]);
					}
				}
			}

			prev = curr;
		}

		return prev[0];


	}

};

// t.c. = O(N*N)
// s.c. = O(N)
