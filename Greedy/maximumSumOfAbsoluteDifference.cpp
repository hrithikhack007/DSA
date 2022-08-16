// sort the array in increasing order , set sum to 0, l to 0 and r to n - 1 and c to 0.
// now till l<r, in each iteration add arr[r]-arr[l] in the sum, after this if c is even then increment l by 1 else decrement r by 1 and change
// the parity of c.
// after while loop is finished, add arr[l]-arr[0] i.e. the difference of last and first.

// intuition: we want to maximize the absolute difference between the adjacent elements so we are pairing the smallest number with the largest
// number that's it else is just forming the sequence with it using two pointers. when c is even that means larger element is on the right so
// increment l as we want next smaller element and if c is odd that means smaller element is on right so we want next larger element so decrement
// r by 1.


#include<bits/stdc++.h>

int maxAbsSum(vector<int> &arr, int n)
{

    sort(arr.begin(), arr.end());

    int sum = 0;

    int l = 0, r = n - 1;
    int c = 0;

    while (l < r) {
        sum += (arr[r] - arr[l]);
        if (c % 2 == 0) l++;
        else r--;
        c ^= 1;
    }

    sum += (arr[l] - arr[0]);
    return sum;


}


// t.c. = O(NLogN) + O(N) = (NLogN)
// s.c. = O(1)