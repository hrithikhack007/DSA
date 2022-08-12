// we will sort the jobs according to the decreasing order of their profits.
// then we will start traversing from i = 0 to n-1, in each iteration we will try to finish the ith job on the last day of its
// deadline , so we there may be other jobs which can finish on that day so we will first find any free position available before
// the deadline where no other job is finishing then we will choose that day and add the job's profit and incrememt the counter else
// we couldn't find the any free day before or on its dealine then we can't do this job so continue.

// parent[i] will tell the first free position from i to 1. i.e. if parent[7] is 4 then that means day 7,6 and 5 are the finishing time for
// some jobs but day 4 is not the finishing time for any job currently so we can assign a job to finish at day 4.
// so. for the ith job, we will find the par[dead] i.e. we want to know is there any free day where I can finish this job before or on the deadline
// if par > 0 that means we can finish this job as there is some free day so we will increment jobs++,add ith job profit,and assign parent of
// par-1 to parent of par because ith job is finished on par'th day so the next free day will be given by parent[par-1].


class Solution
{
public:


	static bool comp(Job a, Job b) {

		return a.profit > b.profit;
	}

	int findPar(int node, vector<int> &parent) {
		if (node == parent[node]) return node;

		return parent[node] = findPar(parent[node], parent);
	}


	vector<int> JobScheduling(Job arr[], int n)
	{

		sort(arr, arr + n, comp);
		vector<int> parent(101);

		for (int i = 0; i <= 100; i++) parent[i] = i;

		int profit = 0, jobs = 0;

		for (int i = 0; i < n; i++) {

			int dead = arr[i].dead;

			int par = findPar(dead, parent);

			if (par > 0) {

				jobs++;
				profit += arr[i].profit;
				parent[par] = findPar(par - 1, parent);
			}


		}

		return {jobs, profit};


	}
};

// t.c. = O(NLogN) + O(N) = O(NLogN)
// s.c. = O(100) = O(1)


// brute force approach of findind the free day.
// starting from the deadline run a loop till we found the free day or we reach 0 then break. if dead > 0 that means we have found the free
// day so assign the deadline[dead] as arr[i].id.

class Solution
{
public:


	static bool comp(Job a, Job b) {

		return a.profit > b.profit;
	}

	//Function to find the maximum profit and the number of jobs done.
	vector<int> JobScheduling(Job arr[], int n)
	{

		sort(arr, arr + n, comp);
		vector<int> deadline(101, 0);

		int profit = 0, jobs = 0;

		for (int i = 0; i < n; i++) {

			int dead = arr[i].dead;

			while (dead > 0 && deadline[dead] != 0) dead--;

			if (dead > 0) {
				deadline[dead] = arr[i].id;
				profit += arr[i].profit;
				jobs++;

			}


		}

		return {jobs, profit};


	}
};


// t.c. = O(NLogN) + O(N*100) = O(NLogN) + O(N) = O(NLogN)
// s.c. = O(100) = O(1)

