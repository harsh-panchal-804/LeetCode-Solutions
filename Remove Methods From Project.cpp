class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
         vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> ans;
        
 
        for (auto& i : invocations) {
            int u = i[0], v = i[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        
        vector<int> sus(n, 0); 
        unordered_set<int> reachable; 
        
     
        function<void(int)> bfs = [&](int src) {
            queue<int> queue;
            sus[src] = 1;
            queue.push(src);
            while (!queue.empty()) {
                int node = queue.front();
                queue.pop();
                reachable.insert(node);  
                for (auto child : adj[node]) {
                    if (!sus[child]) {
                        sus[child] = 1;
                        queue.push(child);
                    }
                }
            }
        };
        bfs(k);
        
       
        for (int i = 0; i < n; i++) {
            if (!sus[i]) {
                ans.push_back(i); 
            }
        }

        
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (!sus[i]) {
                for (auto child : adj[i]) {
                    if (reachable.find(child) != reachable.end()) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
        }

       
        if (!flag) return ans;

     
        for (int i = 0; i < n; i++) {
            if (sus[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};