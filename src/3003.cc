class Solution {
 public:
  int maxPartitionsAfterOperations(string s, int k) {
    if (k == 26) {
      return 1;
    }
    const int n = s.size();
    array<int, 26> indices;
    fill(indices.begin(), indices.end(), -1);
    vector<int> sorted_indices;
    sorted_indices.reserve(26);
    vector<array<int, 26>> dp(n);
    for (int i = n - 1; i >= 0; --i) {
      sorted_indices.clear();
      for (int j = 0; j < indices.size(); ++j) {
        if (indices[j] >= 0) {
          sorted_indices.push_back(indices[j]);
        }
      }
      sort(sorted_indices.begin(), sorted_indices.end());

      for (int j = 0; j < dp[i].size(); ++j) {
        if (sorted_indices.size() < k) {
          dp[i][j] = 1;
        } else if (indices[j] >= 0 && indices[j] <= sorted_indices[k - 1]) {
          dp[i][j] = dp[i + 1][s[i + 1] - 'a'];
        } else {
          const int next_index = sorted_indices[k - 1];
          dp[i][j] = 1 + dp[next_index][s[next_index] - 'a'];
        }
      }
      indices[s[i] - 'a'] = i;
    }
    fill(indices.begin(), indices.end(), -1);
    int distinct = 0;
    int result = dp[0][s[0] - 'a'];
    for (int i = 0, j = 0; j <= n; ++j) {
      if (j < n && indices[s[j] - 'a'] < i) {
        ++distinct;
        indices[s[j] - 'a'] = j;
      }
      if ((j == n && distinct == k) || distinct > k) {
        result = max(result, solve(s, dp, i, j));
        i = j;
        distinct = 1;
      }
    }
    return result;
  }

 private:
  int solve(const string &s, const vector<array<int, 26>> &dp, int start_index,
            int end_index) const {
    int state = 0;
    int first_dup = -1;
    int last = -1;
    for (int i = start_index; i < end_index; ++i) {
      if (state & (1 << (s[i] - 'a'))) {
        if (first_dup < 0) {
          first_dup = i;
        }
      } else {
        last = i;
        state |= (1 << (s[i] - 'a'));
      }
    }
    const int original_val = dp[0][s[0] - 'a'];
    const int end_val =
        end_index == s.size() ? 0 : dp[end_index][s[end_index] - 'a'];
    if (first_dup < 0) {
      return original_val;
    }
    int result = original_val;
    if (first_dup < last) {
      result = max(result, original_val + dp[last][s[last] - 'a'] - end_val);
    }
    for (int i = max(last + 1, first_dup); i < end_index; ++i) {
      for (int j = 0; j < dp[i].size(); ++j) {
        if (state & (1 << j)) {
          continue;
        }
        result = max(result, original_val + dp[i][j] - end_val);
      }
    }
    return result;
  }
};
