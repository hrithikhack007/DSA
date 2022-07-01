// greedy , constructive. we will first precalculate the lastOccurence of the every character for every i. we will use two pointers l and r
// initialized to 0 and n-1 respectively. we will run loop till l<r. when s[l]==s[r] do l++,r--. when we find mismatch, we can now add
// characters in front only so we will try to match s[r] by the shifting l till we found s[l]==s[r] but we have already computed the lastOccurence
// of all chars so we will find the index of s[r] between 0 and l if it is not there then -1 will be present. if -1 is the case that means
// we are appending s[r] somewhere in front so we now have to balance all the character on lhs of l as well so we increment the count by
// l - lastOccurence(s[r]). basically to match s[r] somewhere in the left say x then we have to append l - x characters so l shifted that
// much position. after this we move l to that last occurence + 1 and decrement r by 1 as it matched.

// as r will decrement in each iteration the run time complexity of this algorithm will be O(N). s.c. = O(26*N) => O(N)

class Solution {
public:
	int minChar(string str) {
		//Write your code here

		int n = str.size();

		vector<vector<int>> prefix(n, vector<int>(26, -1));


		for (int i = 0; i < n; i++) {

			for (char ch = 'a' ; ch <= 'z' ; ch++) {

				if (i == 0 && str[i] == ch) {
					prefix[i][ch - 'a'] = i;
				} else if (i != 0) {

					prefix[i][ch - 'a'] = str[i] == ch ? i : prefix[i - 1][ch - 'a'];
				}


			}
		}


		int l = 0, r = n - 1;
		int ans = 0;

		while (l < r) {

			if (str[l] == str[r]) {
				l++; r--;
			} else {

				ans += (l - prefix[l][str[r] - 'a']);
				l = prefix[l][str[r] - 'a'] + 1;
				r--;
			}
		}

		return ans;





	}
};


// t.c. = O(26*N+N) => O(N)
// s.c. = O(26*N) => O(N)