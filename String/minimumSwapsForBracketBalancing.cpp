// (swapping only adjacent) greedy. we will traverse from left to right. if we encounter opening bracket, we will check is there any unpaired
// closing brackets if there are then balanece will be -ve and we will try to form a pair with one of those closing bracket with the
// current opening bracket, if there are three unpaired closing brackets then we will have to swap this opening bracket three times to paired
// it with the leftmost closing bracket and having remaining unpaired closing bracket ahead of them so we can balance them in the future.
//  so we will add abs(balance) i.e. no. of unpaired closing brackets and we will increment balance by 1.
// if it is a closing bracket we will simply decrement balance by 1.
// In the end entire brackets will be balanced because there are n/2 opening brackets and n/2 closing brackets and minimum number of swaps
// required to make them balance is stored in ans.

class Solution {
public:
	int minimumNumberOfSwaps(string S) {
		// code here

		int n = S.size();

		int balance = 0, ans = 0;

		for (int i = 0; i < n; i++) {

			if (S[i] == '[') {
				if (balance < 0) {
					ans += abs(balance);
				}
				balance++;
			} else {

				balance--;
			}
		}

		return ans;

	}
};

// t.c. = O(N)
// s.c. = O(1)


// (swapping any brackets) greedy. first we observe that all the unpaired closing brackets will lie on lhs and all unpaired
// opening brackets lie on rhs. now after calculating the number of unpaired closing brackets we have to multiply it by 2
// to get total unpaired brackets (opening as well) , now we see that in optimal swapping each swap balances 4 brackets
// so we will divide total unpaired brackets by 4 and take its ceil value.

// we will keep balance variable which tracks the no. of opening brackets and cl which tracks number of unpaired closing brackets
// now when we encounter a opening bracket we will increment balance by 1, and when it is closing bracket we will check if balance
// is > 0, if it is then this closing bracket can form pair with some opening bracket and we decrement the balance by 1, else if
// balance == 0 that means there is no opening bracket present to form any pair so we increment cl by 1.

class Solution {
public:
	int minSwaps(string s) {


		int cl = 0, balance = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[') balance++;
			else {

				if (balance) {
					balance--;
				} else {
					cl++;
				}
			}
		}



		return ceil(cl * 2 / 4.0);

	}
};


// t.c. = O(N)
// s.c. = O(1)