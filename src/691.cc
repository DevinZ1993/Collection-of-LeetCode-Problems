class Solution {
 public:
  int minStickers(vector<string> &stickers, string target) {
    using Counter = array<int, 26>;

    Counter target_counter{};
    for (char ch : target) {
      ++target_counter[ch - 'a'];
    }

    vector<Counter> sticker_cnts(stickers.size());
    for (int i = 0; i < stickers.size(); ++i) {
      for (char ch : stickers[i]) {
        ++sticker_cnts[i][ch - 'a'];
      }
    }

    struct CounterHash {
      size_t operator()(const Counter &counter) const {
        static hash<int> hasher;
        size_t result = 0;
        for (int i = 0; i < counter.size(); ++i) {
          result = 31 * result + hasher(counter[i]);
        }
        return result;
      }
    };
    unordered_map<Counter, int, CounterHash> dists;
    dists[Counter{}] = 0;
    deque<Counter> q;
    q.emplace_back();
    while (!q.empty()) {
      const Counter counter = q.front();
      q.pop_front();
      const int dist = dists.at(counter);
      if (counter == target_counter) {
        return dist;
      }
      Counter next_counter;
      for (const Counter &sticker_cnt : sticker_cnts) {
        for (int i = 0; i < counter.size(); ++i) {
          next_counter[i] = min(target_counter[i], counter[i] + sticker_cnt[i]);
        }
        auto it = dists.find(next_counter);
        if (it != dists.end()) {
          continue;
        }
        dists[next_counter] = dist + 1;
        q.push_back(next_counter);
      }
    }
    return -1;
  }
};
