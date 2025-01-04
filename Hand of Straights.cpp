class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int,int> map;
        for(auto i : hand){
            map[i]++;
        }
        while(!map.empty()){
            int start=map.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(map[start+i]==0)return false;
                else map[start+i]--;
                if(map[start+i]==0) map.erase(start+i);
            }
        }
        return true;
        
    }
};
/// 1 2 2 3 3 4 6 7 8 
/// 1 2 3 4 5
///