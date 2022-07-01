// greedy and two pointers. keep two pointers one starting from 0th index and other starting from the end. if a[i]==a[j] , increment i and
// decrement j. if(a[i]<a[j])  increment i and merge a[i] with a[i-1] like a[i]+=a[i-1]. else if a[j]<a[i] then decrement j and merge
// a[j] and a[j+1] like a[j]+=a[j+1].merge one at a time because for example a[i] can become > a[j] in one operation if initially it was smaller
// so if we merge continuously it won't give minimum ans. after merging increment the count.

int merge(vector<int> ar) {
	//Write your code here


	int count = 0;

	int n = ar.size();

	int i = 0, j = n - 1;

	while (i < j) {

		if (ar[i] == ar[j]) {
			i++; j--;
		} else {

			if (ar[i] < ar[j]) {
				i++;
				ar[i] += ar[i - 1];
			} else {
				j--;
				ar[j] += ar[j + 1];
			}

			count++;



		}
	}




	return count;
}

// t.c. = O(N)
// s.c. = O(1)
