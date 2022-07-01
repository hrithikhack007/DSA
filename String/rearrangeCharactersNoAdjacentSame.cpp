// observation. we see that if the frequency of any character becomes > ceil(n/2.0) then we can't rearrange characters such that all adjacent
// characters are different, because the remaining gaps we need to fill between those max frequency elements will be > than the remaining
// characters available so there will be atleast one character which will be equal to its adjacent in this case we will return false else
// we return true.
#include<bits/stdc++.h>
using namespace std;


int main()
{
	//code



	int t;
	cin >> t;

	while (t--) {

		int mp[26] = {0};

		string s;
		cin >> s;
		int maxi = 0;
		int n = s.size();

		for (auto a : s) {
			mp[a - 'a']++;
			maxi = max(maxi, mp[a - 'a']);
		}

		maxi > ceil(n / 2.0) ? cout << "0" << "\n" : cout << "1" << "\n";




	}

	return 0;
}

// t.c. = O(N)
// s.c. = O(26) => O(1)


// returning the rearrange string. so first of all we will check if we can rearragne the string with no same adjacent characters by above method
// if we can't then return empty string else, we will try to place max frequency elements on the even indexes first like 2,4,6, and so on.
// since maxf <= ceil(n/2.0) it will at max take all the even positions then after that we will place all the remaining characters and
// at any instance if i becomes >= n then we will reassign it to 1 that means now we are placing characters on odd inidces.

// important edge case: there may be a chance if smaller frequency characters are placed first aftet that maxf characters is place then
// adjacent characters might become same. for e.g.  s = "baaacd", b->1, a->3 , c->1, d->1.
// b a a c a d
// _ _ _ _ _ _
// 0 1 2 3 4 5

// in the above e.g. we can see that maxf char a is placed together because it doesn't start from the 0th index so resulting in using
// odd index as well for placing all the occurences. to tackle this we will first fill maxf characters first.

// a b a c a d
// _ _ _ _ _ _
// 0 1 2 3 4 5

// this makes sure that no characters are adjacent. we can easily prove this , number of even positions is ceil(n/2.0) so as maxf is less than
// it , it can atmax occupy all the even indices and remaining elements will be start from the odd index and for every remaining element it will
// be in between maxf characters so no same adjacent will be placed.
// if maxf characters < ceil(n/2.0) then maxf char will not use all even indices therefore the next char will start from even index but in order
// to make adjacent characters same the frequency of remaining character must be >= ceil but maxf is already less than ceil(n/2.0) so no
// char can be placed such that they form same adjacent char.


class Solution
{
public:
	string reorganizeString(string s)
	{

		vector<int> mp(26, 0);
		int maxi = 0, n = s.size();
		char maxch = '?';

		for (auto a : s)
		{
			mp[a - 'a']++;
			if (mp[a - 'a'] > maxi)
			{
				maxi = mp[a - 'a'];
				maxch = a;
			}
		}

		if (maxi > ceil(n / 2.0)) return "";

		int i = 0;
		string ans(n, ' ');

		while (mp[maxch - 'a'])
		{

			ans[i] = (maxch);
			i += 2;
			mp[maxch - 'a']--;
		}

		for (char ch = 'a'; ch <= 'z'; ch++)
		{

			while (mp[ch - 'a'] > 0)
			{

				if (i >= n) i = 1;
				mp[ch - 'a']--;
				ans[i] = ch;
				i += 2;
			}
		}

		return ans;
	}
};


// t.c. = O(26 + N) => O(N)
// s.c. = O(26) => O(1)