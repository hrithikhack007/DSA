// use unordered map. first store all the occurences of all elements in a2. then cancel out the occurences from all the elements of a1 array.
// check map if any element has occurence > 0 that means the frequency of that element in a1 is more than that of a2, so we will return no.
// else after checking the map return yes.

string isSubset(int a1[], int a2[], int n, int m) {


	unordered_map<int, int> mp;

	for (int j = 0; j < m; j++) {
		mp[a2[j]]++;
	}

	for (int i = 0; i < n; i++) {
		mp[a1[i]]--;
	}

	for (auto a : mp) {
		if (a.second > 0) return "No";
	}

	return "Yes";

}

// t.c. = O(N)
// s.c. = O(N)