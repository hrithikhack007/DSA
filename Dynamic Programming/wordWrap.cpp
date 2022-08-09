// dp[i] represents minimum total cost to write first i+1 words.
// start iterating from i=0 to n-1 and in each iteration set chs = 0 i.e. number of characters in line and set dp[i] to inf.
// now for each i start iterating from j=i to 0 and in each iteration increment chs by nums[j] and set spaceBetween to i-j i.e. the number
// of spaces in between the current words and if chs + spaceBetween > k that means this many words can't be put in a single line so break.
// now extraSpace will be k - chs - spaceBetween but if i==n-1 i.e. we are at the last word then the last word will always be put into last
// line so extraspaces in last line is always 0 so make extraspace = 0 if i==n-1.
// now calculate cost of writting this (i-j+1) words on the current line i.e. (extraspace)^2.
// now if j==0 that means all the i+1 words can be put into single line so just minimize the dp[i] with cost, else if j!=0 then we have wrote
// i-j+1 words in a single line and its cost is 'cost' so the remaining j-1+1 the cost to write those words are stored in dp[j-1]
// so minimize dp[i] with dp[j-1] + cost.


class Solution {
public:
    int solveWordWrap(vector<int>nums, int k)
    {
        int n = nums.size();

        vector<long> dp(n);

        for (int i = 0; i < n; i++) {

            int chs = 0;
            dp[i] = INT_MAX;

            for (int j = i; j >= 0; j--) {

                chs += nums[j];
                int spaceBetween = i - j;

                if (chs + spaceBetween > k) break;

                long extraSpace = k - chs - spaceBetween;
                if (i == n - 1) extraSpace = 0;

                long cost = (extraSpace * extraSpace);


                if (j == 0) dp[i] = min(dp[i], cost);
                else  dp[i] = min(dp[i], cost + dp[j - 1]);

            }

        }

        return dp[n - 1];

    }
};

// t.c. = O(N^2)
// s.c. = O(N)
