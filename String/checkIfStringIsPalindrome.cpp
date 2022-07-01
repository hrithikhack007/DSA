// two pointers. initialize two pointers l and r starting from 0 and n-1 respectively. in each iteration, check if s[l]==s[r] if it is
// then increment l and decrement j by 1. repeat this until i crosses j.

class Solution {
public:


	int isPalindrome(string S)
	{
		// Your code goes here

		int l = 0, r = S.size() - 1;

		while (l < r) {

			if (S[l++] != S[r--]) return 0;
		}

		return 1;
	}


};

// t.c. = O(N)
// s.c. = O(1)

