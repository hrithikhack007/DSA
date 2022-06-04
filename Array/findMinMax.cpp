// simple linear search


pair<long long, long long> getMinMax(long long a[], int n) {


	pair<long long, long long> minMax = {LLONG_MAX, LLONG_MIN};

	for (int i = 0; i < n; i++) {

		minMax.first = min(a[i], minMax.first);
		minMax.second = max(a[i], minMax.second);
	}

	return minMax;


}

// t.c => O(N)
// s.c => O(1)

// divide and conquer.

// we keep dividing the array at the middle and find the minMax of those two halves and from those we will find the minMax of the
// entire array. we will keep dividing until only one element left from there we will return {min,max} as same element.

pair<long long, long long> rec(int s, int e, long long a[]) {

	if (s == e) {
		return {a[s], a[e]};
	}

	int mid = (s + e) / 2;
	pair<long long , long long> lef = rec(s, mid, a);
	pair<long long , long long> rig = rec(mid + 1, e, a);
	long long maxi = max<long long>(lef.second, rig.second);
	long long mini = min<long long>(lef.first, rig.first);

	return {mini, maxi};
}

pair<long long, long long> getMinMax(long long a[], int n) {

	return rec(0, n - 1, a);

}

// t.c. => O(NlongN)
// s.c. => O(logN) => stack space