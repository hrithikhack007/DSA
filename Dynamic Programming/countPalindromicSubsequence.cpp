// dp[i][j] represents the number of ways I can make palindromic subsequences using substring i,j.
// g means substring length.
// base cases: if g == 1 then dp[i][j] = 1 , if g==2 then if s[i]==s[j] then dp[i][j] = 3 else dp[i][j] = 2.
// else if g>=3, now number of ways without considering the ith character i.e. dp[i+1][j], number of ways without considering the jth
// character i.e. dp[i][j-1] add this ways, also number of ways without considering both ith and jth character i.e. dp[i+1][j-1] is being
// counted twice once in dp[i+1][j] and dp[i][j-1] so subtract it once i.e. already = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]. now this already
// doesn't count number of ways in which both ith and jth character is present so now we will first check if s[i]==s[j] if they are then
// they itself form a palindromic subsequence and also they will act as exrtremes in the palindromic subsequenes formed without considering
// ith and jth character i.e. dp[i+1][j-1] so newWays = 1 + dp[i+1][j-1].
// so total ways in which we can form palindromic subsequences using substring i,j is dp[i][j] = already + newWays.


class Solution {
public:
#define ll long long
    ll mod = (ll)(1e9 + 7);

    ll add(ll a, ll b) {

        return ((a % mod) + (b % mod)) % mod;
    }

    ll mul(ll a, ll b) {

        return ((a % mod) * (b % mod)) % mod;
    }

    ll sub(ll a, ll b) {

        return ((a % mod) - (b % mod) + mod) % mod;
    }

    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        int n = str.size();

        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));

        for (int g = 1; g <= n; g++) {

            for (int i = 0; i + g - 1 < n; i++) {

                int j = i + g - 1;

                if (g == 1) {
                    dp[i][j] = 1;
                } else if (g == 2) {
                    dp[i][j] = str[i] == str[j] ? 3 : 2;
                } else {

                    ll already = sub(add(dp[i + 1][j], dp[i][j - 1]), dp[i + 1][j - 1]);
                    ll newWays = 0;
                    if (str[i] == str[j]) {
                        newWays = add(1, dp[i + 1][j - 1]);
                    }

                    dp[i][j] = add(already, newWays);
                }

            }
        }

        return dp[0][n - 1];

    }

};


// t.c. = O(N*N)
// s.c. = O(N*N)