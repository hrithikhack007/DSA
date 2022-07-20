// backtracking.
// take string path and vector of string paths. make a func. call starting from r = 0 and c = 0. at each func. call check if mat[r][c]
// == 0 if yes then return , if r and n == n-1 store the path in paths array and return else mark the current cell as -1 which
// indicates visited ,explore all 4 direction from this cell.
// if the new cell is withing the bound and new cell is not -1 then push the dir. character in path , and make a call to new cell after
// returning  pop the dir. character from path. before returning from this current cell, make current cell to 1 i.e. mark it unvisited.
class Solution {
public:

	int row[4] = {1, 0, 0, -1};
	int col[4] = {0, -1, 1, 0};
	char dir[4] = {'D', 'L', 'R', 'U'};

	void rec(int r, int c, vector<vector<int>> &mat, vector<string> &paths, string &path, int n) {

		if (mat[r][c] == 0) return;


		if (r == n - 1 && c == n - 1) {
			paths.push_back(path);
			return;
		}

		mat[r][c] = -1;


		for (int k = 0; k < 4; k++) {

			int nr = r + row[k], nc = c + col[k];
			if (nr < n && nc < n && nr >= 0 && nc >= 0 && mat[nr][nc] != -1) {
				path.push_back(dir[k]);
				rec(nr, nc, mat, paths, path, n);
				path.pop_back();
			}



		}

		mat[r][c] = 1;



	}

	vector<string> findPath(vector<vector<int>> &m, int n) {

		string path = "";
		vector<string> paths;

		int cnt = 0;

		rec(0, 0, m, paths, path, n);

		return paths;


	}
};


// t.c. = O(3^(N^2))
// s.c. = O(3^(N^2))
// s.c. without including path space : O(N^2) maximum path length can be N^2