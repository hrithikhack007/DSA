// dp[i][j] represents the maximum coins a player can collect in the range of i to j if he goes first.
// base conditions: if l == r then  there is only one choice so dp[l][r] = arr[l] and then return,
// else if dp[l][r] != -1 that means it is already computed so return it.
// else, a player can collect the lth coin so the remaining range will be rec(l+1,r) and if he chooses rth coin the remaining range will be
// rec(l,r-1) so make calls on them.
// now if r-l==1 that means there is only two coins so the player will always select the maximum of two so dp[l][r] = max(arr[l],arr[r]) and return.
// else , now if a player chooses lth coin then the range becomes (l+1,r) and in that range the opponent will make the choice and that opponent
// also will have two choices i.e. to choose l+1th coin or rth coin and if he chooses l+1th coin the remaining range will be l+2,r and in that
// range a player will make the decision and it is already computed so that will be the maximum coins a player can collect in the range l+2,r
// i.e. dp[l+2][r] and opponent can choose rth coin in that case range will be l+1,r-1 and maximum coin in that range a player can collect is
// dp[l+1][r-1] so as the opponent will also tries to maximize its own profit he will choose that choice in which a player makes less profit
// so automatically profit of opponent will increase so opponent will choose min(dp[l+2][r],dp[l+1][r-1]) choice so if a player is at l,r
// then if he chooses lth coin then the maximum profit he can get is arr[l] + min(dp[l+1][r],dp[l+1][r-1]) and if he chooses rth coin then
// the range will become l,r-1 and similarly as the above case opponent will have choice in this range and he will select that choice in which
// player gets minimum coins so if player selects rth coin then the maximum profit he can get is arr[r] + min(dp[l+1][r-1],dp[l][r-2])
// and the player will choose the maximum of this two choices i.e.
// dp[l][r] = max(arr[l]+min(dp[l+2][r],dp[l+1][r-1]),arr[r]+min(dp[l+1][r-1],dp[l][r-2]));

// proof: so let's say player is at l,r range and he has two choices if he selects lth coin the range will become l+1,r and in that range the
// opponent will try to choose its move so he will choose that move in which he gets maximum profit. Let's say the sum of coins in the range
// l+1,r is 200 and if the opponent selects l+1th coin then the range becomes l+2,r and in this range player will decide the first move and
// the maximum profit the player can earn in this range will already be calculated let's say dp[l+2][r] = 100, so  from the 200 rs player will
// earn 100 rs if the opponent selects the l+1th coin so the profit opponent will get is 200-100 = 100 and 100=arr[l+1] + profit earned by opponent
// in the range l+2,r. and let's say the opponent selects the rth coin then the range will become l+1,r-1 and in this range the maximum profit
// a player can make by making the first move is dp[l+1][r-1] let's say it is 50 so the remaining sum is 200-150 is the profit earned by opponent
// in the range l+1,r if he selects rth coin i.e. 150 = arr[r] + profit made by opponent in the range l+1,r-1.  so we can see that if the opponent
// chooses that choice in which the player is making less profit then  it will result in maximum profit for the opponet that is why while
// checking for l,r state we always consider min(dp[l+2][r],dp[l+1][r-1]) and min(dp[l+1][r-1],dp[l][r-2]) because in that range opponent is making
// choices and he will always select the choice in which player is getting minimum so we consider that values only while making the choice for
// l and rth coins.


class Solution {
public:

#define ll long long

    ll rec(ll l, ll r, int arr[], vector<vector<ll>> &dp) {


        if (l == r) {

            return dp[l][r] = arr[l];

        }


        if (dp[l][r] != -1) return dp[l][r];

        rec(l + 1, r, arr, dp);
        rec(l, r - 1, arr, dp);

        if (r - l == 1) {
            return dp[l][r] = max(arr[l], arr[r]);

        }

        return dp[l][r] = max(arr[l] + min(dp[l + 2][r], dp[l + 1][r - 1]), arr[r] + min(dp[l + 1][r - 1], dp[l][r - 2]));


    }


    long long maximumAmount(int arr[], int n) {

        vector<vector<ll>> dp(n, vector<ll>(n, -1));

        return rec(0, n - 1, arr, dp);

    }
};

// t.c. = O(N^2)
// s.c. = O(N^2) + O(N)(stack space).


// iterative. using gap strategy.
// we can see that first subarrays of size 1 is calculated then of size 2 and so on till size n. that is first we are computing smaller ans
// and then using them to calculate larger ans.
// base conditions and recurrence will remain exactly the same.

class Solution {
public:

#define ll long long

    long long maximumAmount(int arr[], int n) {

        vector<vector<ll>> dp(n, vector<ll>(n, -1));



        for (int g = 1; g <= n; g++) {

            for (int l = 0; l + g - 1 < n; l++) {

                int r = l + g - 1;

                if (g == 1) {

                    dp[l][r] = arr[l];
                } else if (g == 2) {
                    dp[l][r] = max(arr[l], arr[r]);
                } else {

                    dp[l][r] = max(arr[l] + min(dp[l + 2][r], dp[l + 1][r - 1]), arr[r] + min(dp[l + 1][r - 1], dp[l][r - 2]));

                }
            }
        }


        return dp[0][n - 1];



    }
};

// t.c. = O(N^2)
// s.c. = O(N^2)




