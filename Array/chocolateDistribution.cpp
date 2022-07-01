// sorting and sliding window. the answer will always be the window of size m in sorted order because the least difference will be achieved only
// either by taking i-1th chocolates or i+1 th chocolates in sorted order so this is true for i-mth and i+mth as well. we will initilize a
//  window of size m and try to maximize the ans by the difference of window's maximum and minimum element. and will keep sliding it until
// r reached n-1.

class Solution {
public:
	long long findMinDiff(vector<long long> a, long long n, long long m) {
		//code

		sort(a.begin(), a.end());

		long long minDiff = LLONG_MAX;
		int l = 0, r = m - 2;


		while (r < n - 1) {

			r++;



			minDiff = min(minDiff, a[r] - a[l]);

			l++;

		}

		return minDiff;


	}
};


// t.c. = O(NlogN)
// s.c. = O(1)