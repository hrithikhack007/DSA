// dfs.

// if the oldColor is same as newColor return the image array as it is. make a rec func. call with the source cell and old color as the
// color of source cell and newcolor as the given color we want to update the old color with. at each func. call we will check if the color
// of the cell matches with the old color if it does then we update this current's cell color to new color and explore all 4 direction from
// this cell.

// this works because after updating the cell color to newcolor we know that old color is not equal to new color so when the same cell
// is visited again the condition becomes false automatically and func. call ends there so by updating to new color of cell we don't
// need to keep visited array.

class Solution {
public:

	int row[4] = {1, -1, 0, 0};
	int col[4] = {0, 0, 1, -1};

	void rec(int r, int c, vector<vector<int>> &image, int newColor, int oldColor) {

		if (image[r][c] == oldColor) {
			image[r][c] = (newColor);

			for (int k = 0; k < 4; k++) {

				int nr = r + row[k], nc = c + col[k];

				if (nr < image.size() && nc < image[0].size() && nr >= 0 && nc >= 0) {
					rec(nr, nc, image, newColor, oldColor);
				}
			}
		}


	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

		if (image[sr][sc] == color) return image;

		rec(sr, sc, image, color, image[sr][sc]);

		return image;

	}
};


// t.c. = O(N*M)
// s.c. = O(N*M)

// using bfs

// first check edge case: if source cell color matched with color then return image as it is else it will create tle.
// take a queue. push the source cell into it.
// while q is not empty, take out the front cell, check if its color matches with old color if it does then assign new color to this cell
// and explore all 4 direction from this cell and push valid cells into queue.

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

	vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
	{

		if (image[sr][sc] == color) return image;

		int n = image.size(), m = image[0].size();
		int oldColor = image[sr][sc];

		queue<pair<int, int>> q;

		q.push({ sr,
		         sc
		       });

		while (!q.empty())
		{

			auto cell = q.front();

			q.pop();

			int r = cell.first, c = cell.second;

			if (image[r][c] == oldColor)
			{

				image[r][c] = color;

				for (int k = 0; k < 4; k++)
				{

					int nr = r + row[k], nc = c + col[k];

					if (nr < n && nc < m && nr >= 0 && nc >= 0)
					{
						q.push({ nr,
						         nc
						       });
					}
				}
			}
		}

		return image;
	}
};

// t.c. = O(N*M)
// s.c. O(N*M)






