// SYMBOL       VALUE
// I            1
// IV           4
// V            5
// IX           9
// X            10
// XL           40
// L            50
// XC           90
// C            100
// CD           400
// D            500
// CM           900
// M            1000

// In roman, number to avoid same symbols repeated 4 time in a row like IIII or XXXX we use subtraction between these symbols like,
// IV => 5 - 1 = 4, XL => 50 - 10 = 40.
// so the crux of this problem is let's say we are at ith symbol and if i+1th symbol's value is > ith symbol value then we add (val[i+1]-val[i])
// into the num and increment i++ to skip the i+1th character else we will simply ith symbol value into num and continue.

class Solution {
public:
	int romanToDecimal(string &str) {
		// code here

		unordered_map<char, int> mp({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
		});

		int num = 0, n = str.size();

		for (int i = 0; i < n; i++) {

			if (i + 1 < n && mp[str[i + 1]] > mp[str[i]]) {
				num += (mp[str[i + 1]] - mp[str[i]]);
				i++;
			} else {
				num += (mp[str[i]]);
			}

		}

		return num;


	}
};

// t.c. = O(N)
// s.c. = O(1)