// iterative.
// dp[i] represents number of ways to dearrange i elements.
// base conditions: if n==1 return 0 or if n==2 return 1.
// else, declare dp[n+1], set dp[1]=0,dp[2]=1.
// iterate from i=3 to n and in each iteration dp[i] is (i-1)*(dp[i-1]+dp[i-2]).

// intuition: for calculating dp[i], we cannot place i on the ith position but we can place 1,2,3,....i-1 elements on ith position and for
// each element let's see how we can place ith element in the i-1 positions. first we will treat ith element as one of the i-1 elements
// so number of ways we can dearrange i-1 elements is i-1 and in that dearrangement we can place the ith element in one extra position which
// was not possible for the replaced element currently at ith position so if we place the ith element in that extra space then the remaining
// places are i-2 so and all the elements in that i-2 positions will have their respective positions so number of ways we can dearrange
// i-2 elements is dp[i-2] so this are the choices(dp[i-1]+dp[i-2]) for the ith element if we swapped it with one of the i-1 elements and we
// have (i-1) such choices so we do (i-1)*(dp[i-1]+dp[i-2]).




#include<bits/stdc++.h>

#define ll long long

ll mod = (ll)(1e9 + 7);

ll add(ll a, ll b) {

    return ((a % mod) + (b % mod)) % mod;
}

ll mul(ll a, ll b) {

    return ((a % mod) * (b % mod)) % mod;
}


long long int countDerangements(int n) {

    if (n == 1) return 0;
    if (n == 2) return 1;

    vector<ll> dp(n + 1);

    dp[1] = 0, dp[2] = 1;

    for (ll i = 3; i <= n; i++) {

        dp[i] = mul(i - 1, add(dp[i - 1], dp[i - 2]));

    }

    return dp[n];


}

// t.c. = O(N)
// s.c. = O(N)


// space optimized.

#include<bits/stdc++.h>

#define ll long long

ll mod = (ll)(1e9 + 7);

ll add(ll a, ll b) {

    return ((a % mod) + (b % mod)) % mod;
}

ll mul(ll a, ll b) {

    return ((a % mod) * (b % mod)) % mod;
}


long long int countDerangements(int n) {

    if (n == 1) return 0;
    if (n == 2) return 1;

    ll prev = 1, sprev = 0;

    for (ll i = 3; i <= n; i++) {

        ll curr = mul(i - 1, add(prev, sprev));
        sprev = prev;
        prev = curr;

    }

    return prev;


}

// t.c. = O(N)
// s.c. = O(1)