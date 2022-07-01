// overkill 3-d recursive dp. there will be 3 states: idx,status and available. if status = 0 that means we can buy as no active transactions going
// on else we need to look for sell. if s==0 and avail(means we didnt make >=2 transactions) for every idx we can either buy that stock or skip
// it. we will choose that one which will give us maximum profit. Also the value returned at buying call we be profit + s.p. like (10 + 30)
// where 10 is the s.p that this stock was sold and 30 is the overall profit till that call. then total profit now will be (10-c.p) + 30
//           s.p   profit                (buying value)
// basically (10 + 30)(returned value) - c.p .

// if s==1 that means we can either sell the stock here or skip it. we will take the maximum from both of them. the value will be returned here
// will be the overall profit of future transactions so if we are selling here then we will return s.p(current value) + profit(returned value).

class Solution {
public:

	int dp[100001][2][3];

	int rec(int idx, int s, int avail, vector<int> &prices) {

		if (idx == prices.size()) return 0;


		if (dp[idx][s][avail] != -1) return dp[idx][s][avail];

		int profit1 = 0, profit2 = 0;


		if (s == 0 && avail) {

			profit1 = max(rec(idx + 1, 1, avail - 1, prices) - prices[idx] , rec(idx + 1, 0, avail, prices));

		} else if (s == 1) {

			profit2 = max(prices[idx] + rec(idx + 1, 0, avail, prices), rec(idx + 1, 1, avail, prices));
		}

		return dp[idx][s][avail] = max(profit1, profit2);

	}

	int maxProfit(vector<int>& prices) {

		for (int i = 0; i <= prices.size(); i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k <= 2; k++) {
					dp[i][j][k] = -1;
				}
			}
		}

		return rec(0, 0, 2, prices);



	}
};


// t.c. = O(N*2*3)
// s.c. = O(N*2*3)


// more readable code with some changes. we will have 3 parametrs day,buy and cap. if we buy is 1 then we can buy on that day.
// we can either buy or skip buying on that day. if we buy then price of that day will be dedecuted from our account so we will do
// -price[day] and make call on the next day where we will set buy to be 0, or we can just call on next day keeping other parameters same.
// if we it is a selling day then we can either sell it or just skip selling on that day. if we are selling then that much price of that
// day will be added to our account (+price[day]) and make a call on next day by setting buy to 0 and decrementing the cap by 1.
// if cap becomes 0 or we reach the end of the days we will return 0 as we can't make any profit.

class Solution {
public:

	int dp[100005][2][3];

	int rec(int day, int buy, int cap, vector<int> &prices) {

		if (cap == 0) return 0;
		if (day == prices.size()) return 0;

		if (dp[day][buy][cap] != -1) return dp[day][buy][cap];

		if (buy) {

			return dp[day][buy][cap] = max(-prices[day] + rec(day + 1, 0, cap, prices) , rec(day + 1, 1, cap, prices));
		} else {

			return  dp[day][buy][cap] = max(prices[day]  + rec(day + 1, 1, cap - 1, prices) , rec(day + 1, 0, cap, prices));
		}

	}


	int maxProfit(vector<int>& prices) {


		for (int i = 0; i <= prices.size(); i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k <= 2; k++) {
					dp[i][j][k] = -1;
				}
			}
		}

		return rec(0, 1, 2, prices);

	}
};

// t.c. = O(N*2*3)
// s.c. = O(N*2*3)


// tabulation. just refer the memoized solution and reverse the order of parameters handle the base cases similarly.

class Solution
{
public:



	int maxProfit(vector<int> &prices)
	{

		int n = prices.size();

		vector<vector<vector< int>>> dp(n + 1, vector<vector < int>> (2, vector<int> (3, 0)));

		for (int day = n - 1; day >= 0; day--)
		{
			for (int buy = 0; buy < 2; buy++)
			{
				for (int cap = 1; cap < 3; cap++)
				{

					if (buy)
					{

						dp[day][buy][cap] = max(-prices[day] + dp[day + 1][0][cap], dp[day + 1][1][cap]);
					}
					else
					{

						dp[day][buy][cap] = max(prices[day] + dp[day + 1][1][cap - 1], dp[day + 1][0][cap]);
					}
				}
			}
		}

		return dp[0][1][2];
	}
};

