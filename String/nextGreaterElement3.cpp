// greedy. its just a variation of next greater permutation. convert the number into string then perform next greater permutation algo.

class Solution {
public:
	int nextGreaterElement(int n) {

		string s = "";

		while (n > 0) {

			s.push_back(char('0' + (n % 10)));
			n /= 10;
		}

		reverse(s.begin(), s.end());
		int sz = s.size();
		int breakingPoint = -1;

		for (int i = sz - 2; i >= 0; i--) {

			if (s[i] < s[i + 1]) {
				breakingPoint = i;
				break;
			}
		}

		if (breakingPoint == -1) return -1;

		for (int i = sz - 1; i > breakingPoint; i--) {
			if (s[i] > s[breakingPoint]) {
				swap(s[i], s[breakingPoint]);
				reverse(s.begin() + breakingPoint + 1, s.end());
				break;
			}
		}

		long num = stol(s);
		if (num > INT_MAX) return -1;
		return num;

	}
};

// t.c. = O(digits)
// s.c. = O(digits)

