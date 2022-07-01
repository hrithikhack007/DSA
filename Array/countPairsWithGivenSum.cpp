// brute force. check all pairs for the given sum.

class Solution {
public:
	int getPairsCount(int arr[], int n, int k) {
		// code here

		int count = 0;

		for (int i = 0; i < n; i++) {

			for (int j = i + 1; j < n; j++) {

				if (arr[i] + arr[j] == k) count++;
			}
		}

		return count;

	}
};

// t.c. = O(N^2)
// s.c = O(1)


// using unordered map. for each i check how many k-arr[i] values we have seen because by adding the ith and that value we will get k so we will
// add that count to our ans. and also increment the count for the current element in the map.

class Solution {
public:
	int getPairsCount(int arr[], int n, int k) {
		// code here

		unordered_map<int, int> mp;
		int count = 0;

		for (int i = 0; i < n; i++) {

			count += mp[k - arr[i]];

			mp[arr[i]]++;
		}

		return count;

	}
};

// t.c. = O(N)
// s.c. = O(N)

// binary search. Sort the array. for each i, calculate val = k - arr[i] then check if it is present on its rhs if not then continue else find
// the lower_bound index and upper_bound index of that val. that range will cover all the occurence of that val. so add that range into count.
// because that val + ith element will give you k.

class Solution {
public:
	int getPairsCount(int arr[], int n, int k) {
		// code here

		sort(arr, arr + n);

		int count = 0;

		for (int i = 0; i < n; i++) {
			int val = k - arr[i];
			if (!binary_search(arr + i + 1, arr + n, val)) {
				continue;
			}

			int lidx = lower_bound(arr + i + 1, arr + n, val) - arr;
			int uidx = upper_bound(arr + i + 1, arr + n, val) - arr;

			count += (uidx - lidx);
		}

		return count;

	}
};


// t.c. = O(NlogN)
// s.c. = O(1)

