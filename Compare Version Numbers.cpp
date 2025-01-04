class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss(version1);
        string str="";
        vector<int> v1;
        while(getline(ss,str,'.')){
            v1.push_back(stoi(str));
        }
        stringstream ss2(version2);
        string str2="";
        vector<int> v2;
        while(getline(ss2,str2,'.')){
            v2.push_back(stoi(str2));
        }
        for(auto i : v1)cout<<i;
        cout<<endl;
        for(auto i : v2)cout<<i;
        for(int i=0;i<max(v1.size(),v2.size());i++){
            int x=i<v1.size()? v1[i] : 0;
            int y=i<v2.size()? v2[i] :0;
            if(x>y)return 1;
            if(x<y) return -1;
        }
        return 0;

       
        // return 0;
        
    }
};