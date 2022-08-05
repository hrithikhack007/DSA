// iterative.
// it is just the variation of coin change.
// we want distinct combination so we will go coin by coin i.e. with the first coin we will try to form all the sum, then we go to second
// coin and with that we will try to form all the sums and so on.
// so we will start from score=0 to 2 as there are 3 possible scores.
// now for each score we will start from sum = scores[score] to n because sum must be atleast scores[score] then for each sum we will
// add dp[sum-scores[sum]] i.e. we will take scores[sum] and then what is the number of ways to form remaining sum we will add so in that
// ways if we add scores[score] we will get no. of ways to form sum.


#define ll long long

long long int count(long long int n)
{

    vector<ll> scores = {3, 5, 10};

    vector<ll> dp(n + 1, 0);

    dp[0] = 1;

    for (int score = 0; score < 3; score++) {

        for (int sum = scores[score]; sum <= n; sum++) {

            dp[sum] += dp[sum - scores[score]];
        }

    }

    return dp[n];

}

// t.c. = O(3*N) = O(N)
// s.c. = O(N)