/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the
 * cell.
 *     // Returns false if the cell in front is blocked and robot stays in the
 * current cell. bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
 public:
  static constexpr array<pair<int, int>, 4> kDirs = {
      {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};

  void cleanRoom(Robot &robot) {
    unordered_map<int, unordered_set<int>> vis;
    vis[0].insert(0);
    robot.clean();
    for (int dir = 0; dir < kDirs.size(); ++dir) {
      const auto [x, y] = kDirs[dir];
      if (!vis[x].count(y) && robot.move()) {
        solve(robot, vis, x, y, dir);
        robot.move();
        robot.turnLeft();
      } else {
        robot.turnRight();
      }
    }
  }

 private:
  void solve(Robot &robot, unordered_map<int, unordered_set<int>> &vis, int x,
             int y, int dir) {
    vis[x].insert(y);
    robot.clean();
    robot.turnLeft();
    for (int i = -1; i <= 1; ++i) {
      const int next_dir = (dir + i + kDirs.size()) % kDirs.size();
      const auto [dx, dy] = kDirs[next_dir];
      const int next_x = x + dx;
      const int next_y = y + dy;
      if (!vis[next_x].count(next_y) && robot.move()) {
        solve(robot, vis, next_x, next_y, next_dir);
        robot.move();
        robot.turnLeft();
      } else {
        robot.turnRight();
      }
    }
  }
};
