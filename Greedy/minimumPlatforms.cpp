// optimal.
// sort the arrival and departure times of train in non-decreasing order.
// now set a and d to 0.
// set platforms and maxi to 0.
// while a <n(i.e. arrival time of all trains are not considered), in each iteration, check if the current arrival time is <= curr departure
// time then there will be a train arriving before departure of any already arrived train so we have to allot a platform for this train
// so we increment platforms by 1 and maximize maxi with platforms also move to next arrival time by incrementing a by 1.
// else there is a train departing before arrival of next train so we will deallocate the platform which this train was using and move to
// next departure time.

// pattern observation: if let's say we have given n intervals but only one box and at a given time we can consider only one interval in
// that box so we have to find out what is the maximum intervals we can consider without overlapping intervals.
// (like N meetings in one room).
// so in this kind of problems we have to sort accoring to the second value or ending time because as soon as the room gets free we can start
// the other meetings allowing us to perform more meetings than to choosing meetings with higher ending time first.

// but if let's say we have given n intervals and we have to consider all the intervals but need to find the minimum number of boxes required
// to consider all intervals without overlapping.(minimum platforms problem).So in this kind of problems,we first sort both the start and end
// of intervals in non-decreasing order and use two pointer approach to allocate and deallocate boxes based on start is before or equal than
// end.

class Solution {
public:
	//Function to find the minimum number of platforms required at the
	//railway station such that no train waits.
	int findPlatform(int arr[], int dep[], int n)
	{
		// Your code here

		sort(arr, arr + n);
		sort(dep, dep + n);

		int a = 0, d = 0;
		int platforms = 0, maxi = 0;

		while (a < n) {

			if (arr[a] <= dep[d]) {
				platforms++;
				maxi = max(maxi, platforms);
				a++;
			} else {
				platforms--;
				d++;
			}

		}

		return maxi;


	}
};


// t.c. = O(NlogN)
// s.c. = O(1)