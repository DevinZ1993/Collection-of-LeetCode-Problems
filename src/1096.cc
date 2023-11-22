class Solution {
 public:
  vector<string> braceExpansionII(string expression) {
    vector<State> states(1);
    for (char ch : expression) {
      if (ch == '{') {
        states.emplace_back();
      } else if (ch == '}') {
        states.back().reduce();
        auto subs = move(states.back().sum);
        states.pop_back();
        assert(!states.empty());
        states.back().product.push_back(move(subs));
        states.back().product.emplace_back(1);
      } else if (ch == ',') {
        states.back().reduce();
      } else {
        if (states.back().product.empty() ||
            states.back().product.back().size() > 1) {
          states.back().product.emplace_back(1);
        }
        states.back().product.back().back().push_back(ch);
      }
    }
    assert(states.size() == 1);
    states[0].reduce();
    auto results = move(states[0].sum);
    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());
    return results;
  }

 private:
  struct State {
    void reduce() {
      vector<tuple<int, int, int>> stk;
      stk.emplace_back(0, -1, 0);
      string buffer;
      while (!stk.empty()) {
        const auto [index, sub_index, state] = stk.back();
        stk.pop_back();
        if (index == product.size()) {
          sum.push_back(buffer);
          continue;
        }
        if (state == 0) {
          for (int i = 0; i < product[index].size(); ++i) {
            stk.emplace_back(index, i, 1);
          }
        } else if (state == 1) {
          stk.emplace_back(index, sub_index, 2);
          buffer.append(product[index][sub_index]);
          stk.emplace_back(index + 1, -1, 0);
        } else {
          buffer.resize(buffer.size() - product[index][sub_index].size());
        }
      }
      assert(buffer.empty());
      product.clear();
    }

    vector<string> sum;
    vector<vector<string>> product;
  };
};
