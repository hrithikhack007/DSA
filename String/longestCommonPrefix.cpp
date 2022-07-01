// brute force. we will keep n pointers to track characters of n strings. at each iteration we will check if any pointer exceeds its
// corresponding string size then we break out of the loop else we will push the current string's character which the pointer is pointing
// at into the unordered set and increment the pointer by one. Outside the loop we will check if the unordered set size is > 1 if it is
// then all the strings doesn't have common character so we break else all strings have common character and we insert that characer into
// the ans string and extend our common prefix.


// if s is empty means there is no common prefix so we return -1 else we return longest common prefix.

class Solution {
public:

	string longestCommonPrefix (string arr[], int N)
	{
		// your code here

		vector<int> pointers(N, 0);

		string s = "";

		while (1) {
			bool ok = true;
			unordered_set<char> st;
			for (int i = 0; i < N; i++) {
				if (pointers[i] == arr[i].size()) {
					ok = false;
					break;
				} else {
					st.insert(arr[i][pointers[i]++]);
				}
			}



			if (!ok) break;
			else if (ok && st.size() > 1) break;
			else {

				s.push_back(*(st.begin()));
			}

		}

		if (s.size() == 0) return "-1";
		return s;


	}
};

// t.c. = O(N*min(|arr[i]|)) => N is the number of strings in arr
// s.c. = O(N)



// filter out prefix from left to right. take arr[0] string as the result, now starting from the 1st index to last keep comparing the result
// with the ith string i.e. find the common prefix between them and update the result . in the end result will contain the longest common
// prefix of all the string.

class Solution {
public:

	string commonPrefix(string &s, string &t) {

		string result = "";
		int len = min(s.size(), t.size());

		for (int i = 0; i < len; i++) {

			if (s[i] == t[i]) {
				result.push_back(s[i]);
			} else break;
		}

		return result;
	}


	string longestCommonPrefix (string arr[], int N)
	{

		string result  = arr[0];


		for (int i = 1; i < N; i++) {

			result = commonPrefix(arr[i], result);

		}

		if (result.size() == 0) return "-1";
		return result;


	}
};

// t.c. = O(N*(max|arr[i]|))
// s.c. = O(max|arr[i]|)