// brute force. compare all pairs and count accordingly.

class Solution {

public:
	// arr[]: Input Array
	// N : Size of the Array arr[]
	// Function to count inversions in the array.
	long long int inversionCount(long long arr[], long long N)
	{
		// Your Code Here

		long long inversions = 0;

		for (int i = 0; i < N; i++) {

			for (int j = i + 1; j < N; j++) {

				if (arr[i] > arr[j]) {
					inversions++;
				}
			}
		}

		return inversions;



	}

};


// t.c. = O(N^2)
// s.c. = O(1)


// using merge sort technique. we will start the range from 0 and n-1. we will divide the range in 2 halfs recursively from mid point. we will
// independently calculate the inversion count in the first half as well as in the second half then we will calculate the inversion count with
// respect to this two halfs and return the total inversion count i.e. left_count + right_count + res(count of inversion involving both the
// halfs).

class Solution {

public:

	long long merge(long long arr[], int st, int mid, int en) {


		long long inversion = 0;

		long long aux[en - st + 1];

		int idx = 0, i = st, j = mid + 1;

		while (i <= mid && j <= en) {

			if (arr[i] <= arr[j]) {
				aux[idx++] = arr[i++];
				inversion += (j - mid - 1);

			} else {
				aux[idx++] = arr[j++];

			}

		}


		while (i <= mid) {
			inversion  += (j - mid - 1);
			aux[idx++] = arr[i++];
		}

		while (j <= en) {
			aux[idx++] = arr[j++];
		}

		idx = 0;

		for (int i = st; i <= en; i++) {
			arr[i] = aux[idx++];
		}

		return inversion;

	}


	long long mergeSort(long long arr[], int st, int en) {


		if (st == en) {
			return 0;
		}


		int mid = (st + en) / 2;
		long long inversion = 0;

		inversion += mergeSort(arr, st, mid);
		inversion += mergeSort(arr, mid + 1, en);

		long long res =  merge(arr, st, mid, en);
		return inversion + res;

	}

	long long int inversionCount(long long arr[], long long N)
	{

		return mergeSort(arr, 0, N - 1);

	}

};


// t.c = O(NlogN)
// s.c. = O(N)
