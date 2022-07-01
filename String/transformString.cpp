// using unordered map and two pointers. first of all if size(a) != size(b) return -1. now keep two pointers i and j initialize to
// n-1 and m-1 respectively where n is the size(a) and m is the size(b).
// we will try to match characters in both string from end and at every iteration, if a[i]==b[j] then decrement i and j by one
// if i>=0 and a[i]!=b[j] now try to find the nearest position in lhs of i where b[j] is present and while doing so keep on incrementing
// ans and decrementing i by one because that many times we have to insert the characters in front till we didn't find b[j]==a[i].
// also keep add freq. of a[i] in the map while findind b[j].
// if i<0 that means we have some characters inserted in the starting so we will check if the b[j] is present in the map if it is
// then we don't need to do anything because it would have been inserted in the beginning already and we decrement the freq. of b[j] in
// map by 1 and decrement j by 1 else if it is not present in the map then we can't match b[j] so we return -1.


class Solution
{
public:
	int transform (string A, string B)
	{
		//code here.

		if (A.size() != B.size()) return -1;

		unordered_map<char, int> mp;
		int ans = 0;

		int i = A.size() - 1, j = B.size() - 1;

		while (j >= 0) {

			// cout<<i<<" "<<j<<"\n";

			if (i < 0) {

				if (!mp[B[j]]) return -1;
				mp[B[j]]--;
				j--;

			}
			else if (A[i] == B[j]) {
				i--, j--;
			} else {

				while (i >= 0 && A[i] != B[j]) {
					mp[A[i]]++;
					i--;
					ans++;
				}


			}

		}

		return ans;



	}
};

// t.c. = O(N)
// s.c. = O(26+26)=>O(1)
