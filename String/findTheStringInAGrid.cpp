// brute force. traverse the matrix and for each character check if that character matches with the first character of word,if not then
// continue else from this character traverse in 8 directions to check if we can form word in any of these 8 direction.
// take two variable nr and nc initialize to i and j i.e. current cordinate of the cell. idx initialize to 0. now continue a while
// loop until idx < sz(word) and nr and nc are within the bounds of matrix and word[idx] == grid[nr][nc],
// at every iteration of while loop update the nr and nc i.e. extend that direction. if we could reach the idx to sz that means we matched
// all characters of word with the cells of matrix in a particular direction, so we insert the current cordinate into the ans and break,
// else we explore other remaining direction.


class Solution {
public:

	int row[8] = {1, -1, 0, 0, -1, 1, -1, 1};
	int col[8] = {0, 0, 1, -1, 1, 1, -1, -1};


	vector<vector<int>>searchWord(vector<vector<char>>grid, string word) {
		// Code here

		vector<vector<int>> ans;
		int n = grid.size(), m = grid[0].size(), sz = word.size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (grid[i][j] == word[0]) {

					for (int k = 0; k < 8; k++) {

						int idx = 0;
						int nr = i, nc = j;

						while (idx < sz && nr >= 0 && nc >= 0 && nr < n && nc < m && word[idx] == grid[nr][nc]) {

							nr += row[k], nc += col[k];
							idx++;
						}

						if (idx == sz) {
							ans.push_back({i, j});
							break;
						}

					}

				}


			}
		}

		return ans;
	}
};


// t.c. = O(8*min(n,m,sz)*n*m)
// s.c. = O(1)