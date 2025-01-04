class Solution {
public:
    bool isPathCrossing(string path) {
        map<char,pair<int,int>> map;
        map['N']={0,1};
        map['S']={0,-1};
        map['E']={1,0};
        map['W']={-1,0};
        set<pair<int,int>> set;
        int x=0;
        int y=0;
        pair p1(0,0);
        set.insert(p1);
        for(auto i:path){
            x+=map[i].first;
            y+=map[i].second;
            pair<int,int> p2(x,y);
            if(set.count(p2)>0){
                return true;
            }
            set.insert(p2);
        }
        return false;

    }
};