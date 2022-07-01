// ad-hoc. only two combination are possible for binary string to be alternating either starting from 0 or 1. so check for both i.e.
// minimum flips required to make binary string alternative starting with 0 or 1. if index is even and s[i]=1 || index is odd and s[i]=0
// then to make type0 string we have to flip the character so we increase the cnt1 similary we can check of type1 string and increment
// cnt2 accordingly.


int minFlips (string S)
{
	// your code here

	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < S.size(); i++) {

		if ((S[i] == '0' && i % 2 == 1) || (S[i] == '1' && i % 2 == 0)) cnt1++;
		if ((S[i] == '0' && i % 2 == 0) || (S[i] == '1' && i % 2 == 1)) cnt2++;

	}

	return min(cnt1, cnt2);


}

// t.c. = O(N)
// s.c. = O(1)