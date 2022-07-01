// recursive solution. we we will start with res = 1. at each call we will loop through result and and for each i we will calculate how many
// contiguous elements are present equal to ith element, then we will insert the count and ith element in the temp string. we will repeat this step
// from the next index. after constructing a temp string we will again call on rec by passing this temp and decrementing n.
// if n becomes 0 we will return res.

class Solution {
public:

	string rec(string res, int n) {

		if (n == 0) return res;

		string temp = "";
		int sz = res.size();

		for (int i = 0; i < sz; i++) {

			int j = i + 1;
			while (j < sz && res[j - 1] == res[j]) j++;

			temp.push_back(char(j - i + '0'));
			temp.push_back(res[i]);

			i = j - 1;
		}


		return  rec(temp, n - 1);
	}


	string countAndSay(int n) {

		string res = "1";
		return rec(res, n - 1);



	}
};

// t.c. = O(n*2^n) => as in every call string length doubles so to traverse the string it will take 2^n time.
// s.c. = O(2^n) => to store string of size of power of 2


// iterative solution. its similar to recursive. we will construct the res string n-1 times. each time traversing whole res to calculate
// new string temp by calculating consecutive sequences and storing their occurenece with elements and return this temp.

class Solution {
public:

	string build(string &res) {



		string temp = "";
		int sz = res.size();

		for (int i = 0; i < sz; i++) {

			int j = i + 1;
			while (j < sz && res[j - 1] == res[j]) j++;

			temp.push_back(char(j - i + '0'));
			temp.push_back(res[i]);

			i = j - 1;
		}


		return  temp;
	}


	string countAndSay(int n) {

		string res = "1";


		for (int i = 0; i < n - 1; i++) {
			res = build(res);
		}

		return res;



	}
};

// t.c. = O(n*(2^n)) => every iteration, string length doubles so the time requires to traverse the res and we are doing it n times so n*2^n.
// s.c. = O(2^n) => as string size doubles so the space to store it.