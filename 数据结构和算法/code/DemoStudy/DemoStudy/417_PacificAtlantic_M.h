#include "LeetCode.h"


class PacificAtlantic_M:public LeetCode
{
public:
	void Demo()
	{
		vector<vector<int>> matrix(5, vector<int>(5,0));
		matrix[0][0] = 1;
		matrix[0][1] = 2;
		matrix[0][2] = 2;
		matrix[0][3] = 3;
		matrix[0][4] = 5;

		matrix[1][0] = 3;
		matrix[1][1] = 2;
		matrix[1][2] = 3;
		matrix[1][3] = 4;
		matrix[1][4] = 4;

		matrix[2][0] = 2;
		matrix[2][1] = 4;
		matrix[2][2] = 5;
		matrix[2][3] = 3;
		matrix[2][4] = 1;

		matrix[3][0] = 6;
		matrix[3][1] = 7;
		matrix[3][2] = 1;
		matrix[3][3] = 4;
		matrix[3][4] = 5;

		matrix[4][0] = 5;
		matrix[4][1] = 1;
		matrix[4][2] = 1;
		matrix[4][3] = 2;
		matrix[4][4] = 4;

		pacificAtlantic(matrix);
	}

	// Ö÷º¯Êý
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return {};
		}

		vector<vector<int>> ans;
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
		vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			dfs(matrix, can_reach_p, i, 0);
			dfs(matrix, can_reach_a, i, n - 1);
		}
		for (int i = 0; i < n; ++i) {
			dfs(matrix, can_reach_p, 0, i);
			//PrintArray();
			dfs(matrix, can_reach_a, m - 1, i);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; ++j) {
				if (can_reach_p[i][j] && can_reach_a[i][j]) {
					ans.push_back(vector<int>{i, j});
				}
			}
		}
		return ans;
	}
	 
	// ¸¨º¯Êý
	void dfs(const vector<vector<int>>& matrix, vector<vector<bool>>& can_reach,int r, int c) {
		if (can_reach[r][c]) {
			return;
		}
		can_reach[r][c] = true;
		int x, y;
		for (int i = 0; i < 4; ++i) {
			x = r + direction[i], y = c + direction[i + 1];
			if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[r][c] <= matrix[x][y]) {
				dfs(matrix, can_reach, x, y);
			}
		}
	}

private:
	vector<int> direction{ -1, 0, 1, 0, -1 };
};








