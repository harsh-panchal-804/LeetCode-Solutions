class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<int,char>> freq(26,{0,'*'});
        for(auto i : word){
            freq[i-'a'].first+=1;
            freq[i-'a'].second=i;
        }
        sort(freq.begin(),freq.end(),[](pair<int,char> &a,pair<int,char>&b){
            return a.first>b.first;
        });
        int itr=0;
        int step=1;
        int cnt=0;
        while(itr<26&&freq[itr].first!=0){
            freq[itr].first=step;
            ++cnt;
            if(cnt==8){
                ++step;
                cnt=0;
            }
            itr++;
        }
        unordered_map<char,int> map;
        for(auto i : freq){
            map[i.second]=i.first;
        }
        // for(auto i : freq){
        //     cout<<i.second<<"->"<<i.first<<"\n";
        // }
        int ans=0;
        for(auto i : word){
            ans+=map[i];
        }
        return ans;
        
        
        
    }
};