// declare a dp[n+1] with all -1. dp[i] states the maximum valid segments we can get after cutting segment of size i.
// put x,y and z in a vector named cuts i.e. the choice of cuts we have for each ith size segment.
// for each i, we have three choices of cuts, now i should be >= cut else we cannot cut it and also after cutting the segment will be of size
// i-cut so i-cut size segment should such that we can cut it into size x,y, or z i.e. it should not be -1.
// if the above two conditons are satisfied then we can cut the i size segment with 'cut' so there will be a new segment of size cut and the remaining
// one i.e. i-cut size segment for which we already have calculated the ans in dp[i-cut] so that ans + 1 extra segment with this we will try to
// maximize the dp[i] and whichever cut gives the maximum and we will store it in dp[i].

// edge case: if dp[n]==-1 then we cannot cut the segment in size x,y, or z so return 0 else return dp[n].


class Solution
{
public:
  //Function to find the maximum number of cuts.
  int maximizeTheCuts(int n, int x, int y, int z)
  {

    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    vector<int> cuts = {x, y, z};

    for (int i = 1; i <= n; i++) {

      for (auto cut : cuts) {

        if (i >= cut && dp[i - cut] != -1) {
          dp[i] = max(dp[i], dp[i - cut] + 1);
        }
      }
    }

    if (dp[n] == -1) return dp[0];

    return dp[n];


  }
};

// t.c. = O(3*N) = O(N)
// s.c. = O(N)