// brute force. we will check every proper prefix with proper suffix of its size and if they're equal we will maximize the length.

class Solution {
public:
	int lps(string s) {
		// Your code goes here

		int maxi = 0, n = s.size();

		for (int i = 0; i < n - 1; i++) {

			if (s.substr(0, i + 1) == s.substr(n - (i + 1), i + 1)) {
				maxi = max(maxi, i + 1);
			}

		}

		return maxi;


	}
};


// t.c. = O(N^2)
// s.c. = O(1)


// kmp algo. we define a pi array , where pi[i] stores the maximum length of proper prefix which is also a suffix in a substring of s
// from 0 to i.
//                                                                                                   0 1 2 3 4 5 6
// first observation. if s[pi[i-1]] == s[i] then pi[i] = pi[i-1]+1. let's consider an example of s = a b c b a b c

// let's say proper prefix which is also a suffix as good prefix.

// let's say we have calculated till i=4 and pi[4] = 1. that means maximum length of good prefix in substring 0 to 4 is 1. that means
// first 1 character is matching with last 1 character. so now we are at i=5 and noticed that pi[i-1]=1 and s[1] == s[5] so
// we know that s[0] = s[4] from pi[i-1] and now s[1] = s[5] that's why now first two characters are matching with last 2 charcters
// in a subtring from 0 to i=5. that's why we assign pi[i]=pi[i-1]+1. basically if pi[i-1] is x then starting x characters matched with
// last x characters in a subtring from 0 to i-1 so we will check can we increase the matching character by comparing the next
// character x+1th character with ith character if it matched then the good prefix length increases by 1 because we find one more
// matching character.

// also pi[i]<=pi[i-1]+1 (always)

// if the above condition is false, then we will take a j from pi[i-1] - 1 because we know that pi[i] wil  be <= pi[i-1] + 1
// and we have checked the pi[i-1] with ith so now the pi[i] will be <= pi[i-1]. so we will check ith character starting from
// j = pi[i-1]-1. now let's take an example:

//      0 1 2 3 4   5 6 7 8 9  10
// s = (a b c a b) (a b c a b) c
//pi=   0 0 0 1 2   1 2 3 4 5  3
//              j1           i

//  now we are at j = 4. here substring s0 <-> s4 and substring s5 <-> s9 are matching because we jump from pi[i-1]-1.
// where pi[i-1] = 5 meaning starting 5 characters were matching with last 5 characters that's why we are now in the good prefix
// of i-1.

// now we will check the value of pi[j] => pi[4] which is 2 that means starting 2 characters are matching with last 2 characters
// in a substring of 0 to j=4 also we know that the last 2 charactes of the good prefix is equal to to last 2 characters of good
// suffix so, we already prove that : s0 <-> s4 = s5 <-> s9 therefore s3 <-> s4 = s8 <-> s9 also as pi[j] = 2 therefore
// s0 <-> s1 = s3 <-> s4 so we can say that 0 <-> s1 = s8 <-> s9. so now if s[pi[j]] == s[i] then s0 <-> s2 will be matched
// with s8 <-> s10 and pi[i] will be 3 and we break from the loop else we again assign j to pi[j]-1 and continue till j>=0.

class Solution {
public:
	int lps(string s) {
		// Your code goes here


		int maxi = 0, n = s.size();

		vector<int> pi(n);

		pi[0] = 0;

		for (int i = 1; i < n; i++) {

			if (s[pi[i - 1]] == s[i]) pi[i] = pi[i - 1] + 1;
			else {
				pi[i] = 0;
				int j = pi[i - 1] - 1;

				while (j >= 0) {

					if (s[pi[j]] == s[i]) {
						pi[i] = pi[j] + 1;
						break;
					} else j = pi[j] - 1;
				}

			}
		}

		return pi[n - 1];


	}
};

// t.c. = O(N)
// s.c. = O(N)

// Rabin Karp algo. we will keep lhash which will store the hash value of prefix and rhash which will store the hash value of suffix
// now we will start l from 0 and r from n-1. at each iteration, we will calculate lhash = (lash + (ch*power)%mod)%mod;
// i.e. include current char in the hash value.
// for rhash we will just multiply it with prime because as we are calculating hash in reverse order the prime will keep multiply
// towrads right side as we keep moving left. after this we will add current char in rhash. so rhash = (rhash * prime)%mod =>
// this will increase the power from r to n-1 by 1 in rhash and then rhash = (rhash + ch)%mod.

// if lhash == rhash then the current prefix is same as current suffix so we will maximize the length.

// increase the power by multiplying it with prime.
// repeat this till l<n-1

class Solution {
public:
	int lps(string s) {
		// Your code goes here


		long lhash = 0, rhash = 0, prime = 31, power = 1, mod = 1e9 + 7;


		int l = 0, r = s.size() - 1;
		int maxi = 0;

		while (l < s.size() - 1) {


			lhash = (lhash + ((s[l] - 'a' + 1) * power) % mod) % mod;
			rhash = (rhash * prime) % mod;
			rhash = (rhash + (s[r] - 'a' + 1)) % mod;


			if (lhash == rhash) {

				maxi = l + 1;
			}

			l++, r--;

			power = (power * prime) % mod;



		}

		return maxi;



	}
};

// t.c. = O(N)
// s.c. = O(1)





