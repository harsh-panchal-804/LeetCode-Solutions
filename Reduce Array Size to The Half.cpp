class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> map;
        for(auto i : arr) map[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto i : map){
            pq.push({i.second,i.first});
        }
        int count=0;
        while(!pq.empty()){
            int fr=pq.top().first;
            pq.pop();
            if(n<=arr.size()/2)return count;
            count++;
            n-=fr;
        }
        return count;

        
    }
};