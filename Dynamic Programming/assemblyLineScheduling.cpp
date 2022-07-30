// recursion + memo.
// we can start from line 0 or line 1 so we will call rec. two times , in first call we will start in line 0 so we will pass idx=0,a,t,x,line=0 and dp
// as arguments and also add e[0] in it as an entry time and in second call we will start from line 1 so we will pass idx=0,a,t,x,line=1 and dp
// as arguments and also add e[1] i.e. entry time for line 1.
// now in each rec. call if we are at the last station then we will simply add time for that station i.e. a[line][idx] and exit time for that line
// i.e. x[line] so we return a[line][idx] + x[line], else if dp[idx][line] is already computed we will return it.
// set change and notChange to 0, if we are changing the line then first we will add time required by the current station in this line + time required
// to change from current line to next line and then call on rec(idx+1,(line^1)) and assign this to change i.e. t[line][idx+1] + a[line][idx] +
// rec(idx+1,(line^1)) if we are changing the line, else if we are not changing then we just have to add time required at current station in current
// line and call on rec(idx+1,line) i.e. rec(idx+1,line) + a[line][idx] and assign it to noChange i.e. if we are not chaning the line from this
// current station and whichever returns minimum we will store that in our dp[idx][line] and return it.
// also in the main function we will take the minimum from both first call and second call i.e. minimum time required if we start from 0th line
// or if we start from 1st line.
// changing parameters are idx and line , idx can be upto a[line].size() i.e. n stations and there are two lines so dp[n][2] will be the dimensions
// of dp.


class Solution {
public:

#define ll long long

  ll rec(int idx, vector<vector<int>> &a, vector<vector<int>> &T, vector<int> &x, int line, vector<vector<ll>> &dp) {

    if (idx == a[line].size() - 1) {
      return a[line][idx] + x[line];
    }

    if (dp[idx][line] != -1) return dp[idx][line];

    ll change = 0, noChange = 0;

    change = rec(idx + 1, a, T, x, (line ^ 1), dp) + T[line][idx + 1] + a[line][idx];

    noChange = rec(idx + 1, a, T, x, line, dp) + a[line][idx];

    return dp[idx][line] = min(change, noChange);
  }

  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x) {

    vector<vector<ll>> dp(a[0].size() + 1, vector<ll>(2, -1));

    return min(rec(0, a, T, x, 0, dp) + e[0], rec(0, a, T, x, 1, dp) + e[1]);

  }
};


// t.c. = O(N*2) = O(N)
// s.c. = O(N*2) + O(N)(stack space)

// iterative.
// just reverse the order of evaluation as compared to recursion like in rec we were calling idx from 0 and line from 0 so in iteartive we will
// start idx from n-1 to 0 and line from 1 to 0.
// the base conditions and transitions remain exactly the same.
// dp[0][0] will store the minimum time to assemble car if we start from the 0th line and dp[0][1] will store the minimum time to assemble car if
// we start from the 1st line. but to enter 0th line we have to wait e[0] times so we will add e[0] + dp[0][0] and to enter 1st line we have to wait
// e[1] times so we will add e[1] + dp[0][1] now we will return minimum of it.


class Solution {
public:

#define ll long long

  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x) {

    vector<vector<ll>> dp(a[0].size() + 1, vector<ll>(2));

    int n = a[0].size();

    for (int idx = n - 1; idx >= 0; idx--) {

      for (int line = 1; line >= 0; line--) {

        if (idx == n - 1) {
          dp[idx][line] = a[line][idx] + x[line];
        } else {

          ll change = 0, noChange = 0;

          change = dp[idx + 1][(line ^ 1)] + T[line][idx + 1] + a[line][idx];
          noChange = dp[idx + 1][line] + a[line][idx];

          dp[idx][line] = min(change, noChange);
        }
      }
    }

    return min(dp[0][0] + e[0], dp[0][1] + e[1]);

  }
};


// t.c. = O(2*N) = O(N)
// s.c. = O(2*N) = O(N)

// space optimized.
// to calculate the current row we were just requiring the prev row so we don't need to store all the rows we can just store 2 rows curr and prev
// in which we will construct curr using prev and then this curr will act as prev for next state/row and continue.
// the final ans will be in prev i.e. after calculating 0th row we assign curr to prev so dp[0] will be now prev and dp[0][0] will be prev[0]
// and dp[0][1] will be prev[1].

class Solution {
public:

#define ll long long

  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x) {

    vector<ll> curr(2);
    vector<ll> prev(2);

    int n = a[0].size();

    for (int idx = n - 1; idx >= 0; idx--) {

      for (int line = 1; line >= 0; line--) {

        if (idx == n - 1) {
          curr[line] = a[line][idx] + x[line];
        } else {

          ll change = 0, noChange = 0;

          change = prev[(line ^ 1)] + T[line][idx + 1] + a[line][idx];
          noChange = prev[line] + a[line][idx];

          curr[line] = min(change, noChange);
        }
      }

      prev = curr;
    }

    return min(prev[0] + e[0], prev[1] + e[1]);

  }
};

// t.c. = O(2*N) = O(N)
// s.c. = O(1)

