// using unordered map. for each iteration, we will check if a is present in the map if it is not then this customer is entering the
// cyber cafe in this case if k>0 then decrement the number of available computers i.e. k by 1 and insert this a in map with true value
// indicating this customer is on some computer else if k<=0 then the customer could not use any computer so insert a in map with value
// false.

// now if a is present in the map that means customer is leaving cafe, so in this case check if value of a in map is true then one
// computer is becoming available so increment k by 1 else if mp[a] is false then this customer was not assigned any computer so leave
// it. and remove a from the map.

#include<bits/stdc++.h>
int countCustomers(vector<int> &arr, int k)
{
	//    Write your code here

	unordered_map<int, bool> mp;
	int cnt = 0;
	for (auto a : arr) {


		if (mp.find(a) == mp.end()) {

			if (k > 0) {
				mp[a] = true;
				k--;
			} else {
				cnt++;
				mp[a] = false;
			}
		} else {
			if (mp[a]) k++;
			mp.erase(mp.find(a));
		}



	}

	return cnt;


}

// t.c. = O(2*N)
// s.c. = O(N)

// using mod. as the customers label will be <=n we can use the given array as a map itself. at each iteration we will find the
// corresponding index of arr[i] like idx = (arr[i] + x)%x where x is the value n+1 which we will add later. now we will check if
// arr[idx] < x and arr[idx] > 0 that means this index's value has not been modified so arr[i] customer is arriving first time
// in this case, if k>0 then we will assign this customer a computer and decrement k by one and add x to its corresponding index
// value so we can easily identify if the customer is leaving in future. i.e. arr[idx] = arr[idx] + x. else if k<=0 then we can't
// provide any computer to this customer so increment cnt by 1 and add -x to it's corresponding index value like arr[idx]=arr[idx]-x.

// now if the customer is leaving so its value will be <0 or >x , in <0 then skip it because that customer already left without using
// any computer else if >x then increment k by 1 because this customer was leaving making one computer free.


int countCustomers(vector<int> &arr, int k)
{
	int cnt = 0;
	int n = arr.size() / 2;
	int x = n + 1;

	for (int i = 0; i < arr.size(); i++) {
		int idx = (arr[i] + x) % x;

		if (arr[idx] > x) k++;
		else if (arr[idx] < 0) continue;
		else if (k > 0) {
			k--;
			arr[idx] += x;
		} else {
			cnt++;
			arr[idx] -= x;
		}

	}

	return cnt;


}


// t.c. = O(2*N)
// s.c. = O(1)


// using status array. we will define a status array with size of n+1 initialized with 0. for each i we will check s=status[arr[i]]
// if s==0 that means this customer is arriving in this case if k>0 so we will provide 1 comp. to this customer and assign status[arr[i]]
// to 1 else if k<=0 then the customer leaves and we assign status[arr[i]] = -1 and increment cnt by 1.

// if s==1 then this user was using comp. and now leaving making one computer free so increment k by 1 and assign customer[arr[i]] to -1
// else if s==-1 , this customer already left so skip


int countCustomers(vector<int> &arr, int k)
{
	int cnt = 0;
	int n = arr.size() / 2;

	vector<int> status(n + 1, 0);

	for (int i = 0; i < arr.size(); i++) {

		int s = status[arr[i]];

		if (s == 0) {
			if (k > 0) {
				k--;
				status[arr[i]] = 1;
			} else {
				cnt++;
				status[arr[i]] = -1;
			}
		} else if (s == 1) {
			k++;
			status[arr[i]] = -1;
		}
	}

	return cnt;


}

// t.c. = O(2*N)
// s.c. = O(N)
