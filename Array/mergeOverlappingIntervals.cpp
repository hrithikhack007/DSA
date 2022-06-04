// brute force using dfs. Consider each interval as a node of the graph. two intervals will have edge between them if they are overlapping.
// In this way we will form a component where intervals are overlapping with each other and find the minimum starting value and maximum
// ending value in this component and insert it as the new merged interval. two components are disconnected if they don't share any
// overlapping intervals. so after finding all the merged intervals of all disconnected components we will get all merged non-overlapping
// intervals. we will use dfs to traverse each component.


class Solution {
public:

	void dfs(int node, vector<bool> &visited, vector<int> adjacencyList[], int &mini, int &maxi, vector<vector<int>> &intervals) {

		visited[node] = true;
		mini = min(mini, intervals[node][0]);
		maxi = max(maxi, intervals[node][1]);

		for (auto child : adjacencyList[node]) {
			if (!visited[child]) {
				dfs(child, visited, adjacencyList, mini, maxi, intervals);
			}
		}
	}

	vector<vector<int>> merge(vector<vector<int>>& intervals) {


		int n = intervals.size();


		vector<int> adjacencyList[n];
		vector<bool> visited(n, false);


		for (int index = 0; index < n; index++) {


			auto Interval = intervals[index];

			for (int secondIndex = index + 1; secondIndex < n; secondIndex++) {

				auto secondInterval = intervals[secondIndex];

				if (!(secondInterval[0] > Interval[1] || secondInterval[1] < Interval[0])) {

					adjacencyList[index].push_back(secondIndex);
					adjacencyList[secondIndex].push_back(index);

				}

			}


		}

		vector<vector<int>> nonOverlappingIntervals;


		for (int interval = 0; interval < n; interval++) {

			if (!visited[interval]) {
				int mini = INT_MAX, maxi = INT_MIN;
				dfs(interval, visited, adjacencyList, mini, maxi, intervals);
				nonOverlappingIntervals.push_back({mini, maxi});

			}
		}

		return nonOverlappingIntervals;



	}
};



// t.c. = O(N^2)
// /s.c. = O(N^2)

// using sorting. sort the intervals array. we will keep one active interval intialized to intervals[0] and start from index 1. at every index
// we will check if the current interval overlapping with the active interval , if it is then we will merge this two intervals. else if
// current interval is outside the range of active interval then all the intervals ahead of current will also not overlap with active as the
// intervals are sorted in non decreasing order. so we will insert the active interval as one of the merge nonoverlapping interval in the ans
// array and make the current interval as the active interval. in the end we will put the last active interval in ans array.

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {

		int n = intervals.size();

		sort(intervals.begin(), intervals.end());

		vector<int> activeInterval = intervals[0];
		vector<vector<int>> nonOverlappingIntervals;

		for (int index = 1; index < n; index++) {

			auto currentInterval = intervals[index];

			if (currentInterval[0] <= activeInterval[1]) {
				activeInterval[1] = max(activeInterval[1], currentInterval[1]);
			} else {
				nonOverlappingIntervals.push_back(activeInterval);
				activeInterval = currentInterval;
			}


		}


		nonOverlappingIntervals.push_back(activeInterval);

		return nonOverlappingIntervals;

	}
};

// t.c. = O(NlogN)
// s.c. = O(1)


