// using recursion. for every character we have two choices either to include it in the subset or not. so we generate all possible combination
// this way. we have to manually sort the subests.

class Solution {
public:

	void rec(int idx, string &s, string &subset, vector<string> &subsets) {

		if (idx == s.size()) {
			if (subset.size() != 0) {
				subsets.push_back(subset);
			}
			return;
		}

		subset.push_back(s[idx]);
		rec(idx + 1, s, subset, subsets);
		subset.pop_back();
		rec(idx + 1, s, subset, subsets);

	}

	vector<string> AllPossibleStrings(string s) {
		// Code here

		vector<string> subsets;
		string subset = "";

		rec(0, s, subset, subsets);

		sort(subsets.begin(), subsets.end());
		return subsets;

	}
};

// t.c. = O(n*2^n)
// s.c. = O(n)

// using bits. for a given string of length n there are 2^n possible subsets possible. so here we can make use of bit to represent the
// characters present in the subset. for e.g. if s = abc then ,001 => a, 010 => b , 110 => bc and so on.
// so we will start from 1 to 2^(n)-1 because we don't want empty subset. at each iteration we will construct the string represented by the
// bit representation of current i. if 0th bit is set then that means we have to take 0th character of the string in current subset
// else we skip it , in this way we will construct and push it into the subsets array. we will sort it manually.

class Solution {
public:




	vector<string> AllPossibleStrings(string s) {

		int n = s.size();
		vector<string> subsets;


		for (int i = 1; i < (1 << n); i++) {
			string subset = "";

			for (int j = 0; j < n; j++) {
				if (((i) & (1 << j))) {
					subset.push_back(s[j]);
				}
			}

			subsets.push_back(subset);

		}

		sort(subsets.begin(), subsets.end());
		return subsets;

	}
};

// t.c. = O(n*(2^n))
// s.c. = O(1)