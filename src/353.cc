class SnakeGame {
 public:
  SnakeGame(int width, int height, vector<vector<int>>& food)
      : m_(height), n_(width), food_(food.rbegin(), food.rend()), rows_(m_) {
    snake_.emplace_back(0, 0);
    rows_[0].insert(0);
  }

  int move(string direction) {
    assert(direction.size() == 1);
    int di = 0, dj = 0;
    if (direction[0] == 'L') {
      dj = -1;
    } else if (direction[0] == 'R') {
      dj = 1;
    } else if (direction[0] == 'U') {
      di = -1;
    } else {
      di = 1;
    }
    const int next_i = snake_.back().first + di;
    const int next_j = snake_.back().second + dj;
    if (next_i < 0 || next_i >= m_ || next_j < 0 || next_j >= n_) {
      return -1;
    }
    if (!food_.empty() && food_.back()[0] == next_i &&
        food_.back()[1] == next_j) {
      food_.pop_back();
      snake_.emplace_back(next_i, next_j);
      rows_[next_i].insert(next_j);
      return snake_.size() - 1;
    }
    rows_[snake_.front().first].erase(snake_.front().second);
    snake_.pop_front();
    if (rows_[next_i].count(next_j) > 0) {
      return -1;
    }
    rows_[next_i].insert(next_j);
    snake_.emplace_back(next_i, next_j);
    return snake_.size() - 1;
  }

 private:
  const int m_;
  const int n_;
  vector<vector<int>> food_;
  vector<unordered_set<int>> rows_;
  deque<pair<int, int>> snake_;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
