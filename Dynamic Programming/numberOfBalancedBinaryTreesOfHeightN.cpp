// call rec. by passing n = N as argument and in each rec. call if n<=1 simply return 1 else if dp[n]!=-1 means it is already computed
// so return it.
// else we have three choices to form balance binary tree of height n that is keep one at the 0th height then the remaining height is
// n-1 so now we can keep n-1 heights on both left and right subtree of this root so difference is 0 therefore ans1 = rec(n-1)*rec(n-1),
// second choice is to keep n-1 height on left subtree and n-2 height on right subtree so height difference is 1 thefore
// ans2 = rec(n-1)*rec(n-2), third choice is to keep n-2 height on left subtree and n-1 height on right subtree then also difference is 1
// therefore ans3 = rec(n-2)*rec(n-1).
// then dp[n] will be the number of ways to form height balanced binary of height n which is sum of three choices dp[n] = ans1+ans2+ans3.




long mod = (int)(1e9 + 7);
long add(long a, long b) {

    return ((a % mod) + (b % mod)) % mod;
}

long mul(long a, long b) {

    return ((a % mod) * (b % mod)) % mod;
}

int rec(int n, vector<int> &dp) {

    if (n <= 1) return 1;

    if (dp[n] != -1) return dp[n];

    int ans1 = mul(rec(n - 1, dp), rec(n - 1, dp));
    int ans2 = mul(rec(n - 1, dp), rec(n - 2, dp));
    int ans3 = mul(rec(n - 2, dp), rec(n - 1, dp));

    return dp[n] =  add(add(ans1, ans2), ans3);


}

int countBalancedBinaryTree( int n)
{

    long N = n;

    vector<int> dp(n + 1, -1);

    return rec(N, dp);

}

// t.c. = O(N)
// s.c. = O(N) + O(N)(stack space). = O(N)

// iterative.
// just reverse the order of evaluation as compared to recursion and rest all base case as well as transitions remain same.

long mod = (int)(1e9 + 7);
long add(long a, long b) {

    return ((a % mod) + (b % mod)) % mod;
}

long mul(long a, long b) {

    return ((a % mod) * (b % mod)) % mod;
}


int countBalancedBinaryTree( int n)
{

    long N = n;

    vector<int> dp(n + 1);

    for (int i = 0; i <= N; i++) {

        if (i <= 1) {
            dp[i] = 1;
        } else {

            int ans1 = mul(dp[i - 1], dp[i - 1]);
            int ans2 = mul(dp[i - 1], dp[i - 2]);
            int ans3 = mul(dp[i - 2], dp[i - 1]);
            dp[i] = add(add(ans1, ans2), ans3);

        }

    }

    return dp[n];

}

// t.c. = O(N)
// s.c. = O(N)


// space optimized.


long mod = (int)(1e9 + 7);
long add(long a, long b) {

    return ((a % mod) + (b % mod)) % mod;
}

long mul(long a, long b) {

    return ((a % mod) * (b % mod)) % mod;
}


int countBalancedBinaryTree( int n)
{

    long N = n;

    long prev = 1, sprev = 1;

    for (int i = 0; i <= N; i++) {

        long curr = 0;

        if (i <= 1) {
            curr = 1;
        } else {

            int ans1 = mul(prev, prev);
            int ans2 = mul(prev, sprev);
            int ans3 = mul(sprev, prev);
            curr = add(add(ans1, ans2), ans3);
            sprev = prev;
            prev = curr;

        }

    }

    return prev;

}

// t.c. = O(N)
// s.c. = O(1)