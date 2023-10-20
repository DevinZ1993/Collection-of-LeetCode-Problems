class Solution {
 public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                     vector<vector<string>>& people) {
    const int m = req_skills.size();
    unordered_map<string, int> indices;
    for (int i = 0; i < m; ++i) {
      indices.emplace(req_skills[i], i);
    }
    struct State {
      int val = INT_MAX;
      int person_index = -1;
      int prev_state = -1;
    };
    vector<State> dp(1 << m);
    dp[0].val = 0;
    for (int person_index = 0; person_index < people.size(); ++person_index) {
      int skills = 0;
      for (const string& skill : people[person_index]) {
        auto it = indices.find(skill);
        if (it == indices.end()) {
          continue;
        }
        skills |= (1 << it->second);
      }
      for (int state = dp.size() - 1; state >= 0; --state) {
        if (dp[state].val == INT_MAX) {
          continue;
        }
        const int next_state = (state | skills);
        if (dp[next_state].val > dp[state].val + 1) {
          dp[next_state].val = dp[state].val + 1;
          dp[next_state].person_index = person_index;
          dp[next_state].prev_state = state;
        }
      }
    }
    assert(dp.back().val <= m);
    vector<int> results;
    results.reserve(dp.back().val);
    for (int state = (1 << m) - 1; state > 0; state = dp[state].prev_state) {
      results.emplace_back(dp[state].person_index);
    }
    return results;
  }
};
