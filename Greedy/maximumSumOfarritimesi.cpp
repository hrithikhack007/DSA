// just sort the array in increasing order and multiply the a[i] with i.
// so the larger element will be multiplied with larger index and so on so sum is maximum.


class Solution {
public:

#define ll long long
    ll mod = (ll)(1e9 + 7);

    ll add(ll a, ll b) {

        return ((a % mod) + (b % mod)) % mod;
    }

    ll mul(ll a, ll b) {

        return ((a % mod) * (b % mod)) % mod;
    }

    int Maximize(int a[], int n)
    {
        sort(a, a + n);

        ll ans = 0;

        for (int i = 0; i < n; i++) {

            ans = add(ans, mul(a[i], i));

        }

        return ans;


    }
};

// t.c. = O(NLogN)
// s.c. = O(1)
