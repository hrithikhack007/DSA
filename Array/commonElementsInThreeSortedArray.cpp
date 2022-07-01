// using unordered map. we are for each i incrementing its frequency in the unordered map and skipping the duplicates. In this way we are making
// sure that each element in one array is counted only once. So if one element occurs in all three arrays its frequency will be 3. We will insert
// those elements in the ans array and sort the array.


class Solution
{
public:
	vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
	{
		//code here.

		unordered_map<int, int> mp;

		for (int i = 0; i < n1; i++) {
			mp[A[i]]++;
			int j = i + 1;

			while (j < n1 && A[j - 1] == A[j]) j++;
			i = j - 1;
		}

		for (int i = 0; i < n2; i++) {
			mp[B[i]]++;
			int j = i + 1;
			while (j < n2 && B[j - 1] == B[j]) j++;
			i = j - 1;
		}

		for (int i = 0; i < n3; i++) {
			mp[C[i]]++;
			int j = i + 1;
			while (j < n3 && C[j - 1] == C[j]) j++;
			i = j - 1;
		}

		vector<int> ans;

		for (auto a : mp) {
			if (a.second == 3) ans.push_back(a.first);
		}

		sort(ans.begin(), ans.end());
		return ans;


	}

};


// t.c. = O(NlogN) => (N=n1+n2+n3)
// s.c. = O(N) => (N=n1+n2+n3)





// using three pointers. we will keep pointers i,j and k on the starting index of arrays a,b and c. now whenever we find all three pointers
// have same value that means we have found the common element we will push it into the ans array and move all three pointers to the next
// element via skipping duplicates. if all three are not same then we will incremenet the pointer whose value is the minimum. because we cannot
// reach that minimum value via other two pointers so better skip it.


class Solution
{
public:
	vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
	{
		//code here.

		vector<int> ans;

		int i = 0, j = 0, k = 0;

		while (i < n1 && j < n2 && k < n3) {


			if (A[i] == B[j] && B[j] == C[k]) {
				ans.push_back(A[i]);

				int t = i + 1;
				while (t < n1 && A[t - 1] == A[t]) t++;
				i = t;

				t = j + 1;
				while (t < n2 && B[t - 1] == B[t]) t++;
				j = t;

				t = k + 1;
				while (t < n3 && C[t - 1] == C[t]) t++;
				k = t;


			} else if (A[i] <= B[j] && A[i] <= C[k]) {
				i++;
			} else if (B[j] <= A[i] && B[j] <= C[k]) {
				j++;
			} else {
				k++;
			}


		}


		return ans;



	}

};


// t.c. = O(N) => (N = n1 + n2 + n3)
// s.c. = O(1) (excluding the returning ans array)


// using binary search. as all three arrays are sorted. we will traverse array a and will do a binary search for each ith element in the
// arrays b and c. if we found we will insert it in the ans array and skip to the next unique element to avoid duplication.

class Solution
{
public:
	vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
	{
		//code here.

		vector<int> ans;

		for (int i = 0; i < n1; i++) {


			if (binary_search(B, B + n2, A[i]) && binary_search(C, C + n3, A[i])) {
				ans.push_back(A[i]);
			}

			int j = i + 1;

			while (j < n1 && A[j - 1] == A[j]) j++;
			i = j - 1;

		}

		return ans;



	}

};

// t.c. = O(n1log(n2+n3))
// s.c. = O(1) (excluding the returning ans array)




