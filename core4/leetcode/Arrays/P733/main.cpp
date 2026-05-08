#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution_Recursion {
public:

    void dfs(vector<vector<int>>& image,
             int sr,
             int sc,
             int originalColor,
             int newColor,
             int rows,
             int cols) {

        // 1. Boundary check
        if (sr < 0 || sr >= rows || sc < 0 || sc >= cols)
            return;

        // 2. Stop if not original color
        if (image[sr][sc] != originalColor)
            return;

        // 3. Fill current cell
        image[sr][sc] = newColor;

        // 4. Recurse in 4 directions
        dfs(image, sr - 1, sc, originalColor, newColor, rows, cols);
        dfs(image, sr + 1, sc, originalColor, newColor, rows, cols);
        dfs(image, sr, sc - 1, originalColor, newColor, rows, cols);
        dfs(image, sr, sc + 1, originalColor, newColor, rows, cols);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr,
                                   int sc,
                                   int color) {

        int rows = image.size();
        int cols = image[0].size();

        int originalColor = image[sr][sc];

        // Edge case: nothing to change
        if (originalColor == color)
            return image;

        dfs(image, sr, sc, originalColor, color, rows, cols);

        return image;
    }
};

class Solution_BFS {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();

        int originalColor = image[sr][sc];
        if (originalColor == color)
            return image;  // Nothing to change

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        // Direction vectors: Up, Down, Left, Right
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    image[nr][nc] == originalColor) {

                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};



int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1, sc = 1, newColor = 2;

    Solution_Recursion sol;
    vector<vector<int>> res = sol.floodFill(image, sr, sc, newColor);

    cout << "Flood Filled Image:\n";
    for (auto row : res) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}



