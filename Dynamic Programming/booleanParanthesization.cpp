// dp[i][j][0] represents number of ways to segregate or put brackets such that expression starting from i to j results into false,
// and dp[i][j][1] results into true.
// now base condition: if expression is of 1 length so just assign 1 for the given  boolean value like if it is 'T' then dp[i][j][1]=1
// and dp[i][j][0]=0 and vice versa if is was 'F'.
// also notice that expression always starts from even index so if index i is even then start k from i+1 to j-1 basically partitioning
// expression i to j with each operands and counting number of ways.
// so for each k if s[k]=='&': a expression can be valid if and only if left side is true and right side it also true i.e. T&T
// so dp[i][j][1] += (dp[i][k-1][1]*dp[k+1][j][1]) i.e
// and for all other ways it will result into false so dp[i][j][0] += ((dp[i][k - 1][1] * dp[k + 1][j][0]) + (dp[i][k - 1][0] * dp[k + 1][j][1])
// + (dp[i][k - 1][0] * dp[k + 1][j][0]))
// if s[k]=='^': then it will result true only if left is true and right is false or left is false and right is true i.e. T^F , F^T
// so dp[i][j][1] += ((dp[i][k - 1][1] * dp[k + 1][j][0]) + (dp[i][k - 1][0] * dp[k + 1][j][1]))
// and it will be false for T^T , F^F so dp[i][j][0] += ((dp[i][k - 1][1] * dp[k + 1][j][1]) + (dp[i][k - 1][0] * dp[k + 1][j][0]))
// else if s[k]=='|': it will result into true if T|T, T|F, F|T
// so dp[i][j][1] += ((dp[i][k - 1][1] * dp[k + 1][j][1]) + (dp[i][k - 1][1] * dp[k + 1][j][0])
// + (dp[i][k - 1][0] * dp[k + 1][j][1]))
// it will result into false only if F|F so dp[i][j][0] += (dp[i][k - 1][0] * dp[k + 1][j][0])
// also take mod after calculating dp[i][j][1],dp[i][j][0] for each k.




class Solution {
public:

    int mod = (1003);

    int add(int a, int b) {

        return ((a % mod) * (b % mod)) % mod;
    }

    int mul(int a, int b) {

        return ((a % mod) * (b % mod)) % mod;
    }

    int countWays(int N, string S) {


        int dp[N][N][2];

        for (int g = 1; g <= N; g++) {

            for (int i = 0; i + g - 1 < N; i++) {

                int j = i + g - 1;

                dp[i][j][0] = dp[i][j][1] = 0;

                if (g == 1 && (i % 2 == 0)) {
                    dp[i][j][0] = (S[i] == 'F');
                    dp[i][j][1] = (S[i] == 'T');
                } else if ((i % 2 == 0)) {



                    for (int k = i + 1; k < j; k += 2) {

                        if (S[k] == '&') {

                            dp[i][j][1] += (dp[i][k - 1][1] * dp[k + 1][j][1]);
                            dp[i][j][0] += ((dp[i][k - 1][1] * dp[k + 1][j][0]) + (dp[i][k - 1][0] * dp[k + 1][j][1])
                                            + (dp[i][k - 1][0] * dp[k + 1][j][0]));



                        } else if (S[k] == '^') {

                            dp[i][j][1] += ((dp[i][k - 1][1] * dp[k + 1][j][0]) + (dp[i][k - 1][0] * dp[k + 1][j][1]));
                            dp[i][j][0] += ((dp[i][k - 1][1] * dp[k + 1][j][1]) + (dp[i][k - 1][0] * dp[k + 1][j][0]));



                        } else {

                            dp[i][j][1] += ((dp[i][k - 1][1] * dp[k + 1][j][1]) + (dp[i][k - 1][1] * dp[k + 1][j][0])
                                            + (dp[i][k - 1][0] * dp[k + 1][j][1]));
                            dp[i][j][0] += (dp[i][k - 1][0] * dp[k + 1][j][0]);



                        }

                        dp[i][j][1] = dp[i][j][1] % mod;
                        dp[i][j][0] = dp[i][j][0] % mod;

                    }

                }

            }

        }

        return dp[0][N - 1][1];

    }
};


// t.c. = O(N^3)
// s.c. = O((N^2)*(2)) = O(N^2).