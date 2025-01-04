class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for(auto i: timePoints){
            string h=i.substr(0,2);
            int hr;
            if(h=="00")hr=24;
            else hr=stoi(h);
            hr*=60;
            string m=i.substr(3,2);
            int mi=stoi(m);
            mins.push_back(hr+mi);
            mins.push_back(hr+mi+1440);
        }
        sort(mins.begin(),mins.end());
        int ans=INT_MAX;
        for(int i=1;i<mins.size();i++){
            ans=min(ans,mins[i]-mins[i-1]);
        }
        for(auto i : mins){
            cout<<i<<" ";
        }
        return ans;
        
    }
};