// using unordered map. first we will store the occurences of all the characters of string t in the map. Now we will keep two pointer l and r
// both initialized to 0 , where l will be the left end of the window and r will be the right end of the window.
// if mp[s[r]] == 3 that means we require 3 more characters in the window so that the frequency of s[r] in window matches with
//  of s[r] in string t. let's call a window valid if it contains all the characters of string t. now at each iteration we check if the
// freq. of s[r] is > 0 if it is then we increment the counter by one because this s[r] is contributing in making the window validate i.e. we are
// adding a genuine character in window.
// now we have counter which stores the count of genuine characters of string t present in the window. while counter is equal to t.size() then
// window now will be validate and we try to minimize this window by shifting l pointer. in the inner loop, at every iteration, we will minimze
// the length and update the starting index of the string to be returned, if mp[s[l]] == 0 that means after removing this we will need 1 more
// s[r] for valdidate window so we decrement counter indicating one genuine character has been removed , mp[s[l]]++ , increment l by one.

// increment r by one.

// return the string starting from idx of size mini


class Solution {
public:
	string minWindow(string s, string t) {

		int n = s.size();

		unordered_map<char, int> mp;

		for (auto ch : t) mp[ch]++;

		int l = 0, r = 0;
		int mini = n + 1, count = 0, idx = -1;


		while (r < n) {

			if (mp[s[r]] > 0) count++;

			mp[s[r]]--;

			while (count == t.size()) {
				if (r - l + 1 < mini) {
					mini = r - l + 1;
					idx = l;
				}

				if (mp[s[l]] == 0) {
					count--;
				}

				mp[s[l]]++;


				l++;

			}

			r++;

		}


		return mini == n + 1 ? "" : s.substr(idx, mini);

	}
};

// t.c. = O(M+N)
// s.c. = O(26) => O(1)