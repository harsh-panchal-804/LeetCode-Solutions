class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss(s1);
        string str="";
        unordered_map<string,int> map;
        while(getline(ss,str,' ')){
            map[str]++;
        }
        str="";
        unordered_map<string,int> mapt;
        stringstream sr(s2);
        while(getline(sr,str,' ')){
            mapt[str]++;
        }
        vector<string>ans;
        for(auto i: map){
            cout<<i.first<<endl;
            mapt[i.first]+=map[i.first];
        }
        cout<<"_____"<<endl;
        for(auto i: mapt){
            cout<<i.first<<endl;
            if(i.second==1) ans.push_back(i.first);
        }
        return ans;
        
    }
};