class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }

        vector<vector<int>> itemGraph(n);
        vector<int> itemIndegree(n, 0);
        vector<vector<int>> groupGraph(m);
        vector<int> groupIndegree(m, 0);
        vector<vector<int>> groupItems(m);

        for (int i = 0; i < n; i++) {
            groupItems[group[i]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            for (int pre : beforeItems[i]) {
                if (group[i] == group[pre]) {
                    itemGraph[pre].push_back(i);
                    itemIndegree[i]++;
                } else { 
                    groupGraph[group[pre]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        vector<int> sortedGroups = topoSort(groupGraph, groupIndegree, m);
        if (sortedGroups.empty()) return {};

        vector<int> result;
        for (int grp : sortedGroups) {
            vector<int> items = groupItems[grp];
            vector<int> sortedItems = topoSortSubGraph(itemGraph, itemIndegree, items);
            if (sortedItems.size() != items.size()) return {};
            for (int item : sortedItems) {
                result.push_back(item);
            }
        }

        return result;
    }

    vector<int> topoSort(vector<vector<int>>& graph, vector<int>& indegree, int totalNodes) {
        queue<int> q;
        vector<int> order;
        for (int i = 0; i < totalNodes; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            order.push_back(cur);
            for (int neighbor : graph[cur]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return (order.size() == totalNodes) ? order : vector<int>{};
    }

    vector<int> topoSortSubGraph(vector<vector<int>>& itemGraph, vector<int> baseIndegree, vector<int>& items) {
        queue<int> q;
        vector<int> order;
        for (int item : items) {
            if (baseIndegree[item] == 0) {
                q.push(item);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            order.push_back(cur);
            for (int neighbor : itemGraph[cur]) {
                baseIndegree[neighbor]--;
                if (baseIndegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return order;
    }
};
