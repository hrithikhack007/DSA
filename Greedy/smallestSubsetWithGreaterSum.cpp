// sort the arr in increasing order take its sum in rem and set curr and ans to 0.
// start itearting from n - 1 to 0 and in each iteration, increment ans by 1 add ith element in curr remove ith element from rem and if curr
// becomes > rem then return ans.

// intuition: picking larger elements will result in greater sum in minimum number of elements than picking smaller elements.


class Solution {
public:

#define ll long long

    int minSubset(vector<int> &Arr, int N) {


        sort(Arr.begin(), Arr.end());

        ll rem = accumulate(Arr.begin(), Arr.end(), (ll)0);

        ll curr = 0;
        ll ans = 0;

        for (ll i = N - 1; i >= 0; i--) {

            ans++;
            curr += Arr[i];
            rem -= Arr[i];

            if (curr > rem) return ans;
        }



    }
};

// t.c. = O(NLogN)
// s.c. = O(1)