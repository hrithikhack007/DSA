// using auxillary array. we will insert all n elements of arr1 and all m elements of arr2 into auxillary array. we will sort the auxillary
// array, after this we will reassign starting n elements of auxillary array into arr1 and last m elements into arr2.


class Solution {
public:
	void merge(int arr1[], int arr2[], int n, int m) {
		// code here


		int auxillary[n + m];
		int indexAuxillary = 0;

		for (int index = 0; index < n; index++) {


			auxillary[indexAuxillary++] = arr1[index];

		}


		for (int index = 0; index < m; index++) {

			auxillary[indexAuxillary++] = arr2[index];

		}

		sort(auxillary, auxillary + n + m);


		indexAuxillary = 0;

		for (int index = 0; index < n; index++) {

			arr1[index] = auxillary[indexAuxillary++];
		}

		for (int index = 0; index < m; index++) {

			arr2[index] = auxillary[indexAuxillary++];
		}


	}
};


// t.c. = O((N+M)log(N+M))
// s.c. = O(N+M)


// two pointer Approach. we will have two pointer first pointing on the starting index of arr1 and second pointing on the starting index
// of arr2. at each iteration we will compare if value of first < value of second we will insert value of first element in auxillary array
// and increment both the first pointer as well as auxillary pointer similarly for second pointer if its value is smaller than value of first
// pointer. if any one of the pointer reach out of bound of their respective arrays we will terminate the loop and fill the remaining values
// of either arr1 or arr2 whichever is not exhausted. In last we will reassign the first n elements in arr1 and last m elements in arr2.

class Solution {
public:
	void merge(int arr1[], int arr2[], int n, int m) {
		// code here


		int auxillary[n + m];


		int First = 0, Second = 0, auxillaryPointer = 0;

		while (First < n && Second < m) {

			if (arr1[First] < arr2[Second]) {
				auxillary[auxillaryPointer++] = arr1[First++];
			} else {
				auxillary[auxillaryPointer++] = arr2[Second++];
			}

		}

		while (First < n) auxillary[auxillaryPointer++] = arr1[First++];
		while (Second < m) auxillary[auxillaryPointer++] = arr2[Second++];


		int indexAuxillary = 0;

		for (int index = 0; index < n; index++) {

			arr1[index] = auxillary[indexAuxillary++];
		}

		for (int index = 0; index < m; index++) {

			arr2[index] = auxillary[indexAuxillary++];
		}


	}
};


// t.c. = O(N+M)
// s.c. = O(N+M)

// without extra space using swapping. initialize three pointers. pointer f,l and s pointing on first index of arr1,last index of arr1 and
// first index of arr2 respectively. compare value of f and value of s. if val of f <= val of s then increment f by one else swap the  val
// of l with val of s and decrement l by one and increment s by one. continue this process until f and l cross each other or pointer s
// reach out of bound of arr2.
// our target is to get the first n sorted values in arr1 and last m sorted values in arr2. so all the elements lhs of f  and rhs of l ensures
// that they are less than all the values of arr2 because we are swapping smaller values of arr2 with larger values of arr1.

class Solution {
public:
	void merge(int arr1[], int arr2[], int n, int m) {
		// code here


		int f = 0, l = n - 1, s = 0;


		while (f <= l && s < m) {

			if (arr1[f] <= arr2[s]) f++;
			else {

				swap(arr1[l--], arr2[s++]);

			}

		}

		sort(arr1, arr1 + n);
		sort(arr2, arr2 + m);


	}
};

// t.c = O((n+m) + (nlogn + mlogm))
// s.c. = O(1)







