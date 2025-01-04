class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;
        unordered_map<int,int> map;
        for(auto &i : skill)map[i]++;
        int n=skill.size();
        int sum=accumulate(skill.begin(),skill.end(),0);

        ////if(sum&1 && n>2)return -1; 70
      
        int no_teams=n/2;

        int score_team=sum/no_teams;
        if(sum%no_teams)return -1;
        for(auto &i : skill){
            int comp=score_team-i;
            if(map[comp]<=0)return -1;
            ans+=(i*comp);
            ///map[i]--;
            if(map.count(i)<=0)map.erase(i);
            map[comp]--;
            if(map.count(comp)<=0)map.erase(comp);
        }
        return ans/2;
    }
};