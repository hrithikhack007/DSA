// use auxillary array . first copy all +ve elements then insert all -ve elements.

void segregateElements(int arr[], int n)
{
	// Your code goes here

	int aux[n];
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 0) aux[idx++] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) aux[idx++] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		arr[i] = aux[i];
	}

}


//  t.c. = O(N)
//  s.c. = O(N)

// two pointers without maintaining order.


void segregateElements(int arr[], int n)
{
	// Your code goes here

	int i = 0, j = n - 1;

	while (i <= j) {

		if (arr[i] > 0 && arr[j] < 0) { // if lef is +ve and right is -ve, no problem move right and left.
			i++, j--;
		} else if (arr[i] < 0 && arr[j] > 0) { // if lef is -ve and right is -ve , swap them to their respective position and
			// move left as well as right.
			swap(arr[i++], arr[j--]);
		} else if (arr[i] > 0 && arr[j] > 0) { // if lef is +ve and rigt is +ve , lef is its correct position so increment it.
			i++;
		} else {   // if lef is -ve and right is -ve, then rig is its correct position so decrement it.
			j--;
		}
	}

}


// t.c. = O(N)
// s.c. = O(1)

// Insertion sort trick. if current element is +ve and no -ve element encountered yet then continue. if current element is the
// first -ve element then assign start and end of -ve elements stream as i. if curr is +ve and -ve exist then insert this
// +ve element at the first -ve element and right shift all the current -ve elements by one and increment its start and end indexes.




void Insert(int st, int en, int arr[], int idx) {

	int t = arr[st], val = arr[idx];

	for (int i = st; i <= en; i++) {
		t = arr[i];
		arr[i] = val;
		val = t;

	}


}


void segregateElements(int arr[], int n)
{
	// Your code goes here

	int st = -1, en = -1, t = 0;

	for (int i = 0; i < n; i++) {
		if (st == -1) {   // if -ve elements not found yet

			if (arr[i] >= 0) continue;

			else {

				st = i, en = i;

			}

		} else {  // if -ve elements have been found

			if (arr[i] >= 0) {
				en++;
				Insert(st, en, arr, i); // +ve element found so insert it at the start of -ve element stream
				st++;

			} else {
				en++;
			}
		}


	}

}


// t.c. = O(N^2)
// s.c. = O(1)

