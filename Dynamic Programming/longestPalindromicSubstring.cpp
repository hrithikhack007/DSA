// brute force. check all substring if its a palindnrome or not and if it is then maximize the length and store its starting index.

class Solution {
public:

	bool isPalindrome(string s) {

		int l = 0, r = s.size() - 1;

		while (l < r) {

			if (s[l++] != s[r--]) return false;
		}

		return true;
	}

	string longestPalindrome(string s) {
		int n = s.size();

		int maxi = 1, start = 0;

		for (int g = 1; g <= n; g++) {

			for (int i = 0; i + g - 1 < n; i++) {

				int j = i + g - 1;

				if (isPalindrome(s.substr(i, j - i + 1))) {
					if (j - i + 1 > maxi) {
						start = i;
						maxi = j - i + 1;
					}
				}
			}
		}

		return s.substr(start, maxi);

	}
};

// t.c. = O(N^3) => O(N^2) to generate all substring and O(N) to check each substring
// s.c. = O(1)


// better. kind of dp. palindrome has property like for e.g. string s has its start and end characters equal and the substring from s[1]
// to s[n-2] is itself a palindrome then string s is also a palindrome. we can use this property to store the values for smaller string
// and use those to validate larger strings. if size of string is 1 then its a palindrome, if its length is 2 and both of its characters
// are same then its a palindrome, and else for any string len > 2 we can use the above property as we would have already calculated the
// values for smaller strings. if the current string is palindrome and its size is > max then we will maximize the length and store its
// starting index.

class Solution {
public:



	string longestPalindrome(string s) {
		int n = s.size();

		int maxi = 1, start = 0;

		bool isPalindrome[n][n];

		for (int g = 1; g <= n; g++) {

			for (int i = 0; i + g - 1 < n; i++) {
				int j = i + g - 1;
				isPalindrome[i][j] = false;

				if (i == j) {
					isPalindrome[i][j] = true;
				} else if (j - i == 1 && s[i] == s[j]) {
					isPalindrome[i][j] = true;
				} else {

					if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
						isPalindrome[i][j] = true;
					}
				}

				if (isPalindrome[i][j] && j - i + 1 > maxi) {

					maxi = j - i + 1;
					start = i;
				}
			}
		}

		return s.substr(start, maxi);

	}
};

// t.c. = O(N^2)
// s.c. = O(N^2)


// optimized space using expand around center. for each i we will check: for even palindrome we will start from j=i+1 and k=i and we will try
// to form a even length palindorome by extending this pointers as long as they are palindrome. for odd length plaindrome we start j and k from
// i then again try to extend this as long as they are palindrome. in both cases we will try to maximize the length and store the start of
// max palindrome find till now. in the end we will return the max length plaindrome.

class Solution {
public:



	string longestPalindrome(string s) {
		int n = s.size();

		int maxi = 1, start = 0;


		for (int i = 0; i < n; i++) {


			for (int j = i + 1, k = i; j < n && k >= 0 && s[j] == s[k]; j++, k--) {

				if (j - k + 1 > maxi) {
					maxi = j - k + 1;
					start = k;
				}
			}

			for (int j = i, k = i; j < n && k >= 0 && s[j] == s[k]; j++, k--) {

				if (j - k + 1 > maxi) {
					maxi = j - k + 1;
					start = k;
				}
			}

		}



		return s.substr(start, maxi);

	}
};

// t.c. = O(N^2)
// s.c = O(1)