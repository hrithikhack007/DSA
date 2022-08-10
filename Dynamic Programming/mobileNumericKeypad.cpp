class Solution {


// dp[i][j] represents number of ways to form i length numbers ending at j th number/digit.
// first we will initialize the adj. array which will store the adjacent numbers for each key in keypad.
// define dp[N+1][10] and initialize dp[1][1] with 1 , i.e. number of ways we can form 1 length number.
// start iterating from i=2 to N and in each iteration we will loop from j=0 to 9, basically to form a i length number we can end it with 0,1,2,...
//so on till 9. and then inside that loop set dp[i][j] to 0 i.e. initially there are 0 ways. then traverse the adjacent numbers of j and increment
// dp[i][j] with dp[i-1][num] here basically if let's say j is 5 and adjacent number num is 2 and i is 3 so we will check how many ways are there
// to form number of length 2 such that it ends at 2 let's say there are 3 ways so if we add 5 in those 3 ways then we will get ways to form number
// i.e. ending at 5 and of length 3 similarly we will do this for all of its adjacent numbers so after traversing all of its ajdacent numbers,
// dp[i][j] will store the number of ways we can get number of length i such that it ends at j.
// now after dp[i][j] is computed we will check if i==N if it is then simply add dp[i][j] in ways where ways will store the count of total ways
// such that we can form numbers of length N which ends at number from 0 to 9.

// edge case: a number j can be adjacent to itself so take care of it while defining adjacent numbers in array.
// because if we have a way to form number of length 2 such that it ends with 5 then we can again press 5 and form a number of length 3 ending
// at 5.



public:
#define ll long long
	long long getCount(int N)
	{
		if (N == 1) return 10;

		vector<int> adj[10] = {{8, 0}, {2, 4, 1}, {1, 3, 5, 2}, {2, 6, 3}, {1, 5, 7, 4}, {2, 4, 6, 8, 5}, {3, 5, 9, 6}, {4, 8, 7},
			{0, 5, 7, 9, 8}, {6, 8, 9}
		};

		vector<vector<ll>> dp(N + 1, vector<ll>(10));

		for (int i = 0; i < 10; i++) {

			dp[1][i] = 1;
		}

		ll ways = 0;

		for (int i = 2; i <= N; i++) {

			for (int j = 0; j < 10; j++) {

				dp[i][j] = 0;

				for (auto num : adj[j]) {

					dp[i][j] += dp[i - 1][num];
				}

				if (i == N) ways += dp[i][j];
			}

		}

		return ways;

	}


};


// t.c. = O(N*10*3) = O(N)
// s.c. = O(N*10) = O(N)


// space optimized.
// we were requiring just 1 previous state to calculate current state so instead ot taking all rows/states we can have two states prev and curr
// where we can use prev to form current state and then use that curr as new prev to calculate next states.


class Solution {


public:
#define ll long long
	long long getCount(int N)
	{
		if (N == 1) return 10;

		vector<int> adj[10] = {{8, 0}, {2, 4, 1}, {1, 3, 5, 2}, {2, 6, 3}, {1, 5, 7, 4}, {2, 4, 6, 8, 5}, {3, 5, 9, 6}, {4, 8, 7},
			{0, 5, 7, 9, 8}, {6, 8, 9}
		};

		vector<ll> curr(10), prev(10);

		for (int i = 0; i < 10; i++) {

			prev[i] = 1;
		}

		ll ways = 0;

		for (int i = 2; i <= N; i++) {

			for (int j = 0; j < 10; j++) {

				curr[j] = 0;

				for (auto num : adj[j]) {

					curr[j] += prev[num];
				}

				if (i == N) ways += curr[j];
			}

			prev = curr;

		}

		return ways;

	}


};

// t.c. = O(N*10*3) = O(N)
// s.c. = O(10) = O(1)
