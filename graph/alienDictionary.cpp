// using toposort.

//the words are sorted in increasing order according to the alien ordering of characters. we will start from i=1 and compare ith and i-1th word
// when we found a mismatch we will form a edge from a to b where a will be jth character from i-1th word and b will be the jth character from
// ith word and j will be the index where mismatch happens and break out of the comparision loop.

// in this way we will check all adjacent words for mismatch and form edges. basically edge a to b means a comes before b in ordering.
// why are just checking adjacent words and not each word with all other words because in the question it is given that words will be sorted
// so let's consider an example and take some cases to prove our idea to be true:

// a1 a2 a3 a4 a5 a6 | b1 b2 b3 b4 b5 b6 | c1 c2 c3 c4 c5 c6

// let's say word a is some word on left side and b and c are adjacent words.

// now, case1: mismatch of a and b happens at index 4 and mismatch of b and c happens at index 3. so prefix of a1 to a3 and b1 to b3 are same
// and prefix of b1 to b2 and c1 to c2 are same that means prefix of a1 to a2 is same as prefix of c1 to c2 and a3 = b3 so if we compare
// word a and c a3 is going to come before c3 but even if we compare word b and c then also we will find out that b3=a3 is coming before c3.

// case 2: mismatch of a and b happens at index 3 and mismatch of b and c happens at index 4. so prefix of a1 to a2 = prefix of b1 to b2.
// prefix of b1 to b3 = prefix of c1 to c3 and prefix of a1 to a2 = prefix of c1 to c2 and the mismatch will happen at index 3 because b3=c3.
// and we will find that a3 is coming before c3 but while comparing word a with b only we found that a3 is coming before b3 and b3 = c3 so
// a3 is also coming before c3 would have been consider there only without comparing word a with word c.

// case 3: mismatch of a and b happens at index 3 and mismatch of b and c happens at index 3. in this case prefix of a1 to a2 = prefic of b1 to b2
//  prefic of b1 to b2 = prefix of c1 to c2. so we can say that starting 2 characters of all 3 words are same and mismatch is happening at index 3.
// so a3 , b3 and c3 have to be different . and a3 would come before b3 and b3 would come before c3 so by comparing just adjacent words we will
// be able to find the ordering.

// so by analyzing above cases, we can say that we don't need to compare each word with all other words by comparing adjacent words also do the
// trick.


class Solution {
public:

	void dfs(int node, string &order, vector<bool> &visited, vector<int> adj[]) {

		visited[node] = true;

		for (auto child : adj[node]) {
			if (!visited[child]) {
				dfs(child, order, visited, adj);
			}
		}

		order.push_back(char('a' + node));

	}

	string findOrder(string dict[], int N, int K) {
		//code here


		vector<int> adj[K];

		for (int i = 1; i < N; i++) {

			for (int k = 0; k < min((int)dict[i].size(), (int)dict[i - 1].size()); k++) {

				if (dict[i][k] != dict[i - 1][k]) {
					int u = dict[i - 1][k] - 'a';
					int v = dict[i][k] - 'a';

					adj[u].push_back(v);
					break;
				}

			}

		}


		string order = "";
		vector<bool> visited(K, false);

		for (int i = 0; i < K; i++) {
			if (!visited[i]) {
				dfs(i, order, visited, adj);
			}
		}

		reverse(order.begin(), order.end());

		return order;


	}
};

// t.c. = O(l*N) + O(K+E) => O(N)+O(K+E), l is the average length of words , K is the no. of unique chars and E is the no. of edges.
// s.c. = O(K) + O(K+E)

// we can also do this by using bfs (kahn's algo)