class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> vec=score;
        sort(vec.begin(),vec.end(),greater<int>());
        unordered_map<int,string> map;// map number to its medal
        vector<string> list={"Gold Medal","Silver Medal","Bronze Medal"};
        for(int i=0;i<score.size();i++){
            if(i<3){
                map[vec[i]]=list[i];
            }
            else{
                map[vec[i]]=to_string(i+1);
            }
        }
        vector<string> res;
        for(auto i : score){
            res.push_back(map[i]);
        }
        return res;
        
    }
};