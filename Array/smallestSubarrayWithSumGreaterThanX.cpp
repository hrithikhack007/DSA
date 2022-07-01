// brute force. generate all subarrays and check.
class Solution {
public:

	int smallestSubWithSum(int arr[], int n, int x)
	{
		// Your code goes here

		int minLength = n;

		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = i; j < n; j++) {

				sum += arr[j];

				if (sum > x) {
					minLength = min(minLength, j - i + 1);
					break;
				}
			}
		}

		return minLength;

	}
};

// t.c. = O(N^2)
// s.c. = O(1)


// using sliding window and two pointers. we will keep two pointers initially both pointing on 0th index. we will keep a sum variable which will
// store the current window's sum. if sum > x then we will try to minimize the length of the window as long as the sum of the window is still > x
//. so if sum > x then we will keep removing leftmost element of window from sum until l<=r && sum>x and keep mimizing the length. do r++
// after every iteration.

class Solution {
public:

	int smallestSubWithSum(int arr[], int n, int x)
	{
		// Your code goes here

		int minLength = n;
		int sum = 0;

		int l = 0, r = 0;

		while (r < n) {

			sum += arr[r];

			if (sum > x) {

				while (l <= r && sum > x) {
					minLength = min(minLength, r - l + 1);
					sum -= arr[l];
					l++;
				}

			}

			r++;

		}

		return minLength;

	}
};

// t.c. = O(N)
// s.c. = O(1)


// using binary search. we first define a range of size of valid subarray i.e. l=1,r=n. we will try to find is there any subarray of size k which
// can give sum > x, if there is one then we will try to minimize the length of that subarray and decrease h to k-1(because if mid size subarray
// cam achieve x then >mid can as well so we will neglect the right half). if not then we will try to increase the size of the subarray and set
// l to mid + 1(because mid size subarray can't achieve x then neither can subarrays of size < mid). In this way we will reach the optimal size
// subarray which will have sum > x. we will return that. for determining if a subarray of size k can have sum > x we will use sliding window
// of size k and maintain the sum by adding rth element and removing lth element from the sum of window of size k.

class Solution {
public:

	bool bs(int k, int x, int nums[], int n)
	{

		int l = 0, r = 0, sum = 0;

		for (int i = 0; i < n; i++)
		{

			sum += nums[r];
			if (r - l + 1 > k)
			{
				sum -= nums[r - k];
				l++;
			}

			r++;

			if (sum > x) {
				return true;
			}
		}

		return false;
	}

	int smallestSubWithSum(int arr[], int n, int x)
	{
		// Your code goes here

		int minLength = n;
		int sum = 0;

		int l = 1, r = n;

		while (l <= r)
		{

			int mid = (l + r) / 2;

			int can = bs(mid, x, arr, n);

			if (can)
			{
				minLength = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}


		return minLength;

	}
};

// t.c. = O(NlogN)
// s.c. = O(1)
