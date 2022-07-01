// brute force.

// we will use bfs here. first take the queue of pair of int to store the state. take an unordered map visited to and create a function
// to convert the pairs into integer to use it as a key in a visited map.
// push the initial state into queue and mark the initial state as visited.
// now traverse the state level by level i.e. no. of all states from 1 operations will be evaluate together and and states with no.
// of operations 2 will be pushed ans so on. at any moment we get curr. state such that jug1 or jug2 becomes = d then return count.
// count will increment by 1 after evaluating all states of the current count.
// in evaluating a state, we will check all possibilites i.e. fill the jug1 completely, empty the jug1, fill the jug2 completely,
// empty the jug2, pour the water from jug2 to jug1, pour the water from jug1 to jug2. and while checking this possibility we will
// only consider those which has not already been considered and push those into queue and also mark them as visited.

cass Solution{
public:

#define ll short

	ll pairToNum(ll x, ll y, ll oy) {

		return x * (oy + 1) + y;
	}

	void mark(ll x, ll y, ll oy, queue<pair<ll, ll>> &q, unordered_map<ll, ll> &visited) {

		if (!visited[pairToNum(x, y, oy)]) {

			q.push({x, y});
			visited[pairToNum(x, y, oy)]++;

		}

	}

	int minSteps(int m, int n, int d)
	{
		// Code here

		unordered_map<ll, ll> visited;

		queue<pair<ll, ll>> q;

		ll count = 0;

		q.push({0, 0});
		visited[pairToNum(0, 0, n)] = true;

		while (!q.empty()) {

			int sz = q.size();

			for (int i = 0; i < sz; i++) {

				auto curr = q.front();
				q.pop();

				ll j1 = curr.first, j2 = curr.second;

				if (j1 == d || j2 == d) return count;


				//  fill jug1
				mark(m, j2, n, q, visited);
				//empty jug1
				mark(0, j2, n, q, visited);
				//fill jug2
				mark(j1, n, n, q, visited);
				//empty jug2
				mark(j1, 0, n, q, visited);

				//pour jug2 into jug1
				ll j = j1 + j2; // total water from both jug1 and jug2

				// if j exceeds jug1 cap. then fill it completely and keep the remaining water in jug2
				// else pour j into jug1 and make the jug2 empty.
				mark(j > m ? m : j, j > m ? j2 - (m - j1) : 0, n, q, visited);

				// if j exceeds jug2. cap then fill it completely and keep the remaining water in jug1
				// else pour j into jug2 and make the jug1 empty
				mark(j > n ? j1 - (n - j2) : 0, j > n ? n : j, n, q, visited);


			}

			count++;

		}

		return -1;

	}
};

// t.c. = O(N*M), where n is capacity of jug1 and m is capacity of jug2 because only that many states are possible
// s.c. = O(N*M)


// observation and intuition.
// so i will start with two empty jugs and at every iteration, i will check if in the current state of jugs any one of jug is = target
// then return count else increment count by 1. now check if jug2 becomes empty if it does then fill it completely else if jug1
// becomes full then make it empty else if jug1 + jug2 > capacity of jug1 then fill jug1 completely and keep the remaining water in
// jug2 else if jug1 + jug2 <= capacity of jug1 then pour all water of jug2 in jug1 and make jug2 empty.
// when we reach state where jug1 is = capacity of jug1 and jug2 is = capacity of jug2 then we stop and return -1.
// here we have used jug2 to fill in jug1 similarly we will do like use jug1 to fill jug2 and whichever gives minimum we will take that




class Solution {
public:

	int check(int m, int n, int d) {

		int count = 0;

		int j1 = 0, j2 = 0;


		while (1) {

			if (j1 == d || j2 == d) {
				return count;
			}

			if (j1 == m && j2 == n) return -1;

			count++;


			if (j2 == 0) {
				j2 = n;
			} else if (j1 == m) {
				j1 = 0;
			} else if (j1 + j2 > m) {
				j2 = j2 - (m - j1), j1 = m;
			} else if (j1 + j2 <= m) {
				j1 += j2, j2 = 0;
			}


		}
	}

	int minSteps(int m, int n, int d)
	{


		int mini = min(check(m, n, d), check(n, m, d));

		return mini;

	}
};

// s.c. = O(1)
// t.c. = couldn't figure out but might be O(N*M) if the pairs n and m are co-prime.
