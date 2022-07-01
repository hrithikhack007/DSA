// greedy. take a variable mini and at every i minimize so that we can buy at minimum price and maximize the profit by selling the stock at that
// i.

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int mini = INT_MAX , profit = 0;

		for (int i = 0; i < prices.size(); i++) {

			mini = min(mini, prices[i]);
			profit = max(profit, prices[i] - mini);

		}

		return profit;

	}
};

// t.c = O(N)
// s.c. = O(1)