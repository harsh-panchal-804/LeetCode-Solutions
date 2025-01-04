class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vec;
        priority_queue<int,vector<int>> pq;
        for(int i=0;i<profits.size();i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        int i=0;
        while(i<profits.size()&&vec[i].first<=w){
            pq.push(vec[i].second);
            i++;
        }
        if(pq.empty())return 0;
        int ans=0;
        while( !pq.empty() &&k>0){
            ans+=pq.top();
            w+=pq.top();
            pq.pop();
            k--;
            while(i<profits.size()&& vec[i].first<=w){
                pq.push(vec[i].second); 
                i++;
            }

        }
        return w;
        
    }
};