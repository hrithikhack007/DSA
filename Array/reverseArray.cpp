// simply print in reverse order

using namespace std;
int main()
{
	//code

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		int arr[n];

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = n - 1; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}



	return 0;
}

// t.c = O(N)
// s.c. = O(1)


// keep two pointers, one at start and other at end and keep swapping the elements until they two cross each other.


using namespace std;
int main()
{
	//code

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		int arr[n];

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0, j = n - 1; i <= j; i++, j--) { //init two pointers
			int  t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;

			// swapping values at those pointers

		}

		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		// printing the reverse array

	}



	return 0;
}

// t.c = O(N)
// s.c. = O(1)

// use recursion to reverse. keep two pointers and at each call swap the values of pointer and make a call on same
// function with one pointer moving forward  and other backward  until pointers cross each other at that time return.


using namespace std;

void rec(int i, int j, int arr[]) {

	if (i > j) { // terminate when cross by returning
		return;
	}
	int  t = arr[i];
	arr[i] = arr[j];
	arr[j] = t; //swapping
	rec(i + 1, j - 1, arr); // call again
}


int main()
{
	//code

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		int arr[n];

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		rec(0, n - 1, arr);



		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

	}



	return 0;
}

// t.c = O(N)
// s.c. = O(N) => stack space



