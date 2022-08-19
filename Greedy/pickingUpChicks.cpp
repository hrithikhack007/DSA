// we calculate the time taken for each chicks to reach the barn using given initial distance and speed.
// now we set fast, slow and count to 0. fast means the number of chicks which can reach the barn in time , slow means the number of chicks
// who can't reach the barn in time count means number of swaps we have to perform.
// so we will iterate from i = n - 1 to 0 and for each iteration , we will check if the t[i] > T that means it is a slow chick so increment
// slow by 1 else if t[i]<= T then we have found the fast chick so we need to swap this chick with slow chicks ahead of it i.e. 'slow' times
// we have to swap so add slow in count and also increment fast by 1 as it can reach the end in time.
// if fast becomes == k then return count and if the loop is over that means k chicks cannot reach barn in time so return impossible.

// we start from n - 1 and calculate the time taken by each chick while traversing only so don't need to allocate extra array.





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






void answerNikalBc() {

	ll n, k, b, T;

	cin >> n >> k >> b >> T;

	vector<double> d(n), s(n);

	for (ll i = 0; i < n; i++) {
		cin >> d[i];
	}

	for (ll i = 0; i < n; i++) {
		cin >> s[i];
	}


	ll fast = 0, slow = 0, count = 0;

	for (ll i = n - 1; i >= 0; i--) {

		double t = (b - d[i]) / s[i];


		if (t > T) {
			slow++;
		} else {
			fast++;
			count += slow;
		}

		if (fast == k) {
			cout << count << "\n";
			return;
		}


	}

	cout << "IMPOSSIBLE\n";



}




int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t ;
	t = 1;
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		answerNikalBc();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

	return 0;
}


// t.c. = O(N)
// s.c. = O(1)