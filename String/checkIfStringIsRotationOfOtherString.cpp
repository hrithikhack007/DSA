// rolling hash. if size of both string are not equal return false. concatenate string s1 with itself i.e. s = s1+s1. if string s2 is present as
// a substring in s then it is the rotation of string s1 else not. this is true because in string s every substring of size s1.size() represents
// a rotation of original string s1 and covers all unique rotations.

// to check if substring present or not. we will make use of rolling hash. where we first calculate the hash value of string s2.
// e.g hash value of s2= "abcd" => (a*(p^0) + b*(p^1) + c*(p^2) + d*(p^4))%mod . where a will be the position of that character like
// a=>1,b=>2,c=>3 and so on. p is some prime number > 26 .  mod is some large prime number because hash can be too large and overflow.

// after calculating hash of s2, we will iterate slide the window of size sz and check if hash*(p^l) == windowValue.
// because it is possible that powers of substring present might be greater than powers calculated in s2.
// like if abcd is present in s from index 3 to index 6, then its windowValue will be like=> (a*(p^3) + b*(p^4) + c*(p^5) + d*(p^6))%mod.
// so to validate we will multiply the hash with the p^l so it can be in form of windows power . if it matches then we return true else
// we will remove the leftmost element of the window and continue.

// in last we return false

class Solution
{
public:
	//Function to check if two strings are rotations of each other or not.
	bool areRotations(string s1, string s2)
	{



		if (s1.size() != s2.size()) return false;

		string s = s1 + s1;

		long hash = 0, prime = 31, mod = 1000000007;

		long power[s.size() + 1];
		power[0] = 1;

		for (int i = 1; i <= s.size(); i++) {
			power[i] = (power[i - 1] * prime) % mod;
		}

		for (int i = 0; i < s2.size(); i++) {

			hash = (hash + ((s2[i] - 'a' + 1) * power[i]) % mod) % mod;

		}


		long windowValue = 0;

		for (int r = 0, l = 0; r < s.size(); r++) {

			windowValue = (windowValue + ((s[r] - 'a' + 1) * (power[r])) % mod) % mod;


			if (r - l + 1 == s2.size()) {
				if (windowValue == (hash * power[l]) % mod) {
					return true;
				}
				windowValue = (windowValue - (((s[l] - 'a' + 1) * power[l]) % mod) + mod) % mod;
				l++;


			}



		}

		return false;




	}
};

// t.c. = O(N)
// s.c. = O(N)

// brute force. we can traverse s1 and check every window with s2 if it matches or not.

class Solution
{
public:
	//Function to check if two strings are rotations of each other or not.
	bool areRotations(string s1, string s2)
	{



		if (s1.size() != s2.size()) return false;

		string s = s1 + s1;


		for (int l = 0, r = 0; r < s.size(); r++) {

			if (r - l + 1 == s2.size()) {

				if (s.substr(l, r - l + 1) == s2) {
					return true;
				}
				l++;
			}
		}


		return false;




	}
};

// t.c. = O(M*N)
// s.c. = O(N)

// brute force. check every rotation of s1 and see if it matches with s2, if it is return true else continue. in last return false.

class Solution
{
public:

	void rotate(string &s1) {

		char t = s1[0];

		for (int i = 0; i < s1.size() - 1; i++) {
			s1[i] = s1[i + 1];
		}

		s1[s1.size() - 1] = t;
	}

	//Function to check if two strings are rotations of each other or not.
	bool areRotations(string s1, string s2)
	{



		if (s1.size() != s2.size()) return false;

		for (int i = 0; i < s1.size(); i++) {

			if (s1 == s2) {
				return true;
			} else {
				rotate(s1);
			}
		}

		return false;



	}
};


// t.c. = O(N^2)
// s.c. = O(1)