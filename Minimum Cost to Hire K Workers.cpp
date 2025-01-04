class Solution {
public:
    static bool cmp(pair<pair<int,int>,double>& a,pair<pair<int,int>,double>&b){
        return a.second<b.second;
    }
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<pair<int,int>,double>> map;/// quality wage qw
        for(int i=0;i<quality.size();i++){
            double d=(double)wage[i]/quality[i];
            map.push_back({{quality[i],wage[i]},d});
        }
        sort(map.begin(),map.end(),cmp);
        for(auto i : map){
            cout<<i.first.first<<" "<<i.first.second<<" "<<i.second;
            cout<<endl;
        }
        priority_queue<int> heap;
        int qual=0;
        double rate=0.0;
        // hamara assumed ans
        for(int i=0;i<k;i++){
            qual+=map[i].first.first;
            rate=max(rate,map[i].second);
            heap.push(map[i].first.first);
        }
        double ans=rate*qual;
        for(int i=k;i<map.size();i++){
            // remove max qual
            qual-=heap.top();
            heap.pop();
            rate=max(rate,map[i].second);
            qual+=map[i].first.first;
            heap.push(map[i].first.first);
            ans=min(ans,qual*rate);
        }
       
       

        return ans;




        
    }
};