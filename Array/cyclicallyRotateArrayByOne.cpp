
// store the right most element in temp variable and right shift remaining elements by one position. in last insert temp value
// in the start of array.

void rotate(int arr[], int n)
{


    int t = arr[n - 1];

    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = t;


}

// t.c. = O(N)
// s.c. = O(1)

// use two pointers. one at the start and other at the end. swap the values at thos pointers and increment the starting pointer by
// keeping the last pointer fixed.

void rotate(int arr[], int n)
{


    int i = 0, j = n - 1;

    while (i < j) {

        swap(arr[i++], arr[j]);
    }




}


// t.c. = O(N)
// s.c. = O(1)