// start from the second last element of the array. keep checking for every i if i+1th element is > ith element, if it is then that means we can
// swap the ith element with one of the element in the suffix. if it is not then continue. lets say if we found it called it a breaking point then
// again start from the end and search the minimum element which is greater than the ith element ans swap with it. until we find the breaking
// point all the elements on the suffix will form a non-increasing sequence so after swapping all the elements on the right will be smaller than
// the swapped element and all element on lhs of it till breaking point will be greater than it. so we wil reverse this non-increasing sequence to
// maintain the lexographically smaller sequence condition.if we can't find the breaking point that means the original sequence is in
// non-increasing order so we just reverse it.

class Solution {
public:
	void nextPermutation(vector<int>& nums) {


		int breakingPoint = -1 , n = nums.size();

		for (int i = n - 2; i >= 0; i--) {

			if (nums[i + 1] > nums[i]) {
				breakingPoint = i;
				break;
			}

		}

		if (breakingPoint == -1) {
			reverse(nums.begin(), nums.end());
		} else {

			for (int i = n - 1; i > breakingPoint; i--) {

				if (nums[i] > nums[breakingPoint]) {
					swap(nums[i], nums[breakingPoint]);
					break;
				}

			}

			reverse(nums.begin() + breakingPoint + 1, nums.end());

		}



	}
};


// t.c. = O(N)
// s.c. = O(1)
