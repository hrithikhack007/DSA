// Unordered Map. store frequency of each element using unordered_map if while encountering an element its frequency is already 1 that means
// it already occured once so push it in the vector and if frequency is not 1 and not 0 that means it is already considered duplicate.
// sort the array.

vector<int> duplicates(int arr[], int n) {
	// code here

	unordered_map<int, int> mp;
	vector<int> Duplicates;

	for (int i = 0; i < n; i++) {
		if (mp[arr[i]] == 0) mp[arr[i]]++;
		else if (mp[arr[i]] == 1) {
			Duplicates.push_back(arr[i]);
			mp[arr[i]]++;
		}
	}

	if (Duplicates.size() == 0) Duplicates.push_back(-1);
	sort(Duplicates.begin(), Duplicates.end());

	return Duplicates;


}

// t.c. = O(NlogN)
// s.c. = O(1)


// swapping. for each index swap till the element belonging to that index doesn't comes there or you find some collision. if you found some
// collision (repetition) then mark the element of its respective index as -ve and break out of it. if you find the element satisfying
// the current poisition without repitiion then break. if the current element and its respective index's element are different then swap
// this element to its respective position and continue else if at the current element's index there is already an element equal to this but
// -ve then that means it was already considered so break. in the end starting from 0th index store the elements which is -ve and for 0 store
// only if its count >= 1 (edge case) count0=1 also because when there is single 0 it won't be counted initially count is only recorded
// when there is collision.

vector<int> duplicates(int arr[], int n) {

	vector<int> Duplicates;
	int count0 = 0;

	for (int i = 0; i < n; i++) {

		while (arr[i] >= 0 && i != arr[i]) {
			if (abs(arr[arr[i]]) == arr[i] && arr[arr[i]] >= 0) {
				if (arr[i] == 0) {
					count0++;
					break;
				}

				arr[arr[i]] = -arr[arr[i]];
				break;
			} else if (abs(arr[arr[i]]) != arr[i]) {
				swap(arr[i], arr[arr[i]]);
			}
			else {
				break;
			}
		}
	}


	for (int i = 0; i < n; i++) {

		if (i == 0 && count0 >= 1) {
			Duplicates.push_back(0);
			continue;
		}

		if (arr[i] < 0) {
			Duplicates.push_back(i);
		}


	}

	if (Duplicates.size() == 0) {
		Duplicates.push_back(-1);
	}

	return Duplicates;


}


// t.c = O(N)
// s.c. = O(1)



// using mod. for every i we will increment a[a[i]%n] by n. so after doing this, every index whose value is >=2*n indicates that there
// exists atleast 2 elements who has incremented current index's value so we will insert this index in the vector. as values in between
// 0 and n-1 so the highest value (n-1)*2 can't break 2*n range with just one value, so the value will be >2*n if and only if atleast
//  two similar values are present. we are using mod to remove all the n's that has been added to the current index's value and locate
// the accurate index according to the original value without any addition of n.

vector<int> duplicates(int arr[], int n) {

	vector<int> Duplicates;


	for (int i = 0; i < n; i++) arr[arr[i] % n] += n;



	for (int i = 0; i < n; i++) {

		if (arr[i] >= 2 * n) Duplicates.push_back(i);


	}

	if (Duplicates.size() == 0) {
		Duplicates.push_back(-1);
	}

	return Duplicates;


}


// t.c. = O(N)
// s.c. = O(1)



