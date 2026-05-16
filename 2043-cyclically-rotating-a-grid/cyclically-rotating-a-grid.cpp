class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; ++layer) {
            vector<int> elements;

            for (int j = layer; j < n - layer; ++j) {
                elements.push_back(grid[layer][j]);
            }
            for (int i = layer + 1; i < m - layer; ++i) {
                elements.push_back(grid[i][n - layer - 1]);
            }
            for (int j = n - layer - 2; j >= layer; --j) {
                elements.push_back(grid[m - layer - 1][j]);
            }
            for (int i = m - layer - 2; i > layer; --i) {
                elements.push_back(grid[i][layer]);
            }

            int len = elements.size();
            int rotations = k % len;
            if (rotations == 0) continue;

            int idx = rotations;
            for (int j = layer; j < n - layer; ++j) {
                grid[layer][j] = elements[idx];
                idx = (idx + 1) % len;
            }
            for (int i = layer + 1; i < m - layer; ++i) {
                grid[i][n - layer - 1] = elements[idx];
                idx = (idx + 1) % len;
            }
            for (int j = n - layer - 2; j >= layer; --j) {
                grid[m - layer - 1][j] = elements[idx];
                idx = (idx + 1) % len;
            }
            for (int i = m - layer - 2; i > layer; --i) {
                grid[i][layer] = elements[idx];
                idx = (idx + 1) % len;
            }
        }

        return grid;
    }
};