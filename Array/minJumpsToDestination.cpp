// dp. dp[i] => minimum jumps require to reach ith position from starting. for each i we will try to  minimize the jumps by checking all
// minimum jumps of prior positions.


class Solution {
public:
	int jump(vector<int>& nums) {

		int n = nums.size();

		vector<int> dp(n);

		dp[0] = 0;

		for (int i = 1; i < n; i++) {

			dp[i] = INT_MAX;

			for (int j = i - 1; j >= 0; j--) {

				if (j + nums[j] >= i)
					dp[i] = min(dp[i], dp[j] + 1);
			}

		}

		return dp[n - 1];

	}
};


// t.c = O(N^2)
// s.c. = O(N)


// greedy.  we will begin from the starting position. now we will see the maximum index we can cover in 1 jump from start say ml(maximum limit)
// then we can cover every index from s+1 to ml in 1 jump. in next iteration we will explore that range and calculate the maximum index we can
// reach in th 2nd jump and then again explore the updated range for 3rd,4th and so on till the ml becomes >=n-1 that means in this jump
// we can reach the last index else ml didn't increase that means we can't reach end.

class Solution {
public:
	int minJumps(int arr[], int n) {
		// Your code here


		if (n == 1) return 0;

		int e = 0, s = 0, jumps = 0;


		while (1) {

			int ml = e;

			while (s <= e) { // exploring the current range
				ml = max(ml, s + arr[s]); // maximizing the limit of the current jump
				s++;
			}


			if (ml >= n - 1) { // can reach end in this jump
				return jumps + 1;
			} else if (ml <= e) { // cannot increase the limit
				return -1;
			} else {
				s = e + 1; // update the starting
				e = ml; // and ending point of the new range
				jumps++; //jump to next range
			}


		}
	}
};


// t.c. = O(N)
// s.c. = O(1)