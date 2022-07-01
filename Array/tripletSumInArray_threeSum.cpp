// check all triplets.

class Solution {
public:
	//Function to find if there exists a triplet in the
	//array A[] which sums up to X.
	bool find3Numbers(int A[], int n, int X)
	{


		for (int i = 0; i < n; i++) {

			for (int j = i + 1; j < n; j++) {

				for (int k = j + 1; k < n; k++) {

					if (A[i] + A[j] + A[k] == X) return true;
				}
			}
		}

		return false;


	}

};

// t.c. = O(N^3)
// s.c. = O(1)

// binary search. we will find all pairs and then for each pair on the rhs we will do a binary search for the 3rd element, if it is present
// so we will return true. in the end we return false.

class Solution {
public:
	//Function to find if there exists a triplet in the
	//array A[] which sums up to X.
	bool find3Numbers(int A[], int n, int X)
	{


		sort(A, A + n);

		for (int i = 0; i < n - 1; i++) {

			for (int j = i + 1; j < n; j++) {

				if (binary_search(A + j + 1, A + n, X - A[i] - A[j])) return true;
			}

		}

		return false;


	}

};

// t.c. = O(N^2logN)
// s.c. = O(1)

// sorting + two pointers. sort the array. for each i , do a two pointers sweep. t = X-a[i], we will try to find two elements that sums up
// to t . l start from i+1 and r from n-1. if a[l]+a[r]==t so we can say that we have found three elements viz. a[i],a[l] and a[r] so return
// true. else if a[l]+a[r] < t , we will increment l pointer by 1 because if we decrement r pointer the sum is going to decrease even more.
// but we want to increase the sum to reach t. else if a[l]+a[r]>t, we will decrement r by one position. in the end if couldnt find return
// false.

class Solution {
public:
	//Function to find if there exists a triplet in the
	//array A[] which sums up to X.
	bool find3Numbers(int A[], int n, int X)
	{


		sort(A, A + n);

		for (int i = 0; i < n; i++) {

			int t = X - A[i];

			int l = i + 1, r = n - 1;

			while (l < r) {

				int val = A[l] + A[r];

				if (val == t) return true;
				else if (val < t) l++;
				else r--;
			}

		}

		return false;


	}

};


// t.c. = O(N^2)
// s.c. = O(1)

