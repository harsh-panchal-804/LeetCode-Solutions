class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string,int> map;
        for(int i=0;i<list1.size();i++){
            for(int j=0;j<list2.size();j++){
                if(list1[i]==list2[j]){
                    map[list1[i]]=i+j;
                }
            }
        }
        int ans=INT_MAX;
        for(auto i:map){
            ans=min(ans,i.second);
        }
        vector<string>vec;
        for(auto i: map){
            if(i.second==ans){
                vec.push_back(i.first);
            }
        }
        return vec;
    }
};