// bfs
// take queue and distance array. intialize distance array with max value. push the source cell into queue and make source cell value
// in distace array to 0. while queue is not empty, take the front element and pop it out check if the current cell is the target cell of
// it is then return its distance , from the current cell explore all possible valid 8 cells if dist. of curr cell + 1 < dist. of new cell
// then update the distance of new cell and push it into queue. after queue becomes empty return -1 because we could reach target cell.

class Solution
{
public:

	int row[8] = {1, -1, 1, -1, -2, -2, 2, 2};
	int col[8] = { -2, -2, 2, 2, -1, 1, -1, 1};

	//Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&knightPos, vector<int>&TargetPos, int N)
	{
		// Code here

		swap(TargetPos[0], TargetPos[1]);
		swap(knightPos[0], knightPos[1]);

		queue<pair<int, int>> q;
		q.push({knightPos[0], knightPos[1]});

		vector<vector<int>> distance(N + 1, vector<int>(N + 1, 1e9));
		distance[knightPos[0]][knightPos[1]] = 0;

		while (!(q.empty())) {

			auto curr = q.front();


			q.pop();

			int r = curr.first, c = curr.second;

			if (r == TargetPos[0] && c == TargetPos[1]) {
				return distance[r][c];
			}

			for (int k = 0; k < 8; k++) {

				int nr = r + row[k], nc = c + col[k];

				if (nr <= N && nc <= N && nr > 0 && nc > 0 && distance[r][c] + 1 < distance[nr][nc]) {

					distance[nr][nc] = distance[r][c] + 1;
					q.push({nr, nc});
				}

			}
		}


		return -1;



	}
};

// t.c. = O(N^2)
// s.c. = O(N^2)
