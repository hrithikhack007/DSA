// using dfs.

// take a counter initialized to 0. traverse the grid from row = 0 to n and in each row from col = 0 to m.
// if the cell is 1 then make a dfs call from that cell.
// at each dfs call mark the current cell as 0. traverse all of its valid adjacent cells which is having value 1.
// after returning from the call increment the counter by 1.

class Solution {
public:

	int row[4] = {1, -1, 0, 0};
	int col[4] = {0, 0, 1, -1};

	void dfs(int r, int c, vector<vector<char>> &grid, int n, int m) {

		grid[r][c] = '0';

		for (int k = 0; k < 4; k++) {

			int nr = row[k] + r, nc = col[k] + c;

			if (nr < n && nc < m && nr >= 0 && nc >= 0 && grid[nr][nc] == '1') {
				dfs(nr, nc, grid, n, m);
			}
		}

	}

	int numIslands(vector<vector<char>>& grid) {

		int n = grid.size(), m = grid[0].size();
		int count = 0;


		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {

				if (grid[i][j] == '1') {
					dfs(i, j, grid, n, m);
					count++;
				}
			}
		}

		return count;

	}
};

// t.c. = O(N*M)
// s.c. = O(N*M)


// using bfs
// take count initialized to 0. traverse the grid . if the cell is 1 then do a bfs from there. take queue insert the current cell and set current
// cell to 0. while queue is not empty, take out the front cell and pop it out of queue get the row and col of that cell traverse all its valid
// adjacent cells and if those cells are 1 then set the val to 0 and push them into queue. after queue becomes empty increment count by 1.


class Solution
{
public:

	int row[4] = { 1,
	               -1,
	               0,
	               0
	             };
	int col[4] = { 0,
	               0,
	               1,
	               -1
	             };

	int numIslands(vector<vector < char>> &grid)
	{

		int n = grid.size(), m = grid[0].size();

		int count = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '1')
				{

					queue<pair<int, int>> q;
					grid[i][j] = '0';
					q.push({ i, j });

					while (!q.empty())
					{

						auto curr = q.front();
						q.pop();

						int r = curr.first, c = curr.second;

						for (int k = 0; k < 4; k++)
						{

							int nr = r + row[k], nc = c + col[k];

							if (nr < n && nc < m && nr >= 0 && nc >= 0 && grid[nr][nc] == '1')
							{
								grid[nr][nc] = '0';
								q.push({ nr, nc });
							}
						}
					}
					count++;
				}
			}
		}

		return count;
	}
};

// t.c. = O(N*M)
// s.c = O(N*M)
