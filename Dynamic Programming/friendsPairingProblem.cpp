// iterative.
// dp[i] stores the number of ways we can form pair or remain single if there are i people.
// now set dp[1] = 1 and dp[2] = 2.
// now run loop from i=3 to n, and for each i we can make i to remain single let's say there are dp[i-1] ways to make pair or remain single for
// i-1 people so in all of those ways we will simply make ith person to remain single so add dp[i-1]. but if we want to make pair with the ith
// person we have i-1 choices for e.g. 4th person can be paired up with 1st person,2nd person and 3rd person. so 4-1 choices. so let's say 4th person
// made pair with 1st person so the remaining person are 2 and 3 i.e. 2 people so in how many ways these 2 people can form combination we will add it
// i.e. (1,4) and dp[4-2](for 2nd and 3rd person), similarly if we paired up 4th person with 2nd person then again 4-2 = 2 people remains and in how
// many ways these 2 people can form combination i.e. dp[2] we will add i.e. (2,4) and dp[2] so there are 3 choices so we have to add dp[i-2] 3 times
// i.e. if we are at i then we have to add i-1 times dp[i-2] that gives us (i-1)*(dp[i-2]).
// basically if nth person is forming a pair with someone then the remaining people are n-2 so in how many ways those n-2 people can form combination
// and how many ways nth person can paired up i.e. n-1 so dp[n] = (n-1)*(dp[n-2]). take it under mod to avoid overflow.



class Solution
{
public:

#define ll long long
    ll mod = (ll)(1e9 + 7);

    int countFriendsPairings(int n)
    {

        vector<ll> dp(n + 1);

        dp[1] = 1, dp[2] = 2;

        for (ll i = 3; i <= n; i++) {

            dp[i] = (dp[i - 1] % mod + ((i - 1) % mod * dp[i - 2] % mod) % mod) % mod;
        }

        return dp[n];

    }
};

// t.c. = O(N)
// s.c. = O(N)

// space optimized.
// edge cases: if n<=2 return n.
// else, set second prev to 1 and prev to 2 i.e. basically dp[1] and dp[2] respectively.
// now run a loop from i = 3 to n, in each iteration, curr will act as dp[i] so curr = prev + (i-1)*(sprev);
// now for the next state curr will act as the prev and prev will act as the sprev.
// so first set sprev to prev and prev to curr.
// after the calculation of the nth state it will be stored in prev so return prev.



class Solution
{
public:

#define ll long long
    ll mod = (ll)(1e9 + 7);

    int countFriendsPairings(int n)
    {

        if (n == 1 || n == 2) return n;

        ll sprev = 1, prev = 2;

        for (ll i = 3; i <= n; i++) {


            ll curr = (prev % mod + ((i - 1) % mod * sprev % mod) % mod) % mod;
            sprev = prev;
            prev = curr;

        }

        return prev;




    }
};

// t.c. = O(N)
// s.c. = O(1)
