// brute force. check sum of all subarrays .

class Solution {
public:
	//Complete this function
	//Function to check whether there is a subarray present with 0-sum or not.
	bool subArrayExists(int arr[], int n)
	{
		//Your code here

		for (int i = 0; i < n; i++) {

			int sum = 0;

			for (int j = i; j < n; j++) {

				sum += arr[j];
				if (sum == 0) return true;
			}
		}

		return false;

	}
};

// t.c. = O(N^2)
// s.c. = O(1)


// use unordered map. store the frequency of prefix sums . if there exist a subarray with sum = 0 let's say subarray from i to j is a 0
// sum subarray, then whatever the sum till i-1th index was it will be repeated at the jth index again. if we found any sum repeating
// or the sum itself becoming 0 then we will return true else we will store this sum in the map. if we don't find any repeating sum
// we will return false.

class Solution {
public:
	//Complete this function
	//Function to check whether there is a subarray present with 0-sum or not.
	bool subArrayExists(int arr[], int n)
	{
		//Your code here
		unordered_map<int, int> mp;
		int sum = 0;

		for (int i = 0; i < n; i++) {

			sum += arr[i];
			if (sum == 0 || mp[sum]) return true;
			mp[sum]++;
		}

		return false;

	}
};


// t.c. = O(N)
// s.c. = O(N)