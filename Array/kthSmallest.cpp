// sort the array and return k-1 th element

class Solution {
public:
	// arr : given array
	// l : starting index of the array i.e 0
	// r : ending index of the array i.e size-1
	// k : find kth smallest element and return using this function
	int kthSmallest(int arr[], int l, int r, int k) {
		//code here

		sort(arr, arr + r + 1);

		return arr[k - 1];


	}
};

// t.c. = O(NlogN)
// s.c. = O(1)


// using priority queue

// we will keep a max priority queue , if size of pq < k then we will insert the current element else we will check if the current
// element < top element if it is that means the top element can't be our ans because it is greater than atmost k elements so
// we will pop it and push the current element in the pq. in the end we will have our ans as top element.


class Solution {
public:
	// arr : given array
	// l : starting index of the array i.e 0
	// r : ending index of the array i.e size-1
	// k : find kth smallest element and return using this function
	int kthSmallest(int arr[], int l, int r, int k) {
		//code here


		priority_queue<int, vector<int>> pq;

		for (int i = 0; i <= r; i++) {

			if (pq.size() < k) {
				pq.push(arr[i]);
			} else if (pq.size() == k && arr[i] < pq.top()) {
				pq.pop();
				pq.push(arr[i]);
			}

		}

		return pq.top();




	}
};


// t.c. = O(NlogK) => logk for inserting and popping element of pq
// s.c. = O(K) => number of elements in pq


// QuickSelect Algorithm. We will choose mid element and we will try to find its correct position as in sorted array. After this
// if its sorted position matches with k then we will return that element as answer else if the position of the current position
// is less than k that means kth smallest lies on its rhs so we will neglect the left half and continue the search on the rhs of
// current element's position else if the position of the current element is greater than that of k then our target lies on lhs
// of its position so we will neglect its right half and continue the search on the lhs part.




class Solution {
public:
	int kthSmallest(int arr[], int l, int r, int k) {
		//code here


		int mid = (l + r) / 2;
		int s = l, e = r;
		swap(arr[mid], arr[e]);
		while (l <= r) {


			while (arr[l] < arr[e]) l++;
			while (r >= s && arr[r] >= arr[e]) r--;

			if (l <= r)
				swap(arr[l++], arr[r--]);



		}


		swap(arr[e], arr[l]);



		if (l + 1 == k) {
			return arr[l];
		} else if (k > l + 1) {

			return kthSmallest(arr, l + 1, e, k);
		} else {
			return kthSmallest(arr, s, l - 1, k);
		}


	}
};


// t.c. = O(N) on average as the array will get partitioned after finding the sorted position of the element and for each partition
// we will neglect one of the half so on average it will result in O(N) time complexity.

// s.c. = O(logN) => stack space of recursion
