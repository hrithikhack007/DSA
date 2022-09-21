// no need to use trie here.
// simply traverse each row create a string out of row and while creating store the numbers in vector.
// after traversing  a row check in the map if it is present in the map or not if it is present then simply continue else mark it and push
// the vector of row in ans.


vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{

    unordered_map<string, bool> mp;

    vector<vector<int>> ans;

    for (int i = 0; i < row; i++) {

        string t = "";
        vector<int> row;
        for (int j = 0; j < col; j++) {
            row.push_back(M[i][j]);
            t.push_back(char('0' + M[i][j]));
        }

        if (mp[t]) continue;

        mp[t] = true;
        ans.push_back(row);


    }

    return ans;


}

// t.c. = O(M*N)
// s.c. = O(M*N)