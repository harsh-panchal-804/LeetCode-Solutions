class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> map;
        for(int i=0;i<tops.size();i++){
            if(tops[i]==bottoms[i])map[tops[i]]++;
            else {
                map[tops[i]]++;
                map[bottoms[i]]++;
            }
        }
        int x;
        bool flag=false;
        for(auto & i : map){
            if(i.second>=tops.size()){
                x=i.first;
                flag=true;
                break;
            }
        }
        if(!flag) return -1;
        int a=0;
        int b=0;
        for(auto i : tops){
            if(i!=x)a++;
        }
        for(auto i : bottoms){
            if(i!=x)b++;
        }
        return min(a,b);
        
    }
};