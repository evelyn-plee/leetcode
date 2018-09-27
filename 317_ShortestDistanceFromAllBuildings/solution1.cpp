#include<vector>
#include<math>
#include<queue>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int row = grid.size(), col = row ? grid[0].size() : 0;
        vector<vector<int>> distances(row, vector<int>(col, 0));
        vector<vector<int>> reachability(row, vector<int>(col, 0));
        vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int building = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    int distance = 1;
                    while (!q.empty()) {
                        int size = q.size();
                        for (int k = 0; k < size; ++k) {
                            auto cur = q.front();
                            q.pop();
                            for (auto d : dirs) {
                                int ii = cur.first + d.first;
                                int jj = cur.second + d.second;
                                if (ii >= 0 && ii < row && jj >= 0 && jj < col
                                    && grid[ii][jj] == 0 && reachability[ii][jj] == building) {
                                    q.emplace(ii, jj);
                                    ++reachability[ii][jj];
                                    distances[ii][jj] += distance;
                                }
                            }
                        }
                        ++distance;
                    }
                    ++building;
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (reachability[i][j] == building) {
                    res = min(res, distances[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
