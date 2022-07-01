// using unordered map. if size(s) != size(t) then return false. now, we want to map s[i] with t[i], s[i+1] with t[i+1],s[i+2]
// with t[i+1] till s[n-1] with t[n-1] and the mapping should be one to one that means if 'a' in string s is mapped with 'b' in string t
// then 'a' can't be mapped with any other character and also here 'b' in string t can't be maped with any other character in string s
// except 'a'.

// we will keep two maps mp1 and mp2 where mp1 will store the char,char indicating which char in string s is mapped with which char in
// string t and mp2 will store if char in string t is mapped with some char in s or not.

// for every i we will check, let ch1 ith char in s and ch2 ith char in t. if ch1 is not mapped with any char in t then we will try
// to map ch1 with ch2 but if ch2 is already mapped with some char in s then we can't mapped ch1 with ch2 so return false else map ch1
// with ch2 and put mp2[ch2] = true that ch2 is now mapped.
//else if ch1 is mapped already then we will check if ch2 is equal to the mapped character of ch1 if not we return false.

class Solution {
public:
	bool isIsomorphic(string s, string t) {

		if (s.size() != t.size()) return false;

		unordered_map<char, char> mp1;
		unordered_map<char, bool> mp2;

		for (int i = 0; i < s.size(); i++) {

			char ch1 = s[i], ch2 = t[i];

			if (mp1.find(ch1) == mp1.end()) {

				if (mp2[ch2]) return false;
				mp1[ch1] = ch2;
				mp2[ch2] = true;
			} else if (mp1[ch1] != ch2) return false;
		}

		return true;

	}
};

// t.c. = O(N)
// s.c. = O(26) => O(1)