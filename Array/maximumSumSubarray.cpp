// brute force. calculate sum of all subarrays and return the maximum.

class Solution {
public:
	int maxSubArray(vector<int>& nums) {



		int maxi = INT_MIN, n = nums.size();

		for (int i = 0; i < n; i++) { // starting point of the subarray
			int sum = 0;
			for (int j = i; j < n; j++) { // exploring all possible subarrays from the choosen starting point
				sum += nums[j]; // calculate sum of each subarray

				maxi = max(maxi, sum); //maximize the ans
			}

		}

		return maxi;



	}
};


// t.c. = O(N^2)
// s.c. = O(1)

// dp. dp[i] => maximum sum we can get if the subarray ends at ith index. so at every i we will choose whether to continue the previous
// subarray or start new here depending on which gives maximum. and will maximize the result at each i.

class Solution {
public:
	int maxSubArray(vector<int>& nums) {


		int n = nums.size();
		int dp[n];
		int maxi = dp[0] = nums[0];

		for (int i = 1; i < n; i++) {

			dp[i] = max(nums[i], nums[i] + dp[i - 1]);
			maxi = max(maxi, dp[i]);

		}

		return maxi;



	}
};

// t.c. = O(N)
// s.c. = O(N)


// kadane's algorithm. initialize sum with 0. at each i add current element to sum maximize the result with it. if sum becomes negative
// then reinitialize sum to 0 because there is no meaning taking this -ve sum as it will only decrease the subarray sum of the upcoming
// subarrays.

class Solution {
public:
	int maxSubArray(vector<int>& nums) {


		int n = nums.size();
		int maxi = INT_MIN, sum = 0;

		for (int i = 0; i < n; i++) {

			sum += nums[i];
			maxi = max(maxi, sum);
			if (sum <= 0) sum = 0;

		}

		return maxi;



	}
};


// t.c. = O(N)
// s.c. = O(1)

