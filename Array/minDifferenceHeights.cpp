// brute force. for every tower we can either increase it by k or decrease it by k. so we will generate every possible combination and from
// each combination we will calculate the maxi difference and try to minimize the ans with it.

class Solution {
public:

	void rec(int idx, int arr[], int n, int k, int mini, int maxi, int &ans) {

		if (idx == n) {
			ans = min(ans, maxi - mini);
			return;
		}

		rec(idx + 1, arr, n, k, min(mini, arr[idx] + k), max(maxi, arr[idx] + k), ans);
		if (arr[idx] - k >= 0) {
			rec(idx + 1, arr, n, k, min(mini, arr[idx] - k), max(maxi, arr[idx] - k), ans);
		}
	}

	int getMinDiff(int arr[], int n, int k) {
		// code here
		if (n == 1) {
			return 0;
		}


		int ans = INT_MAX;

		rec(0, arr, n, k, INT_MAX, INT_MIN, ans);


		return ans;



	}
};

// t.c = O(2^N)
// s.c. = O(N)=> stack space of recursion

// optimal solution. sort the array. at every index i we will try to make that ith element as the maximum element in the optimal solution.
// to do that we will add k to a[i] and to make sure that this ith element is maximum we will subtract k from all the rhs elements.
// if rightmost - k is still > a[i] + k then it will be the greatest element else a[i]+k. now for smallest element in optimal solution,
// we will add k to  all the elements on the lhs of ith element to minimize the difference and as all elements on rhs is subtracted by k,
// the smallest value will be minimum of (a[0]+k,a[i+1]-k) . so if smallest element is >=0 we will minimize our ans by difference of
// largest and smallest. we are sorting the array so that we can find the next greater of the ith element in constant time because it
// is the possible candidate for minimum value in the optimal solution.


class Solution {
public:


	int getMinDiff(int arr[], int n, int k) {
		// code here

		sort(arr, arr + n);
		int res = arr[n - 1] - arr[0];  // upper bound ans

		for (int i = 0; i < n - 1; i++) {

			// trying to make ith element as the maximum element in optimal

			int le = max(arr[i] + k, arr[n - 1] - k); // add k to ith ele and subtract k from all on rhs and take max of ith and rightmost.
			int se = min(arr[i + 1] - k, arr[0] + k); // add k to all on lhs and all ele on rhs is subtracted by k, so min of ith and leftmost.
			if (se < 0) continue;// continue if smallest height is -ve
			res = min(res, le - se); // minimize the maximum difference
		}

		return res;


	}
};


// t.c. = O(NlogN)
// s.c. = O(1)