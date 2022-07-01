// using two arrays. we will use two arrays viz positive and negative . initially we will insert all -ve and +ve elements in negative and positive
// arrrays respectively. then starting with positive in the start we will alternately place the -ve and +ve elements in the array, if one of
// the array got exhausted then we will insert the elements of the remaining either -ve or +ve.

class Solution {
public:

	void rearrange(int arr[], int n) {
		// code here


		vector<int> neg, pos;

		for (int i = 0; i < n; i++) {
			if (arr[i] < 0) neg.push_back(arr[i]);
			else pos.push_back(arr[i]);
		}

		int idxNeg = 0, idxPos = 0;

		for (int i = 0; i < n; i++) {

			if (i % 2 == 0 && idxPos < pos.size()) {
				arr[i] = pos[idxPos++];
			} else if (i % 2 == 1 && idxNeg < neg.size()) {

				arr[i] = neg[idxNeg++];
			} else {
				if (idxNeg < neg.size()) arr[i] = neg[idxNeg++];
				else arr[i] = pos[idxPos++];
			}
		}




	}
};


// t.c. = O(n)
// s.c. = O(n)

// insertion sort technique. for each i we will check if the ith element parity is satisfied , if not then we will try to find the right
// parity element on its rhs if we found it then we will insert that element at ith index and insert the previous ith element in next index
// by right shifting the rhs elements to ith element by one position. this right shift will be done for elements between ith index and the
// index of the right parity element we found. if we don't found any correct parity element for ith position then we will simply return as
// there is nothing to fix.

class Solution {
public:

	void insert(int arr[], int st, int en, int n) {


		int t, val = arr[en];

		for (int i = st; i <= en; i++) {
			t = arr[i];
			arr[i] = val;
			val = t;

		}

	}

	bool findAndInsert(int idx, int parity, int arr[], int n) {


		for (int i = idx + 1; i < n; i++) {

			if ((parity == -1 && arr[i] < 0) || (parity == 1 && arr[i] >= 0)) {
				insert(arr, idx, i, n);
				return true;
			}
		}
		return false;

	}

	void rearrange(int arr[], int n) {
		// code here


		for (int i = 0; i < n; i++) {



			if (i % 2 == 0 && arr[i] < 0) {

				if (!findAndInsert(i, 1, arr, n)) return;

			} else if (i % 2 == 1 && arr[i] >= 0) {
				if (!findAndInsert(i, -1, arr, n)) return;
			}


		}



	}
};


// t.c. = O(N^2)
// s.c. = O(1)