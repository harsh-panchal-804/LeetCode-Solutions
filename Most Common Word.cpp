class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        string str="";
        vector<string> ans;
        for(auto & i: paragraph){
            i=ispunct(i)? ' ': tolower(i);
        }
        stringstream ss(paragraph);
        while(getline(ss,str,' ')){
            ans.push_back(str);
            cout<<str<<endl;
        }

        unordered_map<string,int> map;
        for(auto i : ans){
            map[i]++;
        }
        for(auto i: banned){
            map[i]=0;
        }
        cout<<map["hit"] << map["bob"] <<map["ball"];
        string res="";
        int count=0;
        for(auto i: map)
            if(i.second > count && i.first!="") res= i.first, count = i.second;
        return res;
    }
};