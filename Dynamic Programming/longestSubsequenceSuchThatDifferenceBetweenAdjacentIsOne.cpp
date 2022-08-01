// declare dp[N] with all 1. dp[i] represents the length of longest valid subsequence ending at ith index/element.
// set maxi to 1. iterate i from 1 to N-1 and in each iteration loop from j = i-1 to 0 and in each iteration check if abs(A[i] - A[j]) is 1 if it is
// then we can append the ith element just after the jth element in the subsequence. so we will maximize dp[i] with dp[j] + 1 i.e. the length of
// longest valid subsequence ending at jth index + 1 for the ith element so dp[j] + 1.
// after the inner loop ends, dp[i] would have been calculated so maximize the maxi with dp[i]. as the longest subequence of the array will end at some
// ith index so this maxi will store it.


class Solution {
public:
    int longestSubsequence(int N, int A[])
    {

        vector<int> dp(N + 1, 1);

        int maxi = 1;

        for (int i = 1; i < N; i++) {

            for (int j = i - 1; j >= 0; j--) {

                if (abs(A[i] - A[j]) == 1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;



    }
};

// t.c. = O(N*N)
// s.c. = O(N)

// optimal solution.
// we can use map. and for each arr[i] we want its adjacent element to be either arr[i] - 1 or arr[i] + 1 so we will check in the
// map the longest subsequence we have found where it ends with arr[i] - 1 or arr[i] + 1 and from both choices we will choose the
// one with maximum length and update mp[arr[i]] as max(mp[choice1],mp[choice2]) + 1. and also update the maxi with this mp[arr[i]].


class Solution {
public:
    int longestSubsequence(int n, int arr[])
    {

        unordered_map<int, int> mp;

        int maxi = 1;

        for (int i = 0; i < n; i++) {

            int choice1 =  arr[i] - 1, choice2 = arr[i] + 1;

            mp[arr[i]] = max(mp[choice1], mp[choice2]) + 1;

            maxi = max(maxi, mp[arr[i]]);
        }

        return maxi;


    }
};

// t.c. = O(N)
// s.c. = O(N)
