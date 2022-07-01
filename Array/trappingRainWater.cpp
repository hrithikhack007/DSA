// brute force. the amount of water i can contain on the ith block depeneds on the maximum height block on its lhs and its rhs. i.e. the
// the level of water we can store on the ith block is the minimum level of max on its rhs and lhs i.e. min(maxLeft,maxRight). if the ith
// block is greater than either  two of them then it can store 0 blocks of water. so for each i we will calculate max height on its lhs
// and max height on its rhs. from that we will calculate the amount of water we can contained on that ith block.

class Solution {

	// Function to find the trapped water between the blocks.
public:
	long long trappingWater(int arr[], int n) {
		// code here


		long long trappedWater = 0;

		for (int i = 0; i < n - 1; i++) {

			int maxLeft = 0, maxRight = 0, curr = arr[i];

			for (int j = i - 1; j >= 0; j--) {
				maxLeft = max(maxLeft, arr[j]);
			}

			for (int j = i + 1; j < n; j++) {
				maxRight = max(maxRight, arr[j]);
			}


			trappedWater += max(min(maxLeft, maxRight) - curr, 0);

		}

		return trappedWater;

	}
};

// t.c. = O(N^2)
// s.c. = O(1)


// dp. we can pre-calculate the prefix and suffix array. in prefix, for every it will store the maximum height from 0 to i and in suffix for
// every i it will store maximum from i to n-1. we will traverse from 0 to n-1, where we will calculate maxLeft and maxRight using prefix
// suffix in constant time. then will use that to calculate the contained water in that ith block.

class Solution {

	// Function to find the trapped water between the blocks.
public:
	long long trappingWater(int arr[], int n) {
		// code here


		long long trappedWater = 0;


		int prefix[n], suffix[n];
		prefix[0] = arr[0], suffix[n - 1] = arr[n - 1];

		for (int i = 1; i < n; i++) {
			prefix[i] = max(prefix[i - 1], arr[i]);
		}

		for (int i = n - 2; i >= 0; i--) {
			suffix[i] = max(suffix[i + 1], arr[i]);
		}

		for (int i = 1; i < n - 1; i++) {

			int maxLeft = prefix[i - 1], maxRight = suffix[i + 1], curr = arr[i];


			trappedWater += max(min(maxLeft, maxRight) - curr, 0);

		}

		return trappedWater;

	}
};

// t.c. = O(N)
// s.c. = O(N)


// using two pointers. we will initialize two pointers one starting from index 0 and another one starting from n-1.
// we will also keep  lh and rh which will keep track of maximum height on left and maximum height on right respectively.
// we will check if height[l]<height[r] that means there is some block present on its rhs which is >= ith height. so we will calculate
// the amount of water it can contain like c += max(min(height[r]-lh)-height[l],0) then we will maximize lh with height[l] and increment it
// by one. we are not using rh here because l and r are moving in increasing order that means if height[l] < height[r] means pointer r is
// pointing on the maximum height from r to n-1 but height[l] might be < lh as it is incrementing to find height > r. similarly we will do if
// height[r] < height[l] , we will first calculate the amount of water rth block can conatin like c += (max(min(height[l],rh)-curr,0)) and
// maximize the rh with height[r] and decrement the r pointer by 1. repeat the above steps until l<r.

class Solution {

	// Function to find the trapped water between the blocks.
public:
	long long trappingWater(int arr[], int n) {
		// code here


		long long trappedWater = 0;


		int l = 0, r = n - 1, lh = 0, rh = 0;

		while (l < r) {

			if (arr[l] < arr[r]) {

				trappedWater += max(min(lh, arr[r]) - arr[l], 0);
				lh = max(lh, arr[l]);
				l++;
			} else {

				trappedWater += max(min(arr[l], rh) - arr[r], 0);
				rh = max(rh, arr[r]);
				r--;
			}
		}

		return trappedWater;

	}
};

// t.c. = O(N)
// s.c. = O(1)
