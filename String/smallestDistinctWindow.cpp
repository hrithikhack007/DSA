// using unordered map. we will first count the distinct characters present in the string in distinc map. we will use another map window
// which we will use to count the occurences of characters in a window or a subtring of the string. we will keep two variable l and r
// initialized to 0 indicating the end points of the window. at each iteration we store the occurence of the rth character in the window
// map then we check does the window contain all the distinct characters, if it does then we will try to reduce the size of window by
// maintaining the distinc characters within it. the instance in which window doesn't contain all distinc characters we will break and
// increment r to find another valid window.

// basically, we try to find valid window first then we try to shrink that window's size as small as possible by maintaining all the
// distinct characters within the window and if it becomes invalid we repeat the process again.

class Solution {
public:
	int findSubString(string str)
	{
		// Your code goes here

		int n = str.size();

		unordered_map<char, bool> distinct;
		unordered_map<char, int> window;

		for (auto ch : str) {
			distinct[ch] = true;
		}

		int l = 0, r = 0;
		int mini = n;

		while (r < n) {


			window[str[r]]++;


			if (window.size() == distinct.size()) {

				while (window.size() == distinct.size()) {

					mini = min(mini, r - l + 1);
					window[str[l]]--;

					if (window[str[l]] == 0) {
						window.erase(window.find(str[l]));
					}
					l++;
				}

			}


			r++;

		}

		return mini;


	}
};

// t.c. = O(N)
// s.c. = O(N)