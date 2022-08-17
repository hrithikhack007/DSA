// set p and n to 0 p will find the index of positive elements i.e. buyer and n will find the index of negative elements i.e. sellers.
// now while p<sz && n<sz , in each iteration find the first index of buyer to do this increment p if it is < sz and arr[p]<=0
// similarly find the first instance of seler to do this increment n if it is < sz and arr[n]>=0.

// now if p < sz and n < sz then we have found the nearest seller for the buyer to buy the wine.
// so we will try to buy the wines for the pth buyer from the nth seller so that the work is minimum because n is the nearest buyer for the
// pth buyer if he buys from someone else work will increase hence to minimize the work it is optimal to take winese form the nth buyer.
// so if arr[p] + arr[n] > 0 that means number of buys is > than no. of selling wines so we will take all the wines from nth seller and add the
// work i.e. distance between buyer and seller which is abs(p-n) multiplied by no. of wines which is abs(arr[n]) and subtract abs(arr[n]) wines
// from arr[p] as we have bought that much wine, set ans[n] to 0.
// and if arr[p] + arr[n] < 0 that means no. of wines for sell exceeds no. of wines for buy so we will buy arr[p] wines and add the work
// abs(p-n)*(arr[p]) and then subtract the arr[p] from arr[n] as that many wines are sold also set arr[p] to 0.
// else if both the buying and selling quantity is same so buyer will buy arr[p] wines and seller will sell arr[n] wines so work done is
// abs(p-n)*arr[p] and set both arr[p] and arr[n] to 0.



#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define inf 1E18
#define ninf -1*1E18
#define mod 1000000007
#define fi first
#define si second
#define pb push_back
#define vi vector<long long int>
#define pi pair<long long int,long long int>
#define vpi vector<pair<long long int,long long int>>
#define vvi vector<vector<long long int>>
#define umii unordered_map<ll,ll>
#define sinf INT_MAX
#include<limits>
using namespace std;

void answerNikalBc(ll sz) {


	vi arr(sz);

	for (ll i = 0; i < sz; i++) cin >> arr[i];

	ll ans = 0;

	ll p = 0, n = 0;

	while (p < sz && n < sz) {

		while (p < sz && arr[p] <= 0) p++;
		while (n < sz && arr[n] >= 0) n++;

		if (p < sz && n < sz) {
			if (arr[p] + arr[n] > 0) {
				ans += (abs(p - n) * abs(arr[n]));
				arr[p] += arr[n];
				arr[n] = 0;
			} else if (arr[p] + arr[n] < 0) {
				ans += (abs(p - n) * abs(arr[p]));
				arr[n] += arr[p];
				arr[p] = 0;
			} else {
				ans += (abs(p - n) * abs(arr[n]));
				arr[p] = arr[n] = 0;
			}
		}

	}

	cout << ans << "\n";


}


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	while (cin >> n) {

		if (n == 0) break;
		answerNikalBc(n);
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

	return 0;
}

// t.c. = O(N)
// s.c. = O(1)