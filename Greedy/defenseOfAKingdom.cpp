// let the maximum difference between the occupied columns be mc and maximum difference between the occupied rows be mr then the maximum
// area of unoccupied rectanlge will be mc*mr.
// so while taking the rows and cols in input of a cell mark its corresponding row and col as occupied in map.
// edge case: mark the bounday rows and cols in the map as well.
// now set maximumdiffrows and maximumdiffcols to 0 and also prevrow and prevcol to 0.
// now first find the maximumdiffrows so start traversing from r = 1 to n and in each iteration check if the row r is occupied if it is
// then take the difference of prevRow and r and maximize the maxDiffRows with it then set prevRow to r.
// simialry iterate from column c = 1 to m and in each iteration check if the col c is occupied if it is then take the difference of prevCol
// and c and maximize the maxDiffCol with it then set prevCol to c.
// ans will be maxDiffRow *maxDiffcol.



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


	ll m, n, q;

	cin >> m >> n >> q;


	unordered_map<ll, ll> rows, cols;

	for (ll i = 0; i < q; i++) {

		ll r, c;

		cin >> c >> r;

		rows[r]++;
		cols[c]++;

	}

	rows[n + 1] = cols[m + 1] = rows[0] = cols[0] = 1;


	ll maxDiffRows = 0, maxDiffCols = 0;
	ll prevRow = 0, prevCol = 0;

	for (ll r = 1; r <= n + 1; r++) {

		if (rows[r]) {
			maxDiffRows = max(maxDiffRows, r - prevRow - 1);
			prevRow = r;
		}


	}

	for (ll c = 1; c <= m + 1; c++) {

		if (cols[c]) {
			maxDiffCols = max(maxDiffCols, c - prevCol - 1);
			prevCol = c;
		}
	}

	cout << maxDiffRows*(1LL)*maxDiffCols << "\n";


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


// t.c. = O(N+M)
// s.c. = O(N+M)