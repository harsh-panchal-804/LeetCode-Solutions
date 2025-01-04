class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<char,char> map;
        for(int i=0;i<mapping.size();i++){
            map[i+'0']=mapping[i]+'0';
        }
        vector<pair<int,int>> vec;
        unordered_map<int,int> map2;
        for(auto &w:nums){
            string temp=to_string(w);
            for(auto &ch:temp){
                ch=map[ch];
            }
            map2[w]=stoi(temp);
        }
        stable_sort(nums.begin(),nums.end(),[&](int a,int b){
            return map2[a]<map2[b];
        });
            
        return nums;
        
    }
};