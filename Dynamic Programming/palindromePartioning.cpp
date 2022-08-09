// dp[i] represents minimum cuts we need to make the valid partition for string ending at ith index.
// we will iterate from i=0 to n-1 and set dp[i] = n and if string 0,i is already a palindrome so no cuts required so set dp[i]=0 and continue,
// else try to make cuts from j=i to 1 and in each iteration check if string j,i is palindrome if it is then only make the cut at jth index
// because we want valid partition so suffix should be palindrome and the remaining string 0,j-1 minimum cuts required to partition string 0,j-1
// i.e. dp[j-1] + 1 cut at jth index we will minimize dp[i] with this i.e. dp[i] = min(dp[i],dp[j-1] + 1) only if string j,i is palindrome.

// to check if a subtring is plaindrome we will do pre - computation using gap strategy i.e starting from smaller substring to bigger string
// and if we want to know if substring i,j is palindrome or not the first s[i] and s[j] should be equal and the remaining substring i+1,j-1
// should be a palindrome and we would have already computed for the substring i+1,j-1 as it is a smaller string than i,j and if both conditions
// are satisfied then we can say that stirng i,j is also a palindrome. By doing this we will be able to tell in constant time if a substring is
// palindrome or not while calculating dp.


class Solution {
public:
    int minCut(string str) {

        int n = str.size();

        vector<int> dp(n);
        vector<vector<bool>> isPalindrome(n, vector<bool>(n));

        for (int g = 1; g <= n; g++) {

            for (int i = 0; i + g - 1 < n; i++) {

                int j = i + g - 1;

                isPalindrome[i][j] = false;

                if (g == 1) {
                    isPalindrome[i][j] = true;
                } else if (g == 2 && str[i] == str[j]) {
                    isPalindrome[i][j] = true;
                } else if (isPalindrome[i + 1][j - 1] && str[i] == str[j]) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {

            dp[i] = n;

            if (isPalindrome[0][i]) {
                dp[i] = 0;
                continue;
            }

            for (int j = i; j > 0; j--) {

                if (isPalindrome[j][i]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }



        }

        return dp[n - 1];

    }
};

// t.c. = O(N^2) + O(N^2) = O(N^2)
// s.c. = O(N^2) + O(N) = O(N^2)

// space optimization . select and expand technique.

// we will start from i=0 to n-1 and in each iteration we will try to expand the substring starting from the ith index as long as it is palindrome.
// for odd length, we will set l = i and r = i and as long as they are not out of bounds and s[l]==s[r] what we will do is we will
// minimize dp[r] with dp[l-1] + 1 if l is not 0 else if l is 0 we will directly set dp[r] as 0.
//for even length we will set l to i and to i+1, and as long as  l and r are not out of bounds and s[l]==s[r] we will expand the substring and in
// each iteration if l==0 then set dp[r] to 0 else minimize dp[r] with dp[l-1]+1.

// intuition: we know that after the valid partition each substring will be the palindrome so we are just using this fact and checking all
// palindromic substring and we are updating r because l to r is a palindrome and we would have already calculated minimum cuts for string 0,l-1
// therefore if we made a cut on l then substrig l to r will be one of the partition and if l is 0 then 0 to r itself is a palindrome so we don't
// required any cut to make valid partition.



class Solution {
public:
    int minCut(string s) {

        int n = s.size();

        vector<int> dp(n, n - 1);

        for (int i = 0; i < n; i++) {

//             odd length

            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) {

                if (l == 0) {
                    dp[r] = 0;
                } else {
                    dp[r] = min(dp[l - 1] + 1, dp[r]);
                }

            }
            // even length

            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                if (l == 0) {
                    dp[r] = 0;
                } else {
                    dp[r] = min(dp[l - 1] + 1, dp[r]);
                }
            }


        }

        return dp[n - 1];



    }
};


// t.c. = O(N^2)
// s.c. = O(N)