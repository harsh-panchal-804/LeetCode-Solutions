#include <vector>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans;
        priority_queue<int> maxHeap;

        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            int dist = abs(x) + abs(y);

            if (maxHeap.size() < k) {
                maxHeap.push(dist);
            } else if (dist < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(dist);
            }

            if (i < k - 1) {
                ans.push_back(-1);
            } else {
                ans.push_back(maxHeap.top());
            }
        }
        return ans;
    }
};
