// using hashmap. we just want to have true candidates while making choices. so we create a map where each unique value will be a key
// and the occurence of that key will be its value. now we will store all unique keys in a aux array. we will use this aux array in each
// call to make changes in the map, because we can't directly make changes in map while traversing it. at each call we will check if the
// frequency of candidate is not 0 then we will push it into the permutation and decreases its value in the map by one and call further
// by decreasing n . when n reaches 0 means we have all n elements in the permutation so we push it into the permutations vector and return
// after returning from the call we will pop out the element from permutation and insert the original value in the map and move to the
// next unique element.

// the crux of this problem is : In a call, when we choose one character then we won't choose that character next time to avoid duplication.


class Solution {
public:

	void rec(vector<int> &permutation, vector<vector<int>> &permutations, unordered_map<char, int> &mp, vector<int> &aux, int n) {

		if (n == 0) {
			permutations.push_back(permutation);
			return;
		}




		for (auto a : aux) {
			if (mp[a]) {
				int val = mp[a];
				mp[a] = val - 1;
				permutation.push_back(a);
				rec(permutation, permutations, mp, aux, n - 1);
				mp[a] = val;
				permutation.pop_back();
			}
		}


	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {


		vector<int> permutation;
		vector<vector<int>> permutations;
		int n = nums.size();

		unordered_map<char, int> mp;
		vector<int> aux;
		for (auto a : nums) mp[a]++;
		for (auto a : mp) aux.push_back(a.first);

		rec(permutation, permutations, mp, aux, n);

		return permutations;

	}
};


// t.c. = O(n*n!) => there are n! permutation possible and to generate each permutation we are requiring n time.
// s.c. = O(N) excluding space for storing permutaion else O(N*N!)(because each permutaion takes n space and there are total n! factortial
// permutations possible)

// using sorting. sort the nums array. now in each call we will traverse nums and check in map if the ith index is already taken if it is
// then we continue else we will insert this ith character in the permutation and mark ith index as visited and make a call by decreasing
// n by 1. after returning from call we will again unmark the ith index from map pop the ith element. then we will skip the duplicate
// elements to avoid repeating permutation that's why we did sorting. if n becomes 0 we will insert the permutation in ans array and return.

class Solution {
public:

	void rec(vector<int> &permutation, vector<vector<int>> &permutations, int n, vector<int> &nums, vector<int> &mp) {

		if (n == 0) {
			permutations.push_back(permutation);
			return;
		}




		for (int i = 0; i < nums.size(); i++) {

			if (!mp[i]) {
				mp[i]++;
				permutation.push_back(nums[i]);
				rec(permutation, permutations, n - 1, nums, mp);
				mp[i]--;
				permutation.pop_back();

				int j = i + 1;
				while (j < nums.size() && nums[j - 1] == nums[j]) j++;

				i = j - 1;

			}

		}


	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {


		vector<int> permutation;
		vector<vector<int>> permutations;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<int> mp(n, 0);


		rec(permutation, permutations, n, nums, mp);

		return permutations;

	}
};

// t.c. = O(N*N!)
// s.c. = O(N*N!)

// normal permutations without duplicates. at each call we will have a variable st which means we want to decide which element will come at
// that st position.
// basically st will be the position. now for e.g. if st = 2 , then that means position from 0 to 1 has been fixed now we want to decide
// for position 2. so from st = 2 till n-1 we will try all possibilites at that position i.e. we will traverse from i = st to n-1.
// for each i we will swap nums[i] with nums[st] and call forward by decrementing n by 1 . after returning from that call we will swap back
// to maintain the order of the array. if n = 0 that means we have considered all n elements, so push nums into the permutations arrray
// and return.

class Solution
{
public:

	void rec(int st, vector<int> &nums, vector<vector<int>> &permutations, int n) {

		if (n == 0) {
			permutations.push_back(nums);
		}

		for (int i = st; i < nums.size(); i++) {

			swap(nums[i], nums[st]);
			rec(st + 1, nums, permutations, n - 1);
			swap(nums[i], nums[st]);

		}
	}


	vector<vector < int>> permute(vector<int> &nums)
	{

		int n = nums.size();

		vector<vector<int>> permutations;

		rec(0, nums, permutations, n);


		return permutations;

	}
};

// t.c. = O(N*N!)
// s.c. = O(1) excluding the storage space of permutations else O(N*N!)






