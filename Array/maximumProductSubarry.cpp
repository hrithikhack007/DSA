// Brute force. check product of all subarrays and maximize the ans.

class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int n = nums.size();

		int maxi = INT_MIN;


		for (int i = 0; i < n; i++) {

			int prod = 1;

			for (int j = i; j < n; j++) {

				prod *= nums[j];
				maxi = max(maxi, prod);
			}
		}

		return maxi;


	}
};

// t.c. = O(N^2)
// s.c. = O(1)

// observation. maximum product subarray will include either one of the end points or both the end points. because if the middle subarray product is
// +ve then there will be 4 cases for corners:
// lhs  rhs
// +ve -ve then lhs will be included
// -ve +ve then rhs will be included
// +ve +ve both will be included
// -ve -ve both will be included

// same can be proved for case where middle product is -ve.

// so we will first traverse the array from left to right to and again from right to left . this is because there might be some case where we don't
// want to include lhs part of the array so we can before hand calculate the product of rhs part and use it to maximize the product. similarly
// can be said for rhs part. edge case of 0, just re-initialize the prod to 1. 0 will act as lhs and rhs of endpoints.

class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int n = nums.size();

		int maxi = INT_MIN, prod = 1;


		for (int i = 0; i < n; i++) {

			prod *= nums[i];
			maxi = max(maxi, prod);

			if (prod == 0) prod = 1;
		}

		prod = 1;

		for (int i = n - 1; i >= 0; i--) {
			prod *= nums[i];
			maxi = max(maxi, prod);
			if (prod == 0) prod = 1;
		}

		return maxi;


	}
};

// t.c. = O(N)
// s.c. = O(1)


// The idea is to traverse array from left to right keeping two variables minVal and maxVal which represents the minimum and maximum product value
// till the ith index of the array. Now, if the ith element of the array is negative that means now the values of minVal and maxVal will be swapped
// as value of maxVal will become minimum by multiplying it with a negative number. Now, compare the minVal and maxVal. The value of minVal and
// maxVal depends on the current index element or the product of the current index element and the previous minVal and maxVal respectively.


class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int n = nums.size();

		int maxProduct = nums[0], maxVal = nums[0], minVal = nums[0];

		for (int i = 1; i < n; i++) {

			if (nums[i] < 0) {
				swap(maxVal, minVal);
			}

			maxVal = max(nums[i], maxVal * nums[i]);
			minVal = min(nums[i], minVal * nums[i]);

			maxProduct = max(maxProduct, maxVal);

		}

		return maxProduct;


	}
};


// t.c = O(N)
// s.c. = O(1)
