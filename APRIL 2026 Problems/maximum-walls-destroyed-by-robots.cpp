class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<pair<int, int>> robotInfo(n);
        for (int i = 0; i < n; i++) {
            robotInfo[i] = {robots[i], distance[i]};
        }
      
        ranges::sort(robotInfo, {}, &pair<int, int>::first);
        ranges::sort(walls);
      
        // DP memoization table
        vector<vector<int>> dp(n, vector<int>(2, -1));
        auto solve = [&](this auto&& solve, int robotIdx, int prevDirection) -> int {
            if (robotIdx < 0) {
                return 0;
            }
            if (dp[robotIdx][prevDirection] != -1) {
                return dp[robotIdx][prevDirection];
            }
          
            int maxDestroyed = 0;
          
            // Option 1: Current robot moves LEFT
            // Calculate the leftmost position this robot can reach
            int leftBound = robotInfo[robotIdx].first - robotInfo[robotIdx].second;
          
            // Ensure no overlap with previous robot (if exists)
            if (robotIdx > 0) {
                leftBound = max(leftBound, robotInfo[robotIdx - 1].first + 1);
            }
          
            // Count walls that can be destroyed when moving left
            int leftWallIdx = ranges::lower_bound(walls, leftBound) - walls.begin();
            int rightWallIdx = ranges::lower_bound(walls, robotInfo[robotIdx].first + 1) - walls.begin();
            int wallsDestroyedLeft = rightWallIdx - leftWallIdx;
          
            // Recurse for previous robots (current robot chose left, so prev can choose any direction)
            maxDestroyed = solve(robotIdx - 1, 0) + wallsDestroyedLeft;
          
            // Option 2: Current robot moves RIGHT
            // Calculate the rightmost position this robot can reach
            int rightBound = robotInfo[robotIdx].first + robotInfo[robotIdx].second;
          
            // Ensure no overlap with next robot (if exists)
            if (robotIdx + 1 < n) {
                if (prevDirection == 0) {
                    // If next robot will move left, consider its leftmost reach
                    rightBound = min(rightBound, robotInfo[robotIdx + 1].first - robotInfo[robotIdx + 1].second - 1);
                } else {
                    // If next robot will move right, just avoid its starting position
                    rightBound = min(rightBound, robotInfo[robotIdx + 1].first - 1);
                }
            }
          
            // Count walls that can be destroyed when moving right
            leftWallIdx = ranges::lower_bound(walls, robotInfo[robotIdx].first) - walls.begin();
            rightWallIdx = ranges::lower_bound(walls, rightBound + 1) - walls.begin();
            int wallsDestroyedRight = rightWallIdx - leftWallIdx;
          
            // Recurse for previous robots (current robot chose right, so pass direction = 1)
            maxDestroyed = max(maxDestroyed, solve(robotIdx - 1, 1) + wallsDestroyedRight);
          
            // Store and return the result
            dp[robotIdx][prevDirection] = maxDestroyed;
            return maxDestroyed;
        };
      
        // Start solving from the last robot, assuming it moves right
        // (The last robot's direction doesn't affect next robots since there are none)
        return solve(n - 1, 1);
    }
};