// first we will do a pre-computation where for every word we will mark the substring of s which is equal to that word as true in present
// 2-d boolean array i.e. if word leet is present as substring in s at 3,6 then present[3][6] will be true.
// dp[i] represents if we can break the sentence of length i into valid dictionary words.
// set dp[0] = present[0][0]. iterate from i=0 to n-1, and for each i iterate j from i to 1 and in each iteration check if substring
// j,i is present in dict. and the remaining part of sentence i.e. j-1 can be break into valid words then dp[i] is true so if it is then
// break else continue.
// after the completion of inner loop if dp[i] is true then ok but if it is not then check if the complete sentence of length i is a valid
// word or not i.e. if it is present in dict. then also dp[i] is true.



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        vector<vector<bool>> present(n, vector<bool>(n, false));


        for (auto word : wordDict) {

            int sz = word.size();

            for (int i = 0; i <= n - sz; i++) {

                if (s.substr(i, sz) == word) {
                    present[i][i + sz - 1] = true;
                }
            }

        }


        vector<bool> dp(n, false);

        dp[0] = present[0][0];

        for (int i = 1; i < n; i++) {

            for (int j = i; j >= 1; j--) {

                dp[i] = present[j][i] && dp[j - 1];

                if (dp[i]) break;
            }

            dp[i] = dp[i] || present[0][i];

        }

        return dp[n - 1];


    }
};

// t.c. = O((L*(N-L))*K) pre computation where L is the average length of words and K is the number of words and N is the length of the
// string s, O(N*N) = O(N^2) for dp so total time is O((L*(N-L))*K) + O(N^2).
// s.c. = O(N^2) + O(N)

// space optimized with more time.
// save all the words in mp. and instead of using present array directly check the substring in the map if it is present or not.



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        unordered_map<string, bool> mp;

        for (auto word : wordDict) {
            mp[word] = true;
        }


        vector<bool> dp(n, false);

        dp[0] = mp[s.substr(0, 1)];

        for (int i = 1; i < n; i++) {

            for (int j = i; j >= 1; j--) {

                dp[i] = mp[s.substr(j, i - j + 1)] && dp[j - 1];

                if (dp[i]) break;
            }

            dp[i] = dp[i] || mp[s.substr(0, i + 1)];

        }

        return dp[n - 1];


    }
};


// t.c. = O(N^3)
// s.c. = O(N) + O(l*K) where l is the average length of word and K is the number of words in dict.