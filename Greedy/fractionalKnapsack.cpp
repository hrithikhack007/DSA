// for each item , there is a ration of value/weight. we want this ration to be as maximum because it tells us the value
// of an item per unit of its weight. so we would like to fill our bag with those items which is having higher ratios.
// so sort the items array accoring to decreasing order of their ratios.
// set mx to 0. now run loop from i = 0 to n && W > 0, in each iteration calculate the ration of item and if W >= than the
// weight of item then take the entire item decrement W by item weight and add the value of this item in mx, else
// add its value in mx and set W to 0.

class Solution
{
public:

	static bool comp(Item a, Item b) {

		return ((double)a.value / a.weight) > ((double)b.value / b.weight);
	}

	//Function to get the maximum total value in the knapsack.
	double fractionalKnapsack(int W, Item arr[], int n)
	{

		sort(arr, arr + n, comp);

		double mx = 0;

		for (int i = 0; i < n; i++) {

			double perunit = (double)arr[i].value / arr[i].weight;

			if (W >= arr[i].weight) {
				W -= arr[i].weight;
				mx += (perunit * arr[i].weight);
			} else {
				mx += (perunit * W);
				W = 0;

			}
		}

		return mx;

	}

};

// t.c. = O(NlogN)
// s.c. = O(1)