// school math. we will represent numbers in a vector digit by digit. then we will do usual multiplication like 1*2 and store its
// result in the result vector then result * 3 then store it in result and so on till n. we will get n! factorial this way.
// the process of multiplication is regular multiplication. we will start multiplying digits of one number from rhs to lhs with one
// digit of another number. we will calculate the digit for each position in the result array by adding multiplicaion result,carry and
// prev digit at that place, also calculate carry from this. we will keep decrement position of res after each digit multiplication.
// after multiplication of all digits from one number with all digits of another number, res array will store result. we will delete
// leading zeroes and return it.

class Solution {
public:

	vector<int> mul(vector<int> &x, int a) {


		vector<int> y;

		while (a > 0) {

			y.push_back(a % 10);
			a /= 10;
		}

		reverse(y.begin(), y.end());


		int j = y.size() - 1;

		vector<int> res((int)x.size() + (int)y.size(), (int)0);

		int z = res.size() - 1;

		while (j >= 0) {


			int i = x.size() - 1, carry = 0;
			int t = z;

			while (i >= 0) {

				int val = (x[i] * y[j] + carry + res[z]);

				carry = val / 10;
				res[z] = val % 10;
				i--;
				z--;


			}

			if (carry) {
				res[z] += carry;
			}

			j--;
			z = t - 1;

		}

		reverse(res.begin(), res.end());
		if (res.back() == 0) res.pop_back();
		reverse(res.begin(), res.end());
		return res;


	}

	vector<int> factorial(int N) {
		// code here


		vector<int> ans(1, 1);

		for (int i = 2; i <= N; i++) {

			ans = mul(ans, i);

		}

		return ans;




	}
};


// t.c. = O(N^2)
// s.c. = O(1) => as we are using array to return the final ans
