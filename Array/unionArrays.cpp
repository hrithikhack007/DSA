// unordered map. take a map and iterate both the array and record the occurence of elements in the map. map size will be the unique
// number of elements in both array combined.


class Solution {
public:
	//Function to return the count of number of elements in union of two arrays.
	int doUnion(int a[], int n, int b[], int m)  {
		//code here

		unordered_map<int, int> mp;

		for (int i = 0; i < n; i++) {
			mp[a[i]]++;
		}

		for (int j = 0; j < m; j++) {
			mp[b[j]]++;
		}

		return (int)mp.size();


	}
};

// t.c. = O(N+M)
// s.c. = O(N+M)

// optimized . first traverse the min length of array and insert elements from both array then after shorter array get exhausted then
// traverse only the longer array.

class Solution {
public:
	//Function to return the count of number of elements in union of two arrays.
	int doUnion(int a[], int n, int b[], int m)  {
		//code here

		unordered_map<int, int> mp;
		int i = 0;
		for (; i < min(n, m); i++) {
			mp[a[i]]++;
			mp[b[i]]++;
		}



		for (; i < ((m > n) ? m : n); i++) {

			if (m > n) mp[b[i]]++;
			else mp[a[i]]++;
		}

		return (int)mp.size();


	}
};

// t.c. = O(max(N,M))
// s.c. = O(N+M)


// using set. we will insert elements from both the array in the set as set stores only unique entries its size will be the
// ans .


class Solution {
public:
	//Function to return the count of number of elements in union of two arrays.
	int doUnion(int a[], int n, int b[], int m)  {
		//code here

		set<int> st;
		int i = 0;
		for (; i < min(n, m); i++) {
			st.insert(a[i]);
			st.insert(b[i]);
		}



		for (; i < ((m > n) ? m : n); i++) {

			if (m > n) st.insert(b[i]);
			else st.insert(a[i]);
		}

		return (int)st.size();


	}
};

// t.c. = O((N+M)log(N+M))
// s.c. = O(N+M)

// sorting and binary search. sort both the arrays. initialize a variable with 0 and count unique elements of array a.
// now while counting elements of array b check if it was present in the array or not using binary search then only count
// it


class Solution {
public:

	bool binarySearch(int k, int a[], int n) {

		int l = 0, h = n - 1;

		while (l <= h) {

			int mid = (l + h) / 2;

			if (a[mid] == k) {
				return true;
			} else if (k > a[mid]) l = mid + 1;
			else h = mid - 1;
		}

		return false;

	}

	//Function to return the count of number of elements in union of two arrays.
	int doUnion(int a[], int n, int b[], int m)  {
		//code here

		sort(a, a + n);
		sort(b, b + m);


		int count = 0;

		for (int i = 0; i < n; i++) {

			if (i != 0 && a[i] == a[i - 1]) continue;
			count++;
		}

		for (int j = 0; j < m; j++) {

			if (!binarySearch(b[j], a, n)) {
				if (j != 0 && b[j] == b[j - 1]) continue;
				count++;
			}
		}

		return count;


	}
};

// t.c. = O(nlogn + mlogm + n + mlogn)
// s.c. = O(1)
