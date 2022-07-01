// unordered map. count the frequency of all elements in the array. insert those elements in the ans array whose frequency is > n/3.

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {

		int n = nums.size();
		unordered_map<int, int> mp;


		for (auto a : nums) {
			mp[a]++;
		}

		vector<int> ans;


		for (auto a : mp) {

			if (a.second > n / 3) ans.push_back(a.first);
		}

		return ans;


	}
};

// t.c. = O(N)
// s.c. = O(N)

// Boyer-Moore majority voting algorithm. There can be atmost 2 majority element. so keep two variables candidate1 and candidate2 also count1 and
// count2 to keep track of their frequency. now , for each i check, if ith element is equal to cand1 then increment count1 else if it is equal to
// the cand2 in that case increment count2 else if it is not equal to both of them that means either its a minority element or candidate1 or
// candidate2 has been cancelled out by some minority elements. if count1 == 0 then that means cand1 had been cancelled out so assign current element
// to cand1 and increment count1 else if count1 was already been > 0 then check the same for count2. if all the above conditions has been false
// that means both candidate1 and candidate2 has been assigned with some value having frequency > 0 that means ith element is the minority element
// so it will cancel out both majority element once by decrementing their count by one. in last whatever values we get in cand1 and cand2 we will
// cross check it again if the frequency is > n/3  then only we will insert it in the ans array.


class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {

		int n = nums.size();

		vector<int> ans;

		int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0;


		for (int i = 0; i < n; i++) {


			if (nums[i] == candidate1) count1++;
			else if (nums[i] == candidate2) count2++;
			else if (count1 == 0) {
				candidate1 = nums[i];
				count1++;
			} else if (count2 == 0) {
				candidate2 = nums[i];
				count2++;
			} else {
				count1--;
				count2--;
			}

		}

		int f1 = 0, f2 = 0;

		for (int i = 0; i < n; i++) {

			if (nums[i] == candidate1) f1++;
			else if (nums[i] == candidate2) f2++;
		}

		if (f1 > (n / 3)) ans.push_back(candidate1);
		if (f2 > (n / 3)) ans.push_back(candidate2);


		return ans;


	}
};


// t.c. = O(N)
// s.c. = O(1)

