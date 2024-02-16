class Solution {
 public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    priority_queue<pair<int, int>> free_servers;
    for (int i = 0; i < servers.size(); ++i) {
      free_servers.emplace(-servers[i], -i);
    }
    priority_queue<pair<int, int>> occupied_servers;
    vector<int> results(tasks.size());
    int time = 0;
    for (int index = 0; index < tasks.size(); ++index) {
      time = max(time, index);
      if (free_servers.empty()) {
        time = max(time, -occupied_servers.top().first);
      }
      while (!occupied_servers.empty() &&
             -occupied_servers.top().first <= time) {
        int server_index = occupied_servers.top().second;
        occupied_servers.pop();
        free_servers.emplace(-servers[server_index], -server_index);
      }
      results[index] = -free_servers.top().second;
      free_servers.pop();
      occupied_servers.emplace(-time - tasks[index], results[index]);
    }
    return results;
  }
};
