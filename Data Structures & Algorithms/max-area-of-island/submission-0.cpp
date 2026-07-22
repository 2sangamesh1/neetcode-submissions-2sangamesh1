class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int maxarea = 0, area = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    q.push({i, j});
                }
                visited[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    area += 1;
                    for(auto &it : dirs){
                        int nx = x + it.first;
                        int ny = y + it.second;

                        if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                            if(grid[nx][ny] == 1 && visited[nx][ny] == 0) q.push({nx, ny});
                            visited[nx][ny] = 1;
                        } 
                    }
                    if(q.empty()){
                        maxarea = max(area, maxarea);
                        area = 0;
                    }
                }
            }
        }

        return maxarea;
    }
};