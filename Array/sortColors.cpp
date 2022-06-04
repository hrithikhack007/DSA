// dutch national flag algorithm . we will keep three pointers low,mid and high. mid will act like current element and whenever mid=0
// swap(arr[mid++],arr[low++]) and if arr[mid]=1 just mid++ else swap(arr[mid],arr[high--]).
// this is based on the fact that everything on the lhs of low will be 0 and everything on rhs of high will be 2 and everything
// in-between low and high including will be 1.


class Solution {
public:
	void sortColors(vector<int>& nums) {

		int low = 0, mid = 0, high = nums.size() - 1;

		while (mid <= high) {

			if (nums[mid] == 1) {
				mid++;
			}
			else if (nums[mid] == 0) {
				swap(nums[mid++], nums[low++]);
			}
			else {
				swap(nums[mid], nums[high--]);
			}
		}

	}
};


// t.c. = O(N)
// s.c. = O(1)

// Bucket sort . we will traverse the nums array 3 times for 0,1 and 2 respectively. we will declare a new array arr and in the
// first traversal of nums array we will insert in arr if curr element is 0 so in this way all 0's of nums will be inserted in
// arr array then similarly we will do for 1 and 2 in second and third traversal respectively.


class Solution {
public:
	void sortColors(vector<int>& nums) {

		int n = nums.size();

		vector<int> arr;

		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j < n; j++) {
				if (nums[j] == i) {
					arr.push_back(i);
				}
			}
		}

		nums = arr;

	}
};

// t.c. = O(N)
// s.c. = O(N)

// count the occurences of 0,1 and 2. keep three variables c1,c2,c3 and in one iteration count the occureneces. then run three
// while loops in order of 0 -> 1 -> 2 with condition being count of their occurences.

class Solution {
public:
	void sortColors(vector<int>& nums) {

		int n = nums.size();

		int cnt0 = 0, cnt1 = 0, cnt2 = 0;

		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) cnt0++;
			else if (nums[i] == 1) cnt1++;
			else cnt2++;
		}

		int idx = 0;

		while (cnt0--) nums[idx++] = 0;
		while (cnt1--) nums[idx++] = 1;
		while (cnt2--) nums[idx++] = 2;

	}
};

// t.c. = O(N)
// s.c. = O(1)
