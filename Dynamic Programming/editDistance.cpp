// recursion + memo.

// call the rec. function by passing i=0,j=0,word1,word2 and dp as arguments. In each rec. call if i==word1.size() that means we have matched the
// first n characters of word2 and word1 doesn't have any more characters left so the remaining characters in word2 that is m - j will be appended
// in word1 so return m - j.
// else if j == word2.size() that means all the characters in word2 is matched with starting m characters of word1 but there are still some characters
// reamining in word1 so we have to delete them so return n - i.
// else, if dp[i][j] != -1 then it means it is already computed so return dp[i][j],
// else if word1[i] == word2[j] then ith and jth character are already matching so don't need to perform any operation simply call on next characters
// i.e. rec(i+1,j+1) and whatever it returns store in dp[i][j] and return it.
// else if ith and jth characters are not matching then for ith character we have three choices, either we can delete,replace or insert at the ith
// character. so if we delete the ith character then jth characters is still un matched so we will call on rec(i+1,j) because i is deleted and j is
// unmatched or if we replace the ith character with jth character then both ith and jth character matches so call on rec(i+1,j+1) or if we want
// to insert the jth character we will insert it before ith character so jth character matches with the newly inserted character but ith character
// is still un matched so we will call on rec(i,j+1) and from these three choices whichever returns minimum we will take it and add 1 in it for
// performing the operation and store it in dp[i][j] and return it.

class Solution {
public:

//     greedy fails on truck and tuckle using two pointers.

    int rec(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {

        if (i == word1.size()) {

            return word2.size() - j;
        }

        if (j == word2.size()) {
            return word1.size() - i;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = rec(i + 1, j + 1, word1, word2, dp);
        } else {

            return dp[i][j] = min({rec(i + 1, j, word1, word2, dp), rec(i + 1, j + 1, word1, word2, dp), rec(i, j + 1, word1, word2, dp)}) + 1;
        }
    }


    int minDistance(string word1, string word2) {

        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return rec(0, 0, word1, word2, dp);


    }
};

// t.c. = O(N*M)
// s.c. = O(N*M) + O(min(N,M))(stack space)

// iterative.
// just reverse the order of evaluation as compared to recursion like we were calling rec. function from i=0 to n and j = 0 to m so in iterative
// we will start from i=n to 0 and j = m to 0.
// base conditions and transitions remains same exactly the same as recursion.
// final answer will be in dp[0][0] -> minimum operations we have to perform to convert string word1 from 0 to n - 1 equals to string word2 from
// 0 to m - 1.



class Solution {
public:


    int minDistance(string word1, string word2) {

        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n; i >= 0; i--) {

            for (int j = m; j >= 0; j--) {

                if (i == n) {
                    dp[i][j] = m - j;
                } else if (j == m) {
                    dp[i][j] = n - i;
                } else {

                    if (word1[i] == word2[j]) {
                        dp[i][j] = dp[i + 1][j + 1];
                    } else {
                        dp[i][j] = min({dp[i + 1][j], dp[i + 1][j + 1], dp[i][j + 1]}) + 1;
                    }
                }
            }
        }

        return dp[0][0];


    }
};

// t.c. = O(N*M)
// s.c. = O(N*M)


// space optimized.
// for calculating the current or ith state row we are just using i+1th row so we don't need all the rows from i+1 to nth row so we can just have
// two rows curr and prev of size m+1 in which curr will store the current state with the help of prev row that we have already calculated and
// after computation of curr row it will become prev for the evaluation of next state.
// after the computation of final row i.e. 0th row we will asssign it to prev so our ans was dp[0][0] so now it will be prev[0].

class Solution {
public:


    int minDistance(string word1, string word2) {

        int n = word1.size(), m = word2.size();

        vector<int> curr(m + 1, 0);
        vector<int> prev(m + 1, 0);

        for (int i = n; i >= 0; i--) {

            for (int j = m; j >= 0; j--) {

                if (i == n) {
                    curr[j] = m - j;
                } else if (j == m) {
                    curr[j] = n - i;
                } else {

                    if (word1[i] == word2[j]) {
                        curr[j] = prev[j + 1];
                    } else {
                        curr[j] = min({prev[j], prev[j + 1], curr[j + 1]}) + 1;
                    }
                }
            }

            prev = curr;
        }

        return prev[0];


    }
};

// t.c. = O(N*M)
// s.c. = O(M)