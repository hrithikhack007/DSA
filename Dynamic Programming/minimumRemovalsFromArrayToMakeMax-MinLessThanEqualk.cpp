// not a dp.
// recursive solution. first sort the array in increasing order.
// now call the rec. by passing st=0,en=n-1 as arguments and in each rec. call if arr[en]-arr[st]<=k then return 0 as we don't have to
// remove anything.
// else set ans1 and ans2 to INT_MAX.
// ans1 stores the minimum number of elements I have to remove if I don't remove the arr[st] so we will found the upper bound in the range
// st and en for arr[st] + k then do a -1 and assign it to gt now arr[gt] - arr[st] will be <=k so we have to remove en - gt elements if we
// don't want to remove arr[st].
// now, ans2 represent the number of elements I have to remove if I don't want to remove the arr[en] so we will do upper bound in range of
// st , en for arr[en]-k-1 and assign it to sm, now arr[en] - arr[sm] <=k so we had to remove sm - st elements.
// now ans3 will be minimum no. of elements I have to remove if I removed both arr[st] and arr[en] so we will call on rec(st+1,en-1) and
// remove this two so ans3 = 2 + rec(st+1,en-1). then whichever choice is giving minimum we will take that and return min({ans1,ans2,ans3}).


#include<bits/stdc++.h>

int rec(int st, int en, vector<int> &arr, int k) {

    if (arr[en] - arr[st] <= k) return 0;


    int ans1 = INT_MAX, ans2 = INT_MAX;

    int gt = (upper_bound(arr.begin(), arr.begin() + en + 1, arr[st] + k) - arr.begin()) - 1;
    if (arr[gt] - arr[st] <= k) {
        ans1 = en - gt;
    }

    int sm = (upper_bound(arr.begin(), arr.begin() + en + 1, arr[en] - k - 1) - arr.begin());

    if (sm != en) {
        ans2 = sm - st;
    }

    int ans3 = rec(st + 1, en - 1, arr, k) + 2;

    return min({ans1, ans2, ans3});



}

int minRemovals(vector<int>& arr, int n, int k)
{

    sort(arr.begin(), arr.end());

    return rec(0, n - 1, arr, k);

}

// t.c. = O(NLogN) + O(NLogN) = O(NLogN)
// s.c. = O(N)(stack space)

// neat/concised more intuitive.

// sort the array in increasing order. then set ans to n - 1.
// iterate st from 0 to n-1. basically we are considering each index as the starting point of the final array and for each starting index
// we will find the valid ending index such that the difference between the ending element and starting element is <=k .
// for this, we will find the upper bound on arr[st] + k in the range st,n and do then do -1 on that upper bound and assign it to en.
// so upper bound will find the first element in array which is > arr[st] + k so if that element is > arr[st] + k then all the elements after
// it will also be > arr[st] + k so the difference between each element from range upper bound till end with arr[st] will be >k.
// that is why we're doing a -1 so en will be <= arr[st] + k and it will be the last element in array which will be <= arr[st] + k as we know
// from en + 1 i.e. upper bound every element is gonna be > arr[st] + k so we have now a st and en so except the elements in this range we will
// delete remaining elements. so deleted elements will be n - (en - st + 1).
// now we will minimize our ans with this deleted elements.


#include<bits/stdc++.h>

int minRemovals(vector<int>& arr, int n, int k)
{

    sort(arr.begin(), arr.end());

    int answer = n - 1;

    for (int st = 0; st < n; st++) {

        int en = (upper_bound(arr.begin() + st, arr.end(), arr[st] + k) - arr.begin()) - 1;

        answer = min(answer, n - (en - st + 1));

    }

    return answer;


}

// t.c. = O(N*Log(N))
// s.c. = O(1)

