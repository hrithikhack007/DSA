// greedy. mark every i as the startig point and keep incrementing j as long as you are finding non-decreasing sequence because the profit will
// might remain same or increase and stop whenever there is a decreasing slope and add the value between the j and i into profit and continue.


class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int n = prices.size();
		int profit = 0;

		for (int i = 0; i < n; i++) {

			int j = i + 1;
			int st = i, en = -1;
			while (j < n && prices[j] >= prices[j - 1]) {
				j++;
				en = j;
			}

			if (en != -1) profit += (prices[j - 1] - prices[i]);

			i = j - 1;

		}

		return profit;

	}
};

// t.c. = O(N)
// s.c. = O(1)