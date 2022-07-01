// basic sum. we keep a sum variable. whenever we encounter 0 we will do sum-- else sum++, if sum becomes 0 that means we have find a
// substring which is having equal number of 0's and 1's. we will then increment count and repeat the process till r<n(r starts from 0).
// if in the end sum is not equal to 0 that means we couldn't find the suffix containing equal number of 0's and 1's so we will return -1
// else we return counter.

class Solution {
public:
	int maxSubStr(string str) {
		//Write your code here

		int r = 0, n = str.size();

		int sum = 0;
		int count = 0;

		while (r < n) {

			if (str[r] == '0') sum--;
			else sum++;

			if (sum == 0) {
				count++;
			}
			r++;

		}

		if (sum != 0) return -1;
		else return count;
	}
};


// t.c. = O(N)
// s.c. = O(1)