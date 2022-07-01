// brute force dp. first we will store each word of dictionary in unordered map. then we will define a dp. dp[i] states if it is possiblle to form
// segments of string s from 0 to i into words present in the dictionary. so we will traverse from i=0 to n-1 and try to calculate each state.
// for each i: edge case: if the whole string from 0 to i is present as a word in dictionary then dp[i] is true. after this we will traverse
// from j = i to 0 and try to break the string at each j and will check if the string from j to i is present as a word and dp[j-1] is true
// if it is then we can form a valid segments so dp[i] is true. (edge case which I missed that ith word can itself be a word in dict.
//  that's why we have to start from j=i instead of j=i-1).

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {


		unordered_map<string, bool> mp;

		for (auto word : wordDict) {

			mp[word] = true;
		}

		int n  = s.size();

		vector<int> dp(n);

		for (int i = 0; i < n; i++) {

			dp[i] = false;
			if (mp[s.substr(0, i + 1)]) dp[i] = true;

			for (int j = i; j > 0; j--) {

				if (dp[j - 1] && mp[s.substr(j, i - j + 1)]) dp[i] = true;
			}
		}

		return dp[n - 1];


	}
};

// t.c = O(N^3)
// s.c. = O(N) + O(M) where m is the length of the dictionary and N is the length of the string.


// optimized using sliding window. for each word of the dict. we will take a window of that word's size and slide it through the string s
// starting from l = 0 and r = size(word)-1. whenever the windnow contains the current word we will marked its presence in the present array.
// by doing this we will be able to mark all the substrings of s which is equal to one of the word in dict.
// after this the searching time will be reduced by a factor of O(N) while calculating dp states.

// if the dp[i] becomes true then we can simply continue to evaluate next step.

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {

		int n  = s.size();

		vector<vector<bool>> present(n, vector<bool>(n, false));

		for (auto word : wordDict) {

			int len = word.size();

			int l = 0, r = len - 1;

			while (r < n) {

				if (s.substr(l, len) == word) present[l][r] = true;
				r++;
				l++;
			}


		}


		vector<int> dp(n);

		for (int i = 0; i < n; i++) {

			dp[i] = present[0][i];
			if (dp[i]) continue;

			for (int j = i; j > 0; j--) {

				if (dp[j - 1] && present[j][i]) {
					dp[i] = true;
					break;
				}
			}
		}

		return dp[n - 1];


	}
};

// t.c. = O(N*M*K + O(N*N)) => N-> length of string s, M->number of words in dict. , K-> average length of words in dict.
// s.c. = O(N*N)





