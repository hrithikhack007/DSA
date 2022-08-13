// for minimum cost: set mini to 0, sort the array in increasing order. set l = 0 and r to n - 1. while l<=r, in each iteration buy the
// lth candy and add it cost to mini , then skip the r - k candies and it may cross l as well so define limit as min(r-k,l) becaue if
// r-k is less than l but we would have already considerded that part so we can stop at l.
// after this , increment l by 1.

// for maximum cost: set maxi to 0, sort the array in increasing order. set l = 0 and r to n - 1. while l<=r, in each iteration buy the
// rth candy and skip the k candies from left. after this decrement r by 1.



#include<bits/stdc++.h>
#define ll long long

long long minimumCost(vector<int> &cost, int n, int k)
{

    ll mini = 0;

    sort(cost.begin(), cost.end());

    int l = 0, r = n - 1;

    while (l <= r) {

        mini += cost[l];
        int lim = max(r - k, l);

        while (r > lim) r--;

        l++;

    }

    return mini;
}

// Function to calculate maximum cost.
long long maximumCost(vector<int> &cost, int n, int k)
{

    ll maxi = 0;

    sort(cost.begin(), cost.end());

    int l = 0, r = n - 1;

    while (l <= r) {

        maxi += cost[r];

        int lim = min(l + k, r);

        while (l < lim) l++;
        r--;
    }

    return maxi;


}


// t.c. = O(NLogN) + O(N) = O(NLogN) for each function.
// s.c. = O(1)

// efficient and concised.
// instead of iterating while skipping k candies we can simply shift the limit.
// for minimum n = n, and start iterating from i=0 till n - 1 , in each iteration buy the ith candy add its cost to minimum then
// we want to shift the k candies from right so simply do n-=k.
// for maximum n = -1, start iterating from sz-1 to n + 1, and in each iteration, buy the ith candy and its cost to maximum then
// shift the k candies from left like n += k.


class Solution
{
public:
    vector<int> candyStore(int cost[], int n, int k)
    {

        int sz = n;
        sort(cost, cost + n);
        vector<int> ans(2, 0);


        for (int i = 0; i < n; i++) {

            ans[0] += cost[i];
            n -= k;

        }

        n = -1;

        for (int i = sz - 1; i > n; i--) {

            ans[1] += cost[i];
            n += k;
        }

        return ans;



    }
};

// t.c. = O(NLogN)
// s.c. = O(1)
