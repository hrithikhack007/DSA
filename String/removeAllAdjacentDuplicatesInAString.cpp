// stack type .we will use a result string as a stack. if the res is not empty and the last element is equal to the current element then we have
// found duplicate adjacent characters and we simply pop back that last character and skip the current character, else we push it in the res.

// leectode version where at a time only two adjacent duplicate characters can remove.

// edge case: we can only remove two adjacent duplicates at a time, so don't try to remove all the adjacent duplicate elements in a single go .
// if we found one pair of  adjacent duplicate then just remove that pair and move to next index the code will automatically handle the rest.


class Solution {
public:
	string removeDuplicates(string s) {

		int n = s.size();

		string res = "";

		for (int i = 0; i < n; i++) {

			if (res.size() != 0 && res.back() == s[i]) {

				res.pop_back();
			} else {
				res.push_back(s[i]);
			}

		}

		return res;

	}
};

// t.c. = O(N)
// s.c. = O(N)

// gfg version. basically , we will traverse a string and for each i whenever we encounter duplicate adjacent elements then we will run
// inner while loop till we adjacent elements are same else we will simply insert this character in string res.
// before any traversal we will initialize a boolean ok to false.
// now whenever we found a adjacent duplicate character we will set ok = true and after traversing the string s if wee see that ok
// is true that means some adjacent duplicate characters were removed so new string res might contain adjacent duplicate like
// abccb here after removing cc res will be abb so again we have bb as adj. duplicate then we will again run the code until ok remains
// false.

class Solution {
public:
	string rremove(string s) {
		// code here


		int n = s.size();


		while (1) {

			bool ok = false;

			string res = "";

			for (int i = 0; i < s.size(); i++) {

				if (i + 1 < n && s[i] == s[i + 1]) {
					while (i + 1 < n && s[i] == s[i + 1]) {
						ok = true;
						i++;
					}
				} else res.push_back(s[i]);
			}

			if (!ok) break;

			s = res;


		}

		return s;
	}
};

// t.c. = O(N^2)
// s.c. = O(N)

