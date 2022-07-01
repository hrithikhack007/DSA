// using unordered map. for each string we will sort it using count sort then we will insert this in vector mapped to the sorted string in map.
// this way all the anagrams will be grouped in one vector. this works because anagrams are basically permutations in which frequency of every
// letter in one string is same to the frequency of all letters in another string. so if we sort two anagrams they become identical. so we are
// able to mapped anagrams together because of this identity.

// after grouping all anagrams together, we will push each group in the ans vector.

class Solution
{
public:

	string countSort(string &s) {

		vector<int> f(26, 0);

		for (auto a : s) f[a - 'a']++;

		string res = "";

		for (int i = 0; i < 26; i++) {
			while (f[i]) {
				res.push_back(char('a' + i));
				f[i]--;
			}
		}

		return res;
	}

	vector<vector < string>> groupAnagrams(vector<string> &strs)
	{

		unordered_map<string, vector < string>> mp;

		for (auto s : strs)
		{

			mp[countSort(s)].push_back(s);
		}

		vector<vector < string>> ans;

		for (auto a : mp)
		{

			ans.push_back(a.second);
		}

		return ans;
	}
};


// t.c. = O(N*(k+26)) => N is the length of vector of strings, k is the average length of each string and +26 for sorting.
// s.c. = O(N*k) => N is the length of vector and k is the average length of string.