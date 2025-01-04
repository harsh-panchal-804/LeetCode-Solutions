class Solution {
public:
    int romanToInt(string s) {
        map<char,int> map;
        map['M']=1000;
        map['X']=10;
        map['C']=100;
        map['I']=1;
        map['L']=50;
        map['V']=5;
        map['D']=500;
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            if(map[s[i]]>=map[s[i+1]]){
                sum+=map[s[i]];
            }
            else{
                sum-=map[s[i]];
            }
        }
        return sum+map[s[s.size()-1]];
        
    }
};