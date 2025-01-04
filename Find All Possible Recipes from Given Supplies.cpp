class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();

   
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> in_degree;

    for (int i = 0; i < n; ++i) {
        for (const string& ingredient : ingredients[i]) {
            graph[ingredient].push_back(recipes[i]);
            in_degree[recipes[i]]++;
        }
    }

  
    queue<string> q;
    for (const string& item : supplies) {
        q.push(item);
    }

    vector<string> res;

    
    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        
        if (find(recipes.begin(), recipes.end(), curr) != recipes.end()) {
            res.push_back(curr);
        }

        for (const string& nxt : graph[curr]) {
            in_degree[nxt]--;
            if (in_degree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    return res;
        
    }
};