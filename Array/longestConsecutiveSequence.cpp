// sorting. we will sort the array. for each i we will extend it till we are getting consecutive elements and skip the duplicates , just count the
// consecutive elemets . we will maximize the length with this count and continue.

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {


		int n = nums.size();

		sort(nums.begin(), nums.end());

		int maxLength = 0;

		for (int i = 0; i < n; i++) {


			int j = i + 1;
			int count = 1;

			while (j < n) {

				if (nums[j] - nums[j - 1] == 1) count++;
				else if (nums[j] - nums[j - 1] > 1) break;
				j++;

			}

			maxLength = max(count, maxLength);

			i = j - 1;


		}


		return maxLength;

	}
};


// t.c. = O(NlogN)
// s.c. = O(1)


// using unordered map. we will first mark all the elements in the map. then for each i we will check if a[i]-1 element is present in the array or
// not if it is then that element will take care of forming consecutive sequence with the ith element. if it is not then we will start forming
// consecutive sequence from this ith element and continue as long as elements are present in array. then we will maximize the ans with this
// sequence length.

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {


		int n = nums.size();

		int maxLength = 0;

		unordered_map<int, int> mp;

		for (auto a : nums) {
			mp[a]++;
		}

		for (int i = 0; i < n; i++) {

			if (!mp[nums[i] - 1]) {

				int count = 0, val = nums[i];

				while (mp[val]) {
					count++;
					val++;
				}
				maxLength = max(maxLength, count);
			}
		}


		return maxLength;

	}
};


// t.c. = O(N)
// s.c. = O(N)



