// brute force. we will consider each character in the matrix as a starting point of the target word. we will make a recursion call from that
// char. at each call we will check if the current char is equal to the target's idxth character , if not we will simply return
// else we will explore all 4 directions from the current cell and make a call on them. before calling we will mark the current cell
// as '*' because we don't want to revisit this cell from future calls. if the new cell is within bounds and not containing '*' char
// we will make a call on that cell with new cell row and column and increment target's idx by 1 . before returning we will unmarked
// the current cell with it's orignal character.

class Solution {
public:

	int row[4] = {1, -1, 0, 0};
	int col[4] = {0, 0, 1, -1};

	void rec(int idx, string &target, vector<vector<char>> &mat, int &count, int i, int j) {


		if (mat[i][j] == target[idx]) {

			if (idx == target.size() - 1) {
				count++;
				return;
			}

			for (int k = 0; k < 4; k++) {

				int nr = i + row[k], nc = col[k] + j;
				mat[i][j] = '*';

				if (nr >= 0 && nc >= 0 && nr < mat.size() && nc < mat[i].size() && mat[nr][nc] != '*') {
					rec(idx + 1, target, mat, count, nr, nc);

				}

				mat[i][j] = target[idx];

			}

		} else {
			return;
		}


	}

	int findOccurrence(vector<vector<char> > &mat, string target) {


		int count = 0;
		int n = mat.size();

		for (int i = 0; i < n; i++) {
			int r = i;
			for (int j = 0; j < mat[r].size(); j++) {

				rec(0, target, mat, count, i, j);
			}
		}


		return count;

	}
};


// t.c. = O(3^(|target|-1) * (N*M))
// s.c. = O(min(|target|,(N*M))) => stack space