// t.c. = O(N*2*3)
// s.c. = O(N*2*3)

// space optimisatipn. we are just checking one forward state so we can remove the state day. we will use curr and after arrays in which
// curr will store the current state answers whereas after will hold the answer of the state just after the curr. so we can easily
// calculate the current state by using already calculated state just after this state from after array.

class Solution
{
public:



	int maxProfit(vector<int> &prices)
	{

		int n = prices.size();

		vector<vector < int>>  curr(2, vector<int> (3, 0));
		vector<vector < int>>  after(2, vector<int> (3, 0));



		for (int day = n - 1; day >= 0; day--)
		{
			for (int buy = 0; buy < 2; buy++)
			{
				for (int cap = 1; cap < 3; cap++)
				{

					if (buy)
					{

						curr[buy][cap] = max(-prices[day] + after[0][cap], after[1][cap]);
					}
					else
					{

						curr[buy][cap] = max(prices[day] + after[1][cap - 1], after[0][cap]);
					}
				}
			}

			after = curr;
		}

		return after[1][2];
	}
};

// t.c. = O(N*2*3)
// s.c. = O(1)

// using operation numbers to keep track of buy and sell as well as capacity. basically at max we can perform 2 transactions like
// B S B S
// 0 1 2 3

// so by numbering the operations this way, we can say whenever the number is even then it is a buy call else it is a sell call.
// if num becomes 4 that means we have performed 2 transactions.

class Solution {
public:

	int rec(int day, int num, vector<int> &prices, vector<vector<int>> &dp) {

		if (num == 4 || day == prices.size()) return 0;

		if (dp[day][num] != -1) return dp[day][num];

		if (!(num & 1)) {

			return dp[day][num] =  max(-prices[day] + rec(day + 1, num + 1, prices, dp), rec(day + 1, num, prices, dp));
		} else {
			return dp[day][num] = max(prices[day] + rec(day + 1, num + 1, prices, dp), rec(day + 1, num, prices, dp));
		}

	}


	int maxProfit(vector<int>& prices) {

		vector<vector<int>> dp(prices.size(), vector<int>(4, -1));

		return rec(0, 0, prices, dp);

	}
};

// t.c. = O(N*4)
// s.c. = O(N*4)


// tabulation. just reverse the ordering of parameters compared to memoization and handle the based cases same as memo.
class Solution {
public:


	int maxProfit(vector<int>& prices) {

		int n = prices.size();

		vector<vector<int>> dp(n + 1, vector<int>(5, 0));

		for (int day = n - 1; day >= 0; day--) {

			for (int num = 3; num >= 0; num--) {

				if (!(num & 1)) {

					dp[day][num] =  max(-prices[day] + dp[day + 1][num + 1], dp[day + 1][num]);
				} else {
					dp[day][num] = max(prices[day] + dp[day + 1][num + 1], dp[day + 1][num]);
				}

			}
		}




		return dp[0][0];

	}
};

// t.c. = O(N*4)
// s.c. = O(N*4)


// space optimizaion. as only one forward state is used to calculate the curr state we can use curr and after arrays to keep track of
// curr and next state respectively. curr will store the current state with the help of next state and then assign curr to after so now
// we will use the calculated value stored in after array to calculate the state in next transition.

class Solution {
public:


	int maxProfit(vector<int>& prices) {

		int n = prices.size();

		vector<int> curr(5, 0);
		vector<int> after(5, 0);

		for (int day = n - 1; day >= 0; day--) {

			for (int num = 3; num >= 0; num--) {

				if (!(num & 1)) {

					curr[num] =  max(-prices[day] + after[num + 1], after[num]);
				} else {
					curr[num] = max(prices[day] + after[num + 1], after[num]);
				}

			}

			after = curr;
		}




		return after[0];

	}
};


// t.c. = O(N*4)
// s.c. = O(1)

