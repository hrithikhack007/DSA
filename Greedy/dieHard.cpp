// we can start from either fire, water or air and whichever returns maximum time we will take that , so call from each choices
// by adding or subtractring the health and armor and for each rec. call if h or a becomes 0 then return 0.
// if dp[place][h][a] != -1 that means it is already calculated so return dp[place][h][a].
// else, set maxi to 0 and iterate from option = 0 to 2 and for each option if it is not equal to current place then call on that option by
// adding or subtracting the health or armor and whatever the call returns add 1 in it because you survived the current place and maximize the
// maxi with it. before returning store the maxi in dp.

// edge cases: health and armor may increase at some instances so define the dp size by more than 1000 to avoid out of bound access.
// here the armor may increase in successive places but in that health will decrease and h can be at max 1000 and so armor can increase in two
// places water and air so in that health decreases by 17 so 1000/17 is the approximate number of times armor can increase and for armor can
// increase by 7 in those places so let's say 1000/17 is 50 so armor increases by 50*7 = 350 from its initial value so we add extra 1000 for
// safety.


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


ll rec(ll place, ll h, ll a, vector<vector<ll>> &places, vector<vector<vector<ll>>> &dp) {

	if (h <= 0 || a <= 0) return 0;


	if (dp[place][h][a] != -1) return dp[place][h][a];

	ll maxi = 0;

	for (ll option = 0; option < 3; option++) {

		if (place != option) {

			maxi = max(maxi, rec(option, h + places[option][0], a + places[option][1], places, dp) + 1);
		}
	}

	return dp[place][h][a] = maxi;
}



void answerNikalBc() {


	ll h, a;

	cin >> h >> a;

	vector<vector<ll>> places = {{3, 2}, { -5, -10}, { -20, 5}};

	vector<vector<vector<ll>>> dp(3, vector<vector<ll>>(h + 1000, vector<ll>(a + 1000, -1)));

	ll maxi = 0;

	for (ll i = 0; i < 3; i++) {

		maxi = max(maxi, rec(i, h + places[i][0], a + places[i][1], places, dp));


	}


	cout << maxi << "\n";


}




int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t ;
	t = 1;
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		answerNikalBc();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

	return 0;
}

// t.c. = O(3*h*a*3) = O(h*a)
// s.c. = O(3*h*a) = O(h*a)

// greedy.


// it is better to start with air and choose air every alternate choice.
// so start t from 0 and when t is even simply go to air and increment h by 3 and increment a by 2.
// else we have two options, either to go to fire or water but going in fire decreases the health by whooping 20 points even though it increases
// armor by 5 points but armor doesn't mean anything if health becomes 0 so we will try to go to water if h > 5 and a > 10 and then decrement
// h by 5 and decrement a by 10 else if it is not true then we have no choice but to go to fire so we will check if h > 20 then we will go in fire
// and decrement h by 20 else if we don't have health left to go in fire then we can't survive so break else if any one of the above condition
// becomes true that means we have survived one place so increment t by 1.


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


	ll h, a;

	cin >> h >> a;

	ll t = 0;

	while (1) {


		if (!(t & 1)) {

			h += 3;
			a += 2;
		} else if (a > 10 && h > 5) {
			h -= 5;
			a -= 10;
		}
		else if (h > 20) {
			h -= 20;
			a += 5;
		} else {
			break;
		}

		t++;


	}

	cout << t << "\n";

}




int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t ;
	t = 1;
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		answerNikalBc();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

	return 0;
}


// t.c. = O(min(h,a))
// s.c. = O(1)