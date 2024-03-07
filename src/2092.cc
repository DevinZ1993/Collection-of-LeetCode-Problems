class Solution {
 public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    vector<int> states(n, 0);
    states[0] = states[firstPerson] = 1;
    vector<int> roots(n, -1);
    unordered_set<int> attendees;
    sort(meetings.begin(), meetings.end(),
         [](const auto &lhs, const auto &rhs) { return lhs[2] < rhs[2]; });
    for (int i = 0, j = 1; j <= meetings.size(); ++j) {
      if (j == meetings.size() || meetings[j][2] > meetings[i][2]) {
        attendees.clear();
        for (int k = i; k < j; ++k) {
          unionByRank(roots, meetings[k][0], meetings[k][1]);
          attendees.insert(meetings[k][0]);
          attendees.insert(meetings[k][1]);
          if (states[meetings[k][0]] == 1) {
            unionByRank(roots, meetings[k][0], 0);
          }
          if (states[meetings[k][1]] == 1) {
            unionByRank(roots, meetings[k][1], 0);
          }
        }
        for (int attendee : attendees) {
          if (getRoot(roots, attendee) == getRoot(roots, 0)) {
            states[attendee] = 1;
          }
        }
        for (int attendee : attendees) {
          roots[attendee] = -1;
        }
        roots[0] = -1;
        i = j;
      }
    }
    vector<int> results;
    for (int i = 0; i < n; ++i) {
      if (states[i] == 1) {
        results.push_back(i);
      }
    }
    return results;
  }

 private:
  void unionByRank(vector<int> &roots, int i, int j) {
    i = getRoot(roots, i);
    j = getRoot(roots, j);
    if (i == j) {
      return;
    }
    if (roots[i] > roots[j]) {
      swap(i, j);
    }
    roots[i] += roots[j];
    roots[j] = i;
  }
  int getRoot(vector<int> &roots, int i) {
    if (roots[i] < 0) {
      return i;
    }
    return roots[i] = getRoot(roots, roots[i]);
  }
};
