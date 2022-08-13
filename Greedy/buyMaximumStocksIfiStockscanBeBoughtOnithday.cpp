// set maxi to 0, sort the array according to the increasing value of prices and we have to keep track of the index of the price as well so take
// a vector of vector where a[0] will be price and a[1] will be index.
// now traverse from i=0 to n-1 and in each iteration, if k>= price * index then increment maxi by index because that many stocks we can buy and then
// decrement the k by the buying price which is price * index.
// else, we can buy floor(k/price) number of stocks so increment maxi by that and k will be remain to k%price and after the ith price every price will
// be increasing only so break.

// intuition: as we want to maximize the number of stocks so we will buy cheaper stocks first because even if the index is larger but if we buy the
// costly stocks first then it might happen that with the remaining money we cannot buy more stocks which we could if we didn't bought the costlier
// stock first. for example let's say index is 5 and price is 10 and k is 30 and also there is index 4 where price is 6. so if we thought the index
// 5 is giving more stock than 4 and bought stocks at price 10 then we could buy only 30/10 = 3 stocks and k will become 0 so max we can buy is 3.
// but let's say we buy cheaper stock of price 6 first then we can buy min(30/6,4) so we can buy 4 stocks and k will become 2. so buying the cheaper
// stocks is optimal.


class Solution {
public:
  int buyMaximumProducts(int n, int k, int price[]) {

    int maxi = 0;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++) arr.push_back({price[i], i + 1});
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {

      if (k >= arr[i][0]*arr[i][1]) {

        maxi += (arr[i][1]);
        k -= (arr[i][0] * arr[i][1]);
      } else {

        maxi += (k / (arr[i][0]));
        k = k % (arr[i][0]);
        break;
      }
    }

    return maxi;

  }
};

// t.c. = O(N) + O(NLogN) + O(N) = O(NLogN)
// s.c. = O(N)

// clean and concised.

class Solution {
public:
  int buyMaximumProducts(int n, int k, int price[]) {

    int maxi = 0;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++) arr.push_back({price[i], i + 1});

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {

      maxi += min(k / arr[i][0], arr[i][1]);
      k -= (min(k / arr[i][0], arr[i][1]) * arr[i][0]);
    }

    return maxi;

  }
};
